#include "Admin.h"

std::shared_ptr<Admin> Admin::obj = nullptr;

Admin::Admin(std::string name, std::string username, std::string password) : Account(name, username, password) {}

std::shared_ptr<Admin> Admin::instance(std::string name, std::string username, std::string password) {
    if (!obj)
    {
        obj.reset(new Admin(name, username, password));
    }
    return obj;
}

std::string Admin::getRole() {
    return role;
}

std::string Admin::printInfo() {
    return Account::printInfo() + "Role: " + role + "\n";
}

