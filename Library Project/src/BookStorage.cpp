#include "BookStorage.h"

std::vector<std::shared_ptr<Book>> BookStorage::books;

BookStorage::BookStorage() = default;
BookStorage::~BookStorage() = default;

bool BookStorage::addBook(const std::shared_ptr<Book>& book) {
    int id = 1;

    if (books.empty()) {
        book->setId(id);
    }
    else {
        for (auto book : books) {
            if (book->getId() != id) {
                break;
            }
            id++;
        }
    }
    book->setId(id);

    try {
        books.push_back(book);
    }
    catch (...) {
        return false;
    }

    return true;
}

bool BookStorage::removeBook(const std::shared_ptr<Book>& book) {
    try {
        for (int i = 0; i < books.size(); i++) {
            if (book == books[i] && !book->getStatus()) {
                books.erase(books.cbegin() + i);
                return true;
            }
            else if (book == books[i] && book->getStatus()) {
                return false;
            }
        }
    }
    catch (...) {
        return false;
    }
    return false;
}

std::shared_ptr<Book> BookStorage::findBook(int id) {
    for (auto book : books) {
        if (id == book->getId()) {
            return book;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Book>> BookStorage::getBooks() {
    return books;
}

int BookStorage::getBooksCount() {
    return books.size();
}


