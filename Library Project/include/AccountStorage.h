#ifndef LIBRARY_ACCOUNTSTORAGE_H
#define LIBRARY_ACCOUNTSTORAGE_H
#include <memory>
#include <vector>
#include "Admin.h"
#include "Account.h"
#include "Member.h"
#include "RentManager.h"

class AccountStorage {
private:
    static std::vector<std::shared_ptr<Account>> accounts;
    RentManager rentManager;
public:
    AccountStorage();
    ~AccountStorage();

    bool addAccount(const std::shared_ptr<Account>& account);
    bool removeAccount(const std::shared_ptr<Account>& account);
    std::shared_ptr<Account> findAccount(std::string username);
    std::vector<std::shared_ptr<Account>> getAccounts();
    int getAccountsCount();
};


#endif //LIBRARY_ACCOUNTSTORAGE_H
