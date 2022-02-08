#include "users.h"

Users::Users() : head(NULL), users_length(0)
{
    Node *node = (Node *)new (Node);
    node->next = NULL;
    head = node;
}

Users::~Users() {}

/* 往用户列表中添加新用户 */
void Users::push(User user)
{
    Node *node = (Node *)new (Node);
    node->user = user;
    node->next = this->head->next;
    this->head->next = node;
    ++users_length;
}

/* 从用户列表中删除用户（以sock句柄作为标识删除） */
void Users::pop(int sockfd)
{
    Node *cur_node = head;
    while (cur_node->next != NULL)
    {
        /* code */
    }
}

/* 展示用户列表 */
void Users::show_users()
{
    cout << "Show Users List:" << endl;
    Node *cur_node = head->next;
    while (cur_node != NULL)
    {
        cout << "User Id: " << cur_node->user.id << " User Name: " << cur_node->user.name << " User Sockfd: " << cur_node->user.sockfd << endl;
        cur_node = cur_node->next;
    }
}

Node *&Users::get_users_head()
{
    return this->head;
}