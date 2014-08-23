#include "../src/socket.h"

int main(void)
{
    int server_fd;
    char buf[128];
    struct sockaddr client;
    socklen_t client_len = sizeof(struct sockaddr);

    server_fd = udp_server("127.0.0.1", "21114");
    udp_recvfrom(server_fd, buf, sizeof(buf), &client, &client_len);
    strcat(buf, " from server");
    udp_sendto(server_fd, buf, sizeof(buf), &client, client_len);
    udp_close(server_fd);
}
