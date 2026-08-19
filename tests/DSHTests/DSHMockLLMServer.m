//
//  DSHMockLLMServer.m
//  DSHTests
//

#import "DSHMockLLMServer.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

@interface DSHMockLLMServer ()
@property (nonatomic, readwrite) uint16_t port;
@property (nonatomic) int listenFD;
@property (nonatomic) dispatch_source_t source;
@property (nonatomic) dispatch_queue_t queue;
@property (atomic, readwrite, copy) NSArray<NSString *> *offeredToolsPerRequest;
@property (atomic, readwrite) NSUInteger requestCount;
@end

@implementation DSHMockLLMServer

- (instancetype)init {
    if (self = [super init]) {
        _reply = @"MOCK-REPLY: hello from the in-app mock model";
        _offeredToolsPerRequest = @[];
        _queue = dispatch_queue_create("dsh.test.mockllm", DISPATCH_QUEUE_CONCURRENT);
        int fd = socket(AF_INET, SOCK_STREAM, 0);
        if (fd < 0)
            return nil;
        int one = 1;
        setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one));
        struct sockaddr_in addr = { .sin_len = sizeof(addr), .sin_family = AF_INET, .sin_port = 0, .sin_addr.s_addr = htonl(INADDR_LOOPBACK) };
        if (bind(fd, (struct sockaddr *) &addr, sizeof(addr)) < 0 || listen(fd, 8) < 0) {
            close(fd);
            return nil;
        }
        socklen_t len = sizeof(addr);
        getsockname(fd, (struct sockaddr *) &addr, &len);
        _port = ntohs(addr.sin_port);
        _listenFD = fd;
        __weak typeof(self) weakSelf = self;
        _source = dispatch_source_create(DISPATCH_SOURCE_TYPE_READ, fd, 0, _queue);
        dispatch_source_set_event_handler(_source, ^{ [weakSelf acceptOne]; });
        dispatch_resume(_source);
    }
    return self;
}

- (NSString *)baseURLString {
    return [NSString stringWithFormat:@"http://127.0.0.1:%u", self.port];
}

- (void)stop {
    if (self.source) {
        dispatch_source_cancel(self.source);
        self.source = nil;
    }
    if (self.listenFD >= 0) {
        close(self.listenFD);
        self.listenFD = -1;
    }
}

- (void)dealloc {
    [self stop];
}

- (void)acceptOne {
    int client = accept(self.listenFD, NULL, NULL);
    if (client < 0)
        return;
    dispatch_async(self.queue, ^{ [self serve:client]; });
}

- (void)serve:(int)fd {
    // Read head + body.
    NSMutableData *buffer = [NSMutableData data];
    NSData *terminator = [@"\r\n\r\n" dataUsingEncoding:NSUTF8StringEncoding];
    NSRange split = NSMakeRange(NSNotFound, 0);
    char chunk[8192];
    while (split.location == NSNotFound) {
        ssize_t n = recv(fd, chunk, sizeof(chunk), 0);
        if (n <= 0) { close(fd); return; }
        [buffer appendBytes:chunk length:n];
        split = [buffer rangeOfData:terminator options:0 range:NSMakeRange(0, buffer.length)];
    }
    NSString *head = [[NSString alloc] initWithData:[buffer subdataWithRange:NSMakeRange(0, split.location)] encoding:NSUTF8StringEncoding];
    NSUInteger contentLength = 0;
    for (NSString *line in [head componentsSeparatedByString:@"\r\n"]) {
        if ([line.lowercaseString hasPrefix:@"content-length:"])
            contentLength = (NSUInteger) [[line substringFromIndex:15] integerValue];
    }
    NSUInteger bodyStart = split.location + split.length;
    while (buffer.length - bodyStart < contentLength) {
        ssize_t n = recv(fd, chunk, sizeof(chunk), 0);
        if (n <= 0) { close(fd); return; }
        [buffer appendBytes:chunk length:n];
    }
    NSDictionary *payload = @{};
    if (contentLength) {
        id parsed = [NSJSONSerialization JSONObjectWithData:[buffer subdataWithRange:NSMakeRange(bodyStart, contentLength)] options:0 error:nil];
        if ([parsed isKindOfClass:NSDictionary.class])
            payload = parsed;
    }
    self.requestCount++;

    // Record which tools the harness offered.
    NSMutableArray *names = [NSMutableArray array];
    for (NSDictionary *tool in payload[@"tools"]) {
        NSString *name = tool[@"function"][@"name"] ?: tool[@"name"];
        if (name) [names addObject:name];
    }
    self.offeredToolsPerRequest = [self.offeredToolsPerRequest arrayByAddingObject:[names componentsJoinedByString:@","]];

    NSString *tool = self.requestTool;
    BOOL offersTool = tool && [names containsObject:tool];
    NSDictionary *toolMessage = nil;
    for (NSDictionary *message in payload[@"messages"]) {
        if ([message[@"role"] isEqualToString:@"tool"])
            toolMessage = message;
    }

    if (offersTool && toolMessage == nil) {
        [self sendToolCall:tool to:fd];
    } else if (tool && toolMessage != nil) {
        id content = toolMessage[@"content"];
        NSString *observed = [content isKindOfClass:NSString.class] ? content
                           : [[NSString alloc] initWithData:[NSJSONSerialization dataWithJSONObject:content ?: @{} options:0 error:nil] encoding:NSUTF8StringEncoding];
        [self sendText:[NSString stringWithFormat:@"TOOL-RESULT-BEGIN %@ TOOL-RESULT-END", observed ?: @""] to:fd];
    } else {
        [self sendText:self.reply to:fd];
    }
    close(fd);
}

