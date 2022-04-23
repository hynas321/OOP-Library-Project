#include <boost/test/unit_test.hpp>
#include "AccountManager.h"

BOOST_AUTO_TEST_SUITE(AccountManagerTestSuite)

    BOOST_AUTO_TEST_CASE(Test1)
    {
        auto accountManager = std::make_shared<AccountManager>();

        std::string username1 = "12345";
        std::string username2 = "123456789012345";
        std::string username3 = "1234";
        std::string username4 = "1234567890123456";

        BOOST_TEST(accountManager->correctUsername(username1) == true);
        BOOST_TEST(accountManager->correctUsername(username2) == true);
        BOOST_TEST(accountManager->correctUsername(username3) == false);
        BOOST_TEST(accountManager->correctUsername(username4) == false);
    }

    BOOST_AUTO_TEST_CASE(Test2)
    {
        auto accountManager = std::make_shared<AccountManager>();

        std::string password1 = "12345";
        std::string password2 = "12345678901234567890";
        std::string password3 = "1234";
        std::string password4 = "123456789012345678901";

        BOOST_TEST(accountManager->correctPassword(password1) == true);
        BOOST_TEST(accountManager->correctPassword(password2) == true);
        BOOST_TEST(accountManager->correctPassword(password3) == false);
        BOOST_TEST(accountManager->correctUsername(password4) == false);
    }

    BOOST_AUTO_TEST_CASE(Test3)
    {
        auto accountManager = std::make_shared<AccountManager>();

        std::string fullName1 = "12345";
        std::string fullName2 = "1234567890123456789012345";
        std::string fullName3 = "1234";
        std::string fullName4 = "12345678901234567890123456";

        BOOST_TEST(accountManager->correctFullName(fullName1) == true);
        BOOST_TEST(accountManager->correctFullName(fullName2) == true);
        BOOST_TEST(accountManager->correctFullName(fullName3) == false);
        BOOST_TEST(accountManager->correctFullName(fullName4) == false);
    }
BOOST_AUTO_TEST_SUITE_END()
