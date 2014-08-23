#include "../src/socket.h"

int main(void)
{
    int client_fd;
    char buf[128] = "hello world";

    client_fd = udp_client("127.0.0.1", "21114");
    udp_send(client_fd, buf, sizeof(buf));
    udp_recv(client_fd, buf, sizeof(buf));
    printf("%s\n", buf);
    udp_close(client_fd);
}