#pragma mark Streaming helpers

- (NSString *)chunkWithDelta:(NSDictionary *)delta finish:(nullable NSString *)finish {
    NSDictionary *choice = @{ @"index": @0, @"delta": delta, @"finish_reason": finish ?: NSNull.null };
    NSDictionary *body = @{ @"id": @"chatcmpl-mock", @"object": @"chat.completion.chunk",
                            @"created": @1700000000, @"model": @"deepseek-chat", @"choices": @[choice] };
    NSString *json = [[NSString alloc] initWithData:[NSJSONSerialization dataWithJSONObject:body options:0 error:nil] encoding:NSUTF8StringEncoding];
    return [NSString stringWithFormat:@"data: %@\n\n", json];
}

- (void)writeSSEHead:(int)fd {
    NSString *head = @"HTTP/1.1 200 OK\r\nContent-Type: text/event-stream\r\nCache-Control: no-cache\r\nConnection: close\r\n\r\n";
    [self writeString:head to:fd];
}

- (void)writeString:(NSString *)string to:(int)fd {
    NSData *data = [string dataUsingEncoding:NSUTF8StringEncoding];
    const uint8_t *bytes = data.bytes;
    NSUInteger sent = 0;
    while (sent < data.length) {
        ssize_t n = send(fd, bytes + sent, data.length - sent, 0);
        if (n <= 0) return;
        sent += n;
    }
}

- (void)sendToolCall:(NSString *)tool to:(int)fd {
    [self writeSSEHead:fd];
    NSDictionary *call = @{ @"index": @0, @"id": @"call_mock_1", @"type": @"function",
                            @"function": @{ @"name": tool, @"arguments": @"{}" } };
    [self writeString:[self chunkWithDelta:@{ @"role": @"assistant", @"content": @"", @"tool_calls": @[call] } finish:nil] to:fd];
    [self writeString:[self chunkWithDelta:@{} finish:@"tool_calls"] to:fd];
    [self writeString:@"data: [DONE]\n\n" to:fd];
}

- (void)sendText:(NSString *)text to:(int)fd {
    [self writeSSEHead:fd];
    [self writeString:[self chunkWithDelta:@{ @"role": @"assistant", @"content": @"" } finish:nil] to:fd];
    for (NSString *word in [text componentsSeparatedByString:@" "])
        [self writeString:[self chunkWithDelta:@{ @"content": [word stringByAppendingString:@" "] } finish:nil] to:fd];
    [self writeString:[self chunkWithDelta:@{} finish:@"stop"] to:fd];
    [self writeString:@"data: [DONE]\n\n" to:fd];
}

@end
