#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <netinet/in.h>

#include "adb_handshake.h"
#include "transport.h"
#include "shell_service.h"

static int server_fd;

static void sig_handler(int sig) {
    printf("adbd-mini: signal %d, exiting\n", sig);
    close(server_fd);
    _exit(0);
}

int main() {
    signal(SIGINT, sig_handler);
    signal(SIGTERM, sig_handler);

    server_fd = transport_listen(5555);
    printf("adbd-mini: listening on port 5555\n");

    while (1) {
        int client = transport_accept(server_fd);
        printf("adbd-mini: client connected\n");

        adb_send_banner(client);
        shell_service_loop(client);

        close(client);
        printf("adbd-mini: client disconnected\n");
    }
}
