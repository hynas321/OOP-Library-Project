#include "RentManager.h"

RentManager::RentManager() = default;
RentManager::~RentManager() = default;

bool RentManager::rentOnAccount(const std::shared_ptr<Rent>& rent, const std::shared_ptr<Account>& account) {
    return rent != nullptr && account != nullptr && rent->getAccount() == account;
}

bool RentManager::noRentsOnAccount(const std::shared_ptr<Account>& account) {
    for (auto rent : rentStorage->getRents()) {
        if (account == rent->getAccount()) {
            return false;
        }
    }
    return true;
}

int RentManager::rentCountOnAccount(const std::shared_ptr<Account>& account) {
    int num;
    for (auto rent : rentStorage->getRents()) {
        if (account == rent->getAccount()) {
            num++;
        }
    }
    return num;
}

bool RentManager::rentValidDate(const std::shared_ptr<Rent>& rent) {
    return rent->getEndDate() >= boost::gregorian::day_clock::local_day();
}




