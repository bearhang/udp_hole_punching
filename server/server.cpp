#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <error.h>

#include "message.pb.h"

using namespace std;
using namespace message;

#define LOCAL_IP "0.0.0.0"
#define LOCAL_PORT 9204

struct peer_info {
    struct sockaddr_in addr;
};

struct peers_manager {
    peer_info peers[2];
    int peer_count;
};

void handle_require()
{

}

int main()
{
    int fd = 0;
    int err = 0;
    struct sockaddr_in local_addr = {0};
    struct peers_manager manager = {0};

    //fd = socket(AF_INET, SOCK_DGRAM | SOCK_NONBLOCK | SOCK_CLOEXEC, 0);
    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd < 0)
    {
        printf("socket %d %s\n", errno, strerror(errno));
        return -1;
    }

    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = inet_addr(LOCAL_IP);
    local_addr.sin_port = htons(LOCAL_PORT);
    err = bind(fd, (struct sockaddr *)&local_addr, (socklen_t)sizeof(local_addr));
    if (err < 0)
    {
        printf("bind %d %s\n", errno, strerror(errno));
        return -1;
    }

    while (manager.peer_count < 2)
    {
        struct sockaddr_in remote_addr = {0};
        socklen_t socklen = sizeof(remote_addr);
        char buf[1024] = {0};

        err = recvfrom(fd, buf, 1024, 0, (struct sockaddr *)&remote_addr, &socklen);
        if (err < 0)
        {
            printf("recvfrom %d %s\n", errno, strerror(errno));
            return -1;
        }

        printf("recv msg:%s from:%s:%d\n", buf, inet_ntoa(remote_addr.sin_addr), ntohs(remote_addr.sin_port));
        memcpy(&manager.peers[manager.peer_count].addr, &remote_addr, socklen);
        manager.peer_count++;
    }

    StartReq req;
    string output;
    req.set_local_ip(manager.peers[0].addr.sin_addr.s_addr);
    req.set_remote_ip(manager.peers[1].addr.sin_addr.s_addr);
    req.set_local_port(manager.peers[0].addr.sin_port);
    req.set_remote_port(manager.peers[1].addr.sin_port);
    req.SerializeToString(&output);
    
    err = sendto(fd, output.c_str(), output.size(), 0, (struct sockaddr *)&manager.peers[0].addr, (socklen_t)sizeof(manager.peers[0].addr));
    if (err < 0)
    {
        printf("connect %d %s\n", errno, strerror(errno));
        return -1;
    }

    req.set_local_ip(manager.peers[1].addr.sin_addr.s_addr);
    req.set_remote_ip(manager.peers[0].addr.sin_addr.s_addr);
    req.set_local_port(manager.peers[1].addr.sin_port);
    req.set_remote_port(manager.peers[0].addr.sin_port);
    req.SerializeToString(&output);
    
    err = sendto(fd, output.c_str(), output.size(), 0, (struct sockaddr *)&manager.peers[1].addr, (socklen_t)sizeof(manager.peers[1].addr));
    if (err < 0)
    {
        printf("connect %d %s\n", errno, strerror(errno));
        return -1;
    }

    return 0;
}
