#include <LoginManager.h>

std::string LoginManager::adminUsername;

LoginManager::LoginManager() = default;
LoginManager::~LoginManager() = default;

bool LoginManager::LogIn(std::shared_ptr<Account> account) {
    if (account != nullptr && loggedAccount == nullptr) {
        loggedAccount = account;
        return true;
    }
    else {
        return false;
    }
}

bool LoginManager::LogOut() {
    if (loggedAccount != nullptr) {
        loggedAccount = nullptr;
        return true;
    }
    else {
        return false;
    }

}

bool LoginManager::accountExists(const std::string &username) {
    for (const auto& account : accountStorage.getAccounts()) {
        if (account->getUsername() == username) {
            return true;
        }
    }
    return false;
}

std::shared_ptr<Account> LoginManager::checkCredentials(const std::string& username, const std::string& password) {
    for (auto& account : accountStorage.getAccounts()) {
        if (username == account->getUsername() && password == account->getPassword()) {
            return account;
        }
    }
    return nullptr;
}

bool LoginManager::loggedAccountIsAdmin() {
    return loggedAccount->getUsername() == adminUsername;
}

std::shared_ptr<Account> LoginManager::getLoggedAccount() {
    return loggedAccount;
}

void LoginManager::setLoggedAccount(std::shared_ptr<Account> account) {
    loggedAccount = account;
}

std::string LoginManager::getAdminUsername() {
    return adminUsername;
}

void LoginManager::setAdminUsername(std::string adminUsername) {
    this->adminUsername = adminUsername;
}




