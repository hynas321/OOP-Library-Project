#include "RentStorage.h"

std::vector<std::shared_ptr<Rent>> RentStorage::rents;

RentStorage::RentStorage() = default;
RentStorage::~RentStorage() = default;

bool RentStorage::addRent(const std::shared_ptr<Rent>& rent) {
    int id = rents.size() + 1;
    rent->setId(id);

    try {
        rent->getBook()->setStatus(true);
        rents.push_back(rent);
    }
    catch (...) {
        return false;
    }

    return true;
}

bool RentStorage::removeRent(const std::shared_ptr<Rent>& rent) {
    try {
        for (int i = 0; i < rents.size(); i++) {
            if (rent == rents[i]) {
                rent->getBook()->setStatus(false);
                rents.erase(rents.cbegin() + i);
                return true;
            }
        }
    }
    catch (...) {
        return false;
    }

    return false;
}

std::shared_ptr<Rent> RentStorage::findRent(int id) {
    for (auto rent : rents) {
        if (id == rent->getId()) {
            return rent;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Rent>> RentStorage::getRents() {
    return rents;
}


int RentStorage::getRentsCount() {
    return rents.size();
}

