//
//  DSHTestHTTPServer.m
//  DSHTests
//

#import "DSHTestHTTPServer.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

@interface DSHTestHTTPServer ()
@property (nonatomic) int listenFD;
@property (nonatomic) dispatch_source_t source;
@property (nonatomic) dispatch_queue_t queue;
@property (nonatomic, readwrite) uint16_t port;
@property (atomic, readwrite) NSUInteger requestCount;
@end

@implementation DSHTestHTTPServer

- (instancetype)initWithPort:(uint16_t)port {
    if (self = [super init]) {
        _statusCode = 200;
        _queue = dispatch_queue_create("dsh.test.http", DISPATCH_QUEUE_CONCURRENT);
        int fd = socket(AF_INET, SOCK_STREAM, 0);
        if (fd < 0)
            return nil;
        int one = 1;
        setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one));
        struct sockaddr_in addr = { .sin_len = sizeof(addr), .sin_family = AF_INET, .sin_port = htons(port), .sin_addr.s_addr = htonl(INADDR_LOOPBACK) };
        if (bind(fd, (struct sockaddr *) &addr, sizeof(addr)) < 0 || listen(fd, 16) < 0) {
            close(fd);
            return nil;
        }
        socklen_t len = sizeof(addr);
        getsockname(fd, (struct sockaddr *) &addr, &len);
        _port = ntohs(addr.sin_port);
        _listenFD = fd;
        _source = dispatch_source_create(DISPATCH_SOURCE_TYPE_READ, fd, 0, _queue);
        __weak typeof(self) weakSelf = self;
        dispatch_source_set_event_handler(_source, ^{ [weakSelf acceptOne]; });
        dispatch_resume(_source);
    }
    return self;
}

- (NSURL *)baseURL {
    return [NSURL URLWithString:[NSString stringWithFormat:@"http://127.0.0.1:%u/", self.port]];
}

- (void)acceptOne {
    int client = accept(self.listenFD, NULL, NULL);
    if (client < 0)
        return;
    self.requestCount++;
    NSInteger status = self.statusCode;
    dispatch_async(self.queue, ^{
        char buf[4096];
        // Read the request head (best effort), then answer.
        recv(client, buf, sizeof(buf), 0);
        NSString *body = @"ok";
        NSString *head = [NSString stringWithFormat:@"HTTP/1.1 %ld %@\r\nContent-Type: text/plain\r\nContent-Length: %lu\r\nConnection: close\r\n\r\n%@",
                          (long) status, status == 200 ? @"OK" : @"Error", (unsigned long) body.length, body];
        const char *bytes = head.UTF8String;
        send(client, bytes, strlen(bytes), 0);
        close(client);
    });
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

@end
