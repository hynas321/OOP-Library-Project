#include <boost/test/unit_test.hpp>
#include "LoginManager.h"

BOOST_AUTO_TEST_SUITE(LoginManagerTestSuite)

    BOOST_AUTO_TEST_CASE(Test1)
    {
        auto loginManager = std::make_shared<LoginManager>();
        auto account = std::make_shared<Member>("Member","login","password");

        loginManager->setAdminUsername("admin");
        loginManager->setLoggedAccount(account);

        BOOST_TEST(loginManager->loggedAccountIsAdmin() == false);
    }

BOOST_AUTO_TEST_SUITE_END()

