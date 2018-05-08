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

int main()
{
    int fd = 0;
    int err = 0;
    struct sockaddr_in local_addr = {0};

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

    StartReq req;
    req.set_local_ip("127.0.0.1");
    req.set_remote_ip("127.0.0.2");
    req.set_local_port(10);
    req.set_remote_port(20);

    string output;
    req.SerializeToString(&output);

    StartReq rsp;
    rsp.ParseFromString(output);
    cout << rsp.local_ip() << endl;
    // while (1)
    // {
    //     sleep(1);
    // }

    return 0;
}
