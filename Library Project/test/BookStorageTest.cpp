#include <boost/test/unit_test.hpp>
#include "BookStorage.h"

BOOST_AUTO_TEST_SUITE(BookStorageTestSuite)

    BOOST_AUTO_TEST_CASE(Test1)
    {
        auto bookStorage = std::make_shared<BookStorage>();
        auto book1 = std::make_shared<Book>("title1","author1","genre1");
        auto book2 = std::make_shared<Book>("title1","author2","genre2");

        BOOST_TEST(bookStorage->addBook(book1) == true);
        BOOST_TEST(bookStorage->addBook(book2) == true);

        BOOST_TEST(bookStorage->getBooksCount() == 2);

        BOOST_TEST(bookStorage->removeBook(book1) == true);
        BOOST_TEST(bookStorage->removeBook(book2) == true);

        BOOST_TEST(bookStorage->getBooksCount() == 0);
    }

    BOOST_AUTO_TEST_CASE(Test2)
    {
        auto bookStorage = std::make_shared<BookStorage>();
        auto book1 = std::make_shared<Book>("title1","author1","genre1");
        auto book2 = std::make_shared<Book>("title1","author2","genre2");

        BOOST_TEST(bookStorage->addBook(book1) == true);
        BOOST_TEST(bookStorage->addBook(book2) == true);

        BOOST_TEST(bookStorage->removeBook(book1) == true);
        BOOST_TEST(bookStorage->removeBook(book2) == true);

        BOOST_TEST(bookStorage->removeBook(book1) == false);
        BOOST_TEST(bookStorage->removeBook(book2) == false);
    }


BOOST_AUTO_TEST_SUITE_END()

