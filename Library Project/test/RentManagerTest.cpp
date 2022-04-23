#include <boost/test/unit_test.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include "RentManager.h"

#include "Book.h"
#include "Account.h"

BOOST_AUTO_TEST_SUITE(RentManagerTestSuite)

    BOOST_AUTO_TEST_CASE(Test1)
    {
        auto rentManager = std::make_shared<RentManager>();
        auto account1 = std::make_shared<Account>("Name","username2","password");
        auto account2 = std::make_shared<Account>("Name", "username2", "password");

        auto book1 = std::make_shared<Book>("title1", "author1", "genre1");
        auto book2 = std::make_shared<Book>("title2", "author2", "genre2");

        auto rent1 = std::make_shared<Rent>(book1, account1);
        auto rent2 = std::make_shared<Rent>(book2, account2);

        BOOST_TEST(rentManager->rentOnAccount(rent1, account1) == true);
        BOOST_TEST(rentManager->rentOnAccount(rent2, account1) == false);

        rent2->setStartDate(boost::gregorian::date(2001,02,17));
        rent2->setEndDate(boost::gregorian::date(2001,04,17));

        BOOST_TEST(rentManager->rentValidDate(rent1) == true);
        BOOST_TEST(rentManager->rentValidDate(rent2) == false);
    }

BOOST_AUTO_TEST_SUITE_END()


