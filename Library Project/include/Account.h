#ifndef LIBRARY_ACCOUNT_H
#define LIBRARY_ACCOUNT_H
#include <string>

class Account {
private:
    std::string name;
    std::string username;
    std::string password;
    std::string role;
public:
    Account(std::string name, std::string username, std::string password);
    ~Account();

    std::string getName();
    std::string getUsername();
    std::string getPassword();
    virtual std::string getRole();
    virtual std::string printInfo();
};


#endif //LIBRARY_ACCOUNT_H
