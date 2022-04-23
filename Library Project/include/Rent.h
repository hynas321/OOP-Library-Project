#ifndef LIBRARY_RENT_H
#define LIBRARY_RENT_H
#include <boost/date_time/gregorian/gregorian.hpp>
#include <memory>
#include <string>
#include "Account.h"
#include "Book.h"

class Rent {
private:
    int id;
    boost::gregorian::date startDate;
    boost::gregorian::date endDate;
    std::shared_ptr<Book> book {nullptr};
    std::shared_ptr<Account> account {nullptr};

public:
    Rent(std::shared_ptr<Book> book, std::shared_ptr<Account> account);
    ~Rent();

    int getId();
    void setId(int id);
    boost::gregorian::date getStartDate();
    boost::gregorian::date setStartDate(boost::gregorian::date date);
    boost::gregorian::date getEndDate();
    boost::gregorian::date setEndDate(boost::gregorian::date date);
    std::shared_ptr<Book> getBook();
    std::shared_ptr<Account> getAccount();
    std::string printInfo();
};


#endif //LIBRARY_RENT_H
