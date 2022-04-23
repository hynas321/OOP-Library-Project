#ifndef LIBRARY_BOOKSTORAGE_H
#define LIBRARY_BOOKSTORAGE_H
#include <memory>
#include <vector>
#include "Book.h"

class BookStorage {
private:
    static std::vector<std::shared_ptr<Book>> books;

public:
    BookStorage();
    ~BookStorage();

    bool addBook(const std::shared_ptr<Book>& book);
    bool removeBook(const std::shared_ptr<Book>& book);
    std::shared_ptr<Book> findBook(int id);
    std::vector<std::shared_ptr<Book>> getBooks();
    int getBooksCount();
};


#endif //LIBRARY_BOOKSTORAGE_H
