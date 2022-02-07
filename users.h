#ifndef USERS_H
#define USERS_H
#include <string>

using std::string;

class User
{
private:
public:
    string id;
    string name;
    int sockfd;
};

struct Node
{
    /* data */
    User user;
    Node *next;
};

class Users
{
private:
    /* data */
    Node *head;
    int users_length;

public:
    Users(/* args */);
    ~Users();

    void push(User user);
    void pop();
    int length();
    int select_sockfd();
    void show_users();
    Node *&get_users_head();
};

#endif  // USERS_H