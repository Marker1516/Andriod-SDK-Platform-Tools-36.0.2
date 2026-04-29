#include "shell_service.h"
#include <sys/socket.h>
#include <unistd.h>

void shell_service_loop(int fd) {
    char buf[1024];

    while (1) {
        ssize_t r = recv(fd, buf, sizeof(buf), 0);
        if (r <= 0) break;

        // Echo back (placeholder for real shell)
        send(fd, buf, r, 0);
    }
}
