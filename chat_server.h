#ifndef CHAT_SERVER_H
#define CHAT_SERVER_H
#include <arpa/inet.h>
#include "users.h"
#include <unistd.h>
#include <iostream>

using std::cout;
using std::endl;
using std::to_string;

class ChatServer
{
private:
    /* data */
    struct sockaddr_in address; // 用于存储用户的地址信息
    /*
    // sockaddr_in数据类型的结构体
    struct sockaddr_in {
        __uint8_t       sin_len;
        sa_family_t     sin_family;     // 地址族（Address Family）
        in_port_t       sin_port;       // 16位的 TCP/UDP 端口号
        struct  in_addr sin_addr;       // 32位 IP位
        char            sin_zero[8];    // 不使用
    };
    */
    int sockfd; // sockfd 就代表本次socket连接的文件句柄，后续的通信我们只需要像对待普通文件一样往这个文件句柄中读写数据即可实现socket通信的过程。
    Users *user_list;
    void Init();

public:
    ChatServer(/* args */);
    ~ChatServer();

    bool AcceptUserFromClient();
};

#endif // CHAT_SERVER_H