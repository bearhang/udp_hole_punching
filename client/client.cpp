#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <error.h>

#include "message.pb.h"

using namespace std;
using namespace message;

#define REMOTE_IP "10.123.25.11"
#define REMOTE_PORT 9204

#define REGISTER "register"

void handle_puching(char *buf)
{
    StartReq req;
    req.ParseFromString(buf);

    cout << req.local_ip << endl;
    cout << req.local_port << endl;
    cout << req.remote_ip << endl;
    cout << req.remote_port << endl;

    return;
}

int main()
{
    int fd = 0;
    int err = 0;
    char buf[1024] = {0};
    struct sockaddr_in remote_addr = {0};

    //fd = socket(AF_INET, SOCK_DGRAM | SOCK_NONBLOCK | SOCK_CLOEXEC, 0);
    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd < 0)
    {
        printf("socket %d %s\n", errno, strerror(errno));
        return -1;
    }

    remote_addr.sin_family = AF_INET;
    remote_addr.sin_addr.s_addr = inet_addr(LOCAL_IP);
    remote_addr.sin_port = htons(LOCAL_PORT);
    err = sendto(fd, REGISTER, sizeof(REGISTER), 0, (struct sockaddr *)&remote_addr, (socklen_t)sizeof(remote_addr));
    if (err < 0)
    {
        printf("connect %d %s\n", errno, strerror(errno));
        return -1;
    }

    err = recv(fd, buf, 1024, 0);
    if (err < 0)
    {
        printf("recv %d %s\n", errno, strerror(errno));
        return -1;
    }

    handle_puching(buf);
    return 0;
}