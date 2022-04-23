#ifndef LIBRARY_ACCOUNTMANAGER_H
#define LIBRARY_ACCOUNTMANAGER_H
#include <iostream>
#include <memory>
#include <string>

class AccountManager {
private:
    std::tuple<int, int> usernameLength = std::make_tuple(5,15);
    std::tuple<int, int> passwordLength = std::make_tuple(5,20);
    std::tuple<int, int> fullnameLength = std::make_tuple(5,25);

public:
    AccountManager();
    ~AccountManager();

    bool correctUsername(std::string username);
    bool correctPassword(std::string password);
    bool correctFullName(std::string fullname);
};


#endif //LIBRARY_ACCOUNTMANAGER_H
