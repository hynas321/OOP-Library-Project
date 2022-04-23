#ifndef LIBRARY_PROJECT_ADMIN_H
#define LIBRARY_PROJECT_ADMIN_H
#include <memory>
#include "Account.h"

class Admin : public Account {
private:
    Admin(std::string name, std::string username, std::string password);
    static std::shared_ptr<Admin> obj;
    std::string role {"Admin"};

public:
    static std::shared_ptr<Admin> instance(std::string name, std::string username, std::string password);
    std::string getRole() override;
    std::string printInfo() override;
};


#endif //LIBRARY_PROJECT_ADMIN_H
