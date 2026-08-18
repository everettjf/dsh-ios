//
//  DSHPortAllocator.m
//  DSH
//

#import "DSHPortAllocator.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

@implementation DSHPortAllocator

+ (BOOL)isLoopbackPortFree:(uint16_t)port {
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0)
        return NO;
    // SO_REUSEADDR mirrors what node/libuv does inside the guest: a port that
    // only has TIME_WAIT leftovers (e.g. right after a restart) is usable,
    // while an active listener still makes bind() fail.
    int one = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one));
    struct sockaddr_in addr = {
        .sin_len = sizeof(addr),
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr.s_addr = htonl(INADDR_LOOPBACK),
    };
    BOOL free = bind(fd, (struct sockaddr *) &addr, sizeof(addr)) == 0;
    close(fd);
    return free;
}

+ (uint16_t)freeLoopbackPortStartingAt:(uint16_t)preferred span:(uint16_t)span {
    for (uint32_t port = preferred; port < (uint32_t) preferred + span && port <= 65535; port++) {
        if ([self isLoopbackPortFree:(uint16_t) port])
            return (uint16_t) port;
    }
    return 0;
}

@end
