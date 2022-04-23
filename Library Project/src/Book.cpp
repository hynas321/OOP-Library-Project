#include "Book.h"

Book::Book(std::string title, std::string author, std::string genre) :
   id(id), title(title), author(author), genre(genre) {}

Book::~Book() = default;

int Book::getId() {
    return id;
}

void Book::setId(int id) {
    this->id = id;
}


std::string Book::getTitle() {
    return title;
}

std::string Book::getAuthor() {
    return author;
}

std::string Book::getGenre() {
    return genre;
}

bool Book::getStatus() {
    return rentedStatus;
}

void Book::setStatus(bool status) {
    rentedStatus = status;
}

std::string Book::printInfo() {
    return "ID: " + std::to_string(id) + ", Title: " + getTitle() + + "\n" + "Author: " + getAuthor() + ", Genre: " + getGenre() + + "\n" + "Rented: "
    + std::to_string(getStatus()) + "\n";
}

