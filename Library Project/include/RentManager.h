#ifndef LIBRARY_RENTMANAGER_H
#define LIBRARY_RENTMANAGER_H
#include "RentStorage.h"

class Account;

class RentManager {
private:
    std::shared_ptr<RentStorage> rentStorage;

public:
    RentManager();
    ~RentManager();

    bool rentOnAccount(const std::shared_ptr<Rent>& rent, const std::shared_ptr<Account>& account);
    bool noRentsOnAccount(const std::shared_ptr<Account>& account);
    int rentCountOnAccount(const std::shared_ptr<Account>& account);
    bool rentValidDate(const std::shared_ptr<Rent>& rent);
};


#endif //LIBRARY_RENTMANAGER_H
