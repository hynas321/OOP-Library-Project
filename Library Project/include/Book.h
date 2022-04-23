#ifndef LIBRARY_BOOK_H
#define LIBRARY_BOOK_H
#include <string>

class Book {
private:
    int id;
    std::string title;
    std::string author;
    std::string genre;
    bool rentedStatus {false};

public:
    Book(std::string title, std::string author, std::string genre);
    ~Book();

    int getId();
    void setId(int id);
    std::string getTitle();
    std::string getAuthor();
    std::string getGenre();
    bool getStatus();
    void setStatus(bool status);
    std::string printInfo();

};


#endif //LIBRARY_BOOK_H
