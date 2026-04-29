#include "adb_handshake.h"
#include <string.h>
#include <sys/socket.h>

void adb_send_banner(int fd) {
    const char *banner = "CNXN0000000c00000000host::\0";
    send(fd, banner, strlen(banner), 0);
}
