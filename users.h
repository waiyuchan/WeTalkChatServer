#ifdef USERS_H_
#define USERS_H_

class User
{
private:
public:
    std::string id;
    std::string name;
    std::string sock_info;
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
};

Users::Users(/* args */)
{
}

Users::~Users()
{
}

#endif