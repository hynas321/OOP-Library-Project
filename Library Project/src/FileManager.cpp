#include "FileManager.h"

FileManager::FileManager(std::string path) : path(path) {}
FileManager::~FileManager() = default;

void FileManager::saveToAFile() {
    std::ofstream file;
    std::string objectType;

    file.open(path);

    for (auto account : accountStorage.getAccounts()) {
        if (account->getRole() == "Member") {
            file << "MEMBER" << "\n" << account->getName() << "\n" << account->getUsername() << "\n" << account->getPassword() << "\n\n";
        }
    }

    for (auto book : bookStorage.getBooks()) {
        file << "BOOK" << "\n" << book->getId() << "\n" << book->getTitle() << "\n" << book->getAuthor() << "\n" << book->getGenre()
             << "\n" << book->getStatus() << "\n\n";
    }

    for (auto rent : rentStorage.getRents()) {
        file << "RENT" << "\n" << rent->getId() << "\n" << rent->getStartDate() << "\n" << rent->getEndDate() << "\n"
             << rent->getAccount()->getUsername() << "\n" << rent->getBook()->getId() << "\n\n";
    }

    file.close();
}

void FileManager::readFromAFile() {
    std::ifstream file;
    std::string line;
    std::string keyword;

    int lineNum = 0;
    int lineInitial = 0;

    std::string input1, input2, input3, input4, input5;

    file.open(path, std::ios::out);

    while(std::getline(file, line)) {
        if (line.empty()) {
            lineNum++;
            continue;
        }

        else if (line.find("MEMBER") != std::string::npos) {
            lineInitial = lineNum;
            keyword = "MEMBER";
        }
        else if (keyword == "MEMBER") {
            if      (lineNum == lineInitial + 1) { input1 = line; }
            else if (lineNum == lineInitial + 2) { input2 = line; }
            else if (lineNum == lineInitial + 3) {
                input3 = line;

                auto account = std::make_shared<Member>(input1, input2, input3);
                accountStorage.addAccount(account);

                lineInitial = 0;
                keyword = "";
            }
        }

        else if (line.find("BOOK") != std::string::npos) {
            lineInitial = lineNum;
            keyword = "BOOK";
        }
        else if (keyword == "BOOK") {
            if      (lineNum == lineInitial + 1) { input1 = line; }
            else if (lineNum == lineInitial + 2) { input2 = line; }
            else if (lineNum == lineInitial + 3) { input3 = line; }
            else if (lineNum == lineInitial + 4) { input4 = line; }
            else if (lineNum == lineInitial + 5) {
                input5 = line;

                auto book = std::make_shared<Book>(input2, input3, input4);
                book->setId(atoi(input1.c_str()));
                book->setStatus(!(atoi(input5.c_str()) - '0'));
                bookStorage.addBook(book);

                lineInitial = 0;
                keyword = "";
            }
        }

        else if (line.find("RENT") != std::string::npos) {
            lineInitial = lineNum;
            keyword = "RENT";
        }
        else if (keyword == "RENT") {
            if      (lineNum == lineInitial + 1) { input1 = line; }
            else if (lineNum == lineInitial + 2) { input2 = line; }
            else if (lineNum == lineInitial + 3) { input3 = line; }
            else if (lineNum == lineInitial + 4) { input4 = line; }
            else if (lineNum == lineInitial + 5) {
                input5 = line;

                std::shared_ptr<Book> book;
                std::shared_ptr<Account> account;

                book = bookStorage.findBook(atoi(input5.c_str()));
                account = accountStorage.findAccount(input4);

                auto rent = std::make_shared<Rent>(book, account);

                rent->setId(atoi(input1.c_str()));
                rent->setStartDate(boost::gregorian::date(boost::gregorian::from_string(input2)));
                rent->setEndDate(boost::gregorian::date(boost::gregorian::from_string(input3)));

                if (rentManager.rentValidDate(rent)) {
                    rentStorage.addRent(rent);
                }

                lineInitial = 0;
                keyword = "";
            }
        }
        lineNum++;
    }
    file.close();

    //RentManager rent correct date
}
