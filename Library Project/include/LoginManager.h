#ifndef LIBRARY_PROJECT_LOGINMANAGER_H
#define LIBRARY_PROJECT_LOGINMANAGER_H
#include <memory>
#include <string>
#include "AccountStorage.h"

class LoginManager {
private:
    static std::string adminUsername;
    std::shared_ptr<Account> loggedAccount {nullptr};
    AccountStorage accountStorage;

public:
    LoginManager();
    ~LoginManager();

    bool LogIn(std::shared_ptr<Account> account);
    bool LogOut();
    bool accountExists(const std::string& username);
    std::shared_ptr<Account> checkCredentials(const std::string& username, const std::string& password);
    bool loggedAccountIsAdmin();
    std::shared_ptr<Account> getLoggedAccount();
    void setLoggedAccount(std::shared_ptr<Account> account);
    std::string getAdminUsername();
    void setAdminUsername(std::string adminUsername);
};
#endif //LIBRARY_PROJECT_LOGINMANAGER_H
