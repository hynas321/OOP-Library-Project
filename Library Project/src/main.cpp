#include <memory>
#include "Library.h"
#include "FileManager.h"

int main() {
    FileManager fm("/home/student/CLionProjects/Library Project/savedFiles/myLibrary");
    AccountStorage as;
    RentStorage rs;
    BookStorage bs;

    fm.readFromAFile();

    auto member1 = std::make_shared<Member>("Piotr H", "piotr", "12345");
    auto member2 = std::make_shared<Member>("Dawid S", "dawid", "12345");

    auto book1 = std::make_shared<Book>("Alice's Adventures in Wonderland","Lewis Carroll","Fantasy");
    auto book2 = std::make_shared<Book>("Crime and Punishment","Fyodor Dostoyevsky","Crime fiction");
    auto book3 = std::make_shared<Book>("The Odyssey","Homer","Epic poetry");

    auto rent = std::make_shared<Rent>(book2,member1);
    auto rent2 = std::make_shared<Rent>(book3,member2);

    auto admin1 = Admin::instance("Admin Account","admin","admin1");
    auto admin2 = Admin::instance("Admin Account","admin","admin2");

    /*bs.addBook(book1);
    bs.addBook(book2);
    bs.addBook(book3);

    as.addAccount(member1);
    as.addAccount(member2);

    rs.addRent(rent);
    rs.addRent(rent2);*/

    Library library(admin2);
    library.menu();

    fm.saveToAFile();
    return 0;
}

