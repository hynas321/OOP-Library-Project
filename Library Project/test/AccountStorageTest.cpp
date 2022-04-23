#include <boost/test/unit_test.hpp>
#include "AccountStorage.h"

BOOST_AUTO_TEST_SUITE(AccountStorageTestSuite)

    BOOST_AUTO_TEST_CASE(Test1)
    {
        auto accountStorage = std::make_shared<AccountStorage>();
        auto account1 = std::make_shared<Member>("account","account","password");
        auto account2 = std::make_shared<Member>("account2","account2","password");

        BOOST_TEST(accountStorage->addAccount(account1) == true);
        BOOST_TEST(accountStorage->addAccount(account2) == true);

        BOOST_TEST(accountStorage->getAccountsCount() == 2);

        BOOST_TEST(accountStorage->removeAccount(account1) == true);
        BOOST_TEST(accountStorage->removeAccount(account2) == true);

        BOOST_TEST(accountStorage->getAccountsCount() == 0);
    }

    BOOST_AUTO_TEST_CASE(Test2)
    {
        auto accountStorage = std::make_shared<AccountStorage>();
        auto account1 = std::make_shared<Member>("account","account","password");
        auto account2 = std::make_shared<Member>("account2","account2","password");

        BOOST_TEST(accountStorage->addAccount(account1) == true);
        BOOST_TEST(accountStorage->addAccount(account2) == true);

        BOOST_TEST(accountStorage->removeAccount(account1) == true);
        BOOST_TEST(accountStorage->removeAccount(account2) == true);

        BOOST_TEST(accountStorage->removeAccount(account1) == false);
        BOOST_TEST(accountStorage->removeAccount(account2) == false);
    }


BOOST_AUTO_TEST_SUITE_END()
