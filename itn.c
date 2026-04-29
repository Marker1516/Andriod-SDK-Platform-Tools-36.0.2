#include "transport.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int transport_listen(int port) {
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr.s_addr = INADDR_ANY
    };

    bind(fd, (struct sockaddr*)&addr, sizeof(addr));
    listen(fd, 4);
    return fd;
}

int transport_accept(int server_fd) {
    return accept(server_fd, NULL, NULL);
}
