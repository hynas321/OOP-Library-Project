#include "AccountManager.h"

AccountManager::AccountManager() = default;
AccountManager::~AccountManager() = default;

bool AccountManager::correctUsername(std::string username) {
    return username.size() >= std::get<0>(usernameLength) && username.size() <= std::get<1>(usernameLength);
}

bool AccountManager::correctPassword(std::string password) {
    return password.size() >= std::get<0>(passwordLength) && password.size() <= std::get<1>(passwordLength);
}

bool AccountManager::correctFullName(std::string fullname) {
    return fullname.size() >= std::get<0>(fullnameLength) && fullname.size() <= std::get<1>(fullnameLength);
}
