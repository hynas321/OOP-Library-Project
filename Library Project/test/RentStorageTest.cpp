#include <boost/test/unit_test.hpp>
#include "RentStorage.h"
#include "Book.h"
#include "Account.h"

BOOST_AUTO_TEST_SUITE(RentStorageTestSuite)

    BOOST_AUTO_TEST_CASE(Test1)
    {
        auto rentStorage = std::make_shared<RentStorage>();
        auto book1 = std::make_shared<Book>("title1","author1","genre1");
        auto book2 = std::make_shared<Book>("title2","author2","genre2");

        auto account1 = std::make_shared<Account>("account1","account1","password1");
        auto account2 = std::make_shared<Account>("account2","account2","password2");

        auto rent1 = std::make_shared<Rent>(book1,account1);
        auto rent2 = std::make_shared<Rent>(book2,account2);

        BOOST_TEST(rentStorage->addRent(rent1) == true);
        BOOST_TEST(rentStorage->addRent(rent2) == true);

        BOOST_TEST(rentStorage->getRentsCount() == 2);

        BOOST_TEST(rentStorage->removeRent(rent1) == true);
        BOOST_TEST(rentStorage->removeRent(rent2) == true);

        BOOST_TEST(rentStorage->getRentsCount() == 0);
    }

    BOOST_AUTO_TEST_CASE(Test2)
    {
        auto rentStorage = std::make_shared<RentStorage>();
        auto book1 = std::make_shared<Book>("title1","author1","genre1");
        auto book2 = std::make_shared<Book>("title2","author2","genre2");

        auto account1 = std::make_shared<Account>("account1","account1","password1");
        auto account2 = std::make_shared<Account>("account2","account2","password2");

        auto rent1 = std::make_shared<Rent>(book1,account1);
        auto rent2 = std::make_shared<Rent>(book2,account2);

        BOOST_TEST(rentStorage->addRent(rent1) == true);
        BOOST_TEST(rentStorage->addRent(rent2) == true);

        BOOST_TEST(rentStorage->removeRent(rent1) == true);
        BOOST_TEST(rentStorage->removeRent(rent2) == true);

        BOOST_TEST(rentStorage->removeRent(rent1) == false);
        BOOST_TEST(rentStorage->removeRent(rent2) == false);
    }


BOOST_AUTO_TEST_SUITE_END()