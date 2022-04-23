#include "Rent.h"

#include <utility>

Rent::Rent(std::shared_ptr<Book> book, std::shared_ptr<Account> account) :
    book(std::move(book)), account(std::move(account)) {
    startDate = boost::gregorian::date(boost::gregorian::day_clock::local_day());
    endDate = startDate + boost::gregorian::days(60);
}
Rent::~Rent() = default;

int Rent::getId() {
    return id;
}

void Rent::setId(int id) {
    this->id = id;
}

boost::gregorian::date Rent::getStartDate() {
    return startDate;
}

boost::gregorian::date Rent::setStartDate(boost::gregorian::date date) {
    return startDate = date;
}

boost::gregorian::date Rent::getEndDate() {
    return endDate;
}

boost::gregorian::date Rent::setEndDate(boost::gregorian::date date) {
    return endDate = date;
}

std::shared_ptr<Book> Rent::getBook() {
    return book;
}

std::shared_ptr<Account> Rent::getAccount() {
    return account;
}
std::string Rent::printInfo() {
    return "Rent's ID: " + std::to_string(id) + ", Start date: " + boost::gregorian::to_simple_string(startDate) + ", End date: " + boost::gregorian::to_simple_string(endDate) + "\n" + "Book's ID: "
    + std::to_string(book->getId()) + ", Book's title: " + book->getTitle() + ", Renter: " + account->getUsername() +"\n";
}




