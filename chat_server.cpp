#include "chat_server.h"
#

ChatServer::ChatServer(/* args */)
{
    Init(); // 通讯服务器初始化
    user_list = new Users();
}

ChatServer::~ChatServer()
{
}

/* 初始化服务器到监听状态 */
void ChatServer::Init()
{
    address.sin_family = AF_INET;                     // AF为地址族（Address Family），也就是IP地址类型，常用的有 AF_INET和AF_INET6。AF_INET 表示 IPv4 地址，例如 127.0.0.1；AF_INET6 表示 IPv6 地址，例如 1030::C9B4:FF12:48AA:1A2B。
    address.sin_port = htons(62466);                  // 表示将16位的主机字节顺序转化为16位的网络字节顺序（ip地址是32位的，端口号是16位的 ）
    address.sin_addr.s_addr = inet_addr("127.0.0.1"); // 此步骤到目标是将IP地址从点数格式转换成无符号长整型

    sockfd = socket(AF_INET, SOCK_STREAM, 0); // 创建套接字

    if (sockfd == -1)
        return;
    int ret = bind(sockfd, (struct sockaddr *)&address, sizeof(address));
    if (ret == -1)
        close(sockfd); // 关闭socket句柄
        sockfd = -1;   // 重设socket句柄为初始监听状态：-1
        return;        // 结束
    ret = listen(sockfd, 1024);
    if (ret == -1)
        close(sockfd);
        sockfd = -1;
        return;
}

bool ChatServer::AcceptUserClient()
{
    if (sockfd == -1)
        return false;
    int client_sockfd = accept(sockfd, NULL, NULL);
    if (client_sockfd == -1)
        return false;
    User user;
    
    // 接受客户端
    ssize_t size = recv(client_sockfd, &user, sizeof(user), 0);
    return true;
}