#include "AccountStorage.h"

std::vector<std::shared_ptr<Account>> AccountStorage::accounts;

AccountStorage::AccountStorage() = default;
AccountStorage::~AccountStorage() = default;


bool AccountStorage::addAccount(const std::shared_ptr<Account>& account) {
    try {
        accounts.push_back(account);
    }
    catch (std::exception& ex) {
        return false;
    }

    return true;
}

bool AccountStorage::removeAccount(const std::shared_ptr<Account>& account) {
    try {
        for (int i = 0; i < accounts.size(); i++) {
            if (account == accounts[i] && rentManager.noRentsOnAccount(account)) {
                accounts.erase(accounts.cbegin() + i);
                return true;
            }
            else if (account == accounts[i] && !rentManager.noRentsOnAccount(account)) {
                return false;
            }
        }
    }
    catch (...) {
        return false;
    }
    return false;
}

std::shared_ptr<Account> AccountStorage::findAccount(std::string username) {
    for (auto account : accounts) {
        if (username == account->getUsername()) {
            return account;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Account>> AccountStorage::getAccounts() {
    return accounts;
}

int AccountStorage::getAccountsCount() {
    return accounts.size();
}
