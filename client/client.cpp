#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <error.h>
#include <pthread.h>

#include "message.pb.h"

using namespace std;
using namespace message;

// #define REMOTE_IP "10.123.25.11"
#define REMOTE_IP "10.104.53.46"
#define REMOTE_PORT 9204

#define REGISTER "register"
#define SENDDATA "data"
void * send_routine(void * data)
{
    int fd = 0;
    int err = 0;
    struct sockaddr_in remote_addr = {0};
    StartReq *req = (StartReq *)data;

    fd = req->fd();

    remote_addr.sin_family = AF_INET;
    remote_addr.sin_addr.s_addr = req->remote_ip();
    remote_addr.sin_port = req->remote_port();

    while (1)
    {
        err = sendto(fd, SENDDATA, sizeof(SENDDATA), 0, (struct sockaddr *)&remote_addr, (socklen_t)sizeof(remote_addr));
        if (err < 0)
        {
            printf("sendto %d %s\n", errno, strerror(errno));
            return NULL;
        }
        sleep(1);
    }

    return NULL;
}

void * recv_routine(void * data)
{
    int fd = 0;
    int err = 0;
    StartReq *req = (StartReq *)data;

    fd = req->fd();

    while (1)
    {
        struct sockaddr_in remote_addr = {0};
        socklen_t socklen = sizeof(remote_addr);
        char buf[1024] = {0};

        err = recvfrom(fd, buf, 1024, 0, (struct sockaddr *)&remote_addr, &socklen);
        if (err < 0)
        {
            printf("recvfrom %d %s\n", errno, strerror(errno));
            return NULL;
        }

        printf("recv msg:%s from:%s:%d\n", buf, inet_ntoa(remote_addr.sin_addr), ntohs(remote_addr.sin_port));        
    }

    return NULL;
}

void handle_puching(int fd, char *buf)
{
    int err = 0;
    pthread_t pid = 0;
    StartReq req;
    req.ParseFromString(buf);

    cout << req.local_ip() << endl;
    cout << req.local_port() << endl;
    cout << req.remote_ip() << endl;
    cout << req.remote_port() << endl;

    req.set_fd(fd);

    err = pthread_create(&pid, NULL, send_routine, &req);
    if (err < 0)
    {
        printf("pthread_create %d %s\n", err, strerror(err));
        return;
    }

    err = pthread_create(&pid, NULL, recv_routine, &req);
    if (err < 0)
    {
        printf("pthread_create %d %s\n", err, strerror(err));
        return;
    }

    while (1)
    {
        sleep(1);
    }

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
    remote_addr.sin_addr.s_addr = inet_addr(REMOTE_IP);
    remote_addr.sin_port = htons(REMOTE_PORT);
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

    handle_puching(fd, buf);
    return 0;
}
