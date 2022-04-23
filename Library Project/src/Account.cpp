#include "Account.h"
#include <string>
#include <utility>

Account::Account(std::string name, std::string username, std::string password)
: name(std::move(name)), username(std::move(username)), password(std::move(password)) {}
Account::~Account() = default;

std::string Account::getName() {
    return name;
}

std::string Account::getUsername() {
    return username;
}

std::string Account::getPassword() {
    return password;
}

std::string Account::getRole() {
    return role;
}

std::string Account::printInfo() {
    std::string str = "Full name: " + getName() + "\n" + "Username: " + getUsername() + "\n";
    return str;
}



