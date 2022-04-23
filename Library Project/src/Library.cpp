#include "Library.h"

namespace Color {
    enum Code {
        red    = 31,
        green  = 32,
        yellow = 33,
        blue   = 34,
        gray   = 39,
    };

    std::ostream& operator<<(std::ostream& os, Code code) {
        return os << "\033[" << static_cast<int>(code) << "m";
    }
}

Library::Library(const std::shared_ptr<Admin>& adminAccount) {
    loginManager.setAdminUsername(adminAccount->getUsername());
    accountStorage.addAccount(adminAccount);

    if (music.openFromFile("/home/student/CLionProjects/Library Project/sounds/startsound.wav")) {
        music.play();
    }
}

Library::~Library() {
}

void Library::menu() {
    std::string inputAction;
    while (true) {
        std::cout << "\n";
        std::cout << Color::blue << "========================================" << Color::gray << std::endl;
        std::cout << "Number of members: " << accountStorage.getAccountsCount() - 1 << std::endl;
        std::cout << "Number of books: " << bookStorage.getBooksCount() << std::endl;
        std::cout << "Number of rents: " << rentStorage.getRentsCount() << std::endl;
        std::cout << Color::blue << "============= LIBRARY MENU =============" << Color::gray << std::endl;
        std::cout << "Choose your action by entering the digit" << std::endl;
        std::cout << "1) Log in" << std::endl;
        std::cout << "2) Sign in" << std::endl;
        std::cout << "3) Exit " << std::endl;
        std::cout << Color::blue << "========================================" << Color::gray << std::endl;
        std::cout << ">>> ";

        std::cin >> inputAction;

        switch (inputAction[0]) {
            case '1':
                return logInMenu();
            case '2':
                return signUpMenu();
            case '3':
                return exit();
            default:
                std::cout << Color::red << "*** Incorrect digit ***" << Color::gray << std::endl;
                continue;
        }
    }

}

void Library::printMessage(std::string title, std::string text) {
    std::cout << "\n";
    std::cout << Color::blue << title << Color::gray << std::endl;
    std::cout << Color::blue << "========================================" << Color::gray << std::endl;
    std::cout << text << std::endl;
    std::cout << Color::blue << "========================================" << Color::gray << std::endl;
    std::cout << ">>> ";
}

template<typename T>
void Library::printQuestion(std::string title, std::string text, T function) {
    std::cout << "\n";
    std::cout << Color::blue << title << Color::gray << std::endl;
    std::cout << Color::blue << "========================================" << Color::gray << std::endl;
    std::cout << function << std::endl;
    std::cout << text << std::endl;
    std::cout << "1) Yes" << std::endl;
    std::cout << "2) No" << std::endl;
    std::cout << Color::blue << "========================================" << Color::gray << std::endl;
    std::cout << ">>> ";
}

void Library::logInMenu() {
    std::string inputUsername;
    std::string inputPassword;

    printMessage("LOG IN", "Enter your username");
    std::cin >> inputUsername;

    printMessage("LOG IN", "Enter your password");
    std::cin >> inputPassword;

    auto account = loginManager.checkCredentials(inputUsername, inputPassword);

    if (account != nullptr) {
        loginManager.LogIn(account);
        std::cout << Color::green << "*** You have successfully logged in ***" << Color::gray << std::endl;
        return accountMenu();
    }
    else {
        std::cout << Color::red << "*** Incorrect username or password ***" << Color::gray << std::endl;
        return menu();
    }
}

void Library::logOutMenu() {
    loginManager.LogOut();
    std::cout << Color::green << "*** You have logged out ***" << Color::gray << std::endl;
    return menu();
}

void Library::signUpMenu() {
    std::string inputUsername;
    std::string inputPassword;
    std::string inputName;
    std::string inputAction;

    printMessage("SIGN UP", "Enter your username (5-15 chars)");
    std::cin >> inputUsername;

    if (!accountManager.correctUsername(inputUsername)) {
        std::cout << Color::red << "*** The username has an incorrect length ***" << Color::gray << std::endl;
        return menu();
    }

    if (loginManager.accountExists(inputUsername)) {
        std::cout << Color::red << "*** The account already exists ***" << Color::gray << std::endl;
        return menu();
    }

    printMessage("SIGN UP", "Enter your password (5-20 chars)");
    std::cin >> inputPassword;

    if (!accountManager.correctPassword(inputPassword)) {
        std::cout << Color::red << "*** The password has an incorrect length ***" << Color::gray << std::endl;
        return menu();
    }

    printMessage("SIGN UP", "Enter your full name (5-25 chars)");
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::getline(std::cin, inputName);

    if (!accountManager.correctFullName(inputName)) {
        std::cout << Color::red << "*** The full name has an incorrect length ***" << Color::gray << std::endl;
        return menu();
    }

    std::cout << "\n";
    std::cout << Color::blue << "============= SIGN-UP MENU =============" << Color::gray << std::endl;
    std::cout << "Your username: " << inputUsername << std::endl;
    std::cout << "Your full name: " << inputName << std::endl;
    std::cout << "Would you like to register this account?" << std::endl;
    std::cout << "1) Yes" << std::endl;
    std::cout << "2) No" << std::endl;
    std::cout << Color::blue << "========================================" << Color::gray << std::endl;
    std::cout << ">>> ";
    std::cin >> inputAction;

    std::shared_ptr<Member> account;
    bool added;

    switch (inputAction[0]) {
        case '1':
            account = std::make_shared<Member>(inputName, inputUsername, inputPassword);
            added = accountStorage.addAccount(account);

            if (added) {
                std::cout << Color::green << "*** Account has been registered ***" << Color::gray << std::endl;
                loginManager.setLoggedAccount(accountStorage.getAccounts().back());
            }
            else {
                std::cout << Color::red << "*** ERROR: Account has not been registered ***" << Color::gray << std::endl;
            }
            return accountMenu();
        default:
            std::cout << Color::yellow << "*** Account has not been registered ***" << Color::gray << std::endl;
            return menu();
    }
}

void Library::accountMenu() {
    std::string actionInput;

    if (!loginManager.loggedAccountIsAdmin()) {
        std::cout << "\n";
        std::cout << Color::blue << "============= MEMBER MENU ==============" << Color::gray << std::endl;
        std::cout << loginManager.getLoggedAccount()->printInfo() << std::endl;
        std::cout << "1) Manage your rents" << std::endl;
        std::cout << "2) Print all books" << std::endl;
        std::cout << "3) Delete your account" << std::endl;
        std::cout << "4) Log Out" << std::endl;
        std::cout << Color::blue << "========================================" << Color::gray << std::endl;
        std::cout << ">>> ";
        std::cin >> actionInput;

        switch (actionInput[0]) {
            case '1':
                return printRents();
            case '2':
                return printBooks();
            case '3':
                return deleteAccountMenu();
            case '4':
                return logOutMenu();
            default:
                std::cout << Color::red << "*** Incorrect digit ***" << Color::gray << std::endl;
                return accountMenu();
        }
    }
    else {
        std::cout << "\n";
        std::cout << Color::blue << "============== ADMIN MENU ==============" << Color::gray << std::endl;
        std::cout << loginManager.getLoggedAccount()->printInfo() << std::endl;
        std::cout << "1) Print all rents" << std::endl;
        std::cout << "2) Print all books" << std::endl;
        std::cout << "3) Print all accounts" << std::endl;
        std::cout << "4) Add a book" << std::endl;
        std::cout << "5) Remove a book" << std::endl;
        std::cout << "6) Log Out" << std::endl;
        std::cout << Color::blue << "========================================" << Color::gray << std::endl;
        std::cout << ">>> ";
        std::cin >> actionInput;

        switch (actionInput[0]) {
            case '1':
                return printRents();
            case '2':
                return printBooks();
            case '3':
                return printAccounts();
            case '4':
                return addBookMenu();
            case '5':
                return removeBookMenu();
            case '6':
                return logOutMenu();
            default:
                std::cout << Color::red << "*** Incorrect digit ***" << Color::gray << std::endl;
                return accountMenu();
        }
    }
}

void Library::deleteAccountMenu() {
    std::string inputAction;

    if (!rentManager.noRentsOnAccount(loginManager.getLoggedAccount())) {
        std::cout << Color::red << "*** You cannot delete your account, there are active rents ***" << Color::gray << std::endl;
        return accountMenu();
    }

    printQuestion("ACCOUNT MENU", "Would you like to delete this account?", loginManager.getLoggedAccount()->printInfo());

    std::cin >> inputAction;
    bool removed;

    switch (inputAction[0]) {
        case '1':
            removed = accountStorage.removeAccount(loginManager.getLoggedAccount());
            if (removed) {
                loginManager.LogOut();
                std::cout << Color::green << "*** Account has been removed ***" << Color::gray << std::endl;
                return menu();
            }
        default:
            std::cout << Color::yellow << "*** Account has not been removed ***" << Color::gray << std::endl;
            return accountMenu();
    }
}

void Library::exit() {
    if (music.openFromFile("/home/student/CLionProjects/Library Project/sounds/endsound.wav")) {
        music.play();
    }
    std::this_thread::sleep_for (std::chrono::milliseconds(850));
    std::cout << "\n";
    std::cout << Color::green << "*** PROGRAM TERMINATED ***" << Color::gray << std::endl;
    EXIT_SUCCESS;
}

void Library::printBooks() {
    std::string inputAction;

    std::cout << "\n";
    std::cout << Color::blue << "============== ALL BOOKS ===============" << Color::gray << std::endl;
    for (auto const& book : bookStorage.getBooks()) {
        std::cout << book->printInfo() << std::endl;
    }

    std::cout << "Input anything to go back..." << std::endl;
    std::cout << Color::blue << "========================================" << Color::gray << std::endl;
    std::cout << ">>> ";
    std::cin >> inputAction;
    return accountMenu();

}

void Library::printAccounts() {
    std::string inputAction;

    std::cout << "\n";
    std::cout << Color::blue << "============== ACCOUNTS ===============" << Color::gray << std::endl;
    for (auto const& account : accountStorage.getAccounts()) {
        std::cout << account->printInfo() << std::endl;
    }

    std::cout << "Input anything to go back..." << std::endl;
    std::cout << Color::blue << "========================================" << Color::gray << std::endl;
    std::cout << ">>> ";
    std::cin >> inputAction;
    return accountMenu();
}

void Library::printRents() {
    std::string inputAction;

    if (loginManager.getLoggedAccount()->getUsername() != loginManager.getAdminUsername()) {
        std::cout << "\n";
        std::cout << Color::blue << "============== YOUR RENTS ==============" << Color::gray << std::endl;
        for (const auto& rent : rentStorage.getRents()) {
            if (rent->getAccount() == loginManager.getLoggedAccount()) {
                std::cout << rent->printInfo() << std::endl;
            }
        }
        std::cout << "1) Rent a book" << std::endl;
        std::cout << "2) Return a book" << std::endl;
        std::cout << "3) Go back" << std::endl;
        std::cout << Color::blue << "========================================" << Color::gray << std::endl;
        std::cout << ">>> ";
        std::cin >> inputAction;

        switch (inputAction[0]) {
            case '1':
                return rentBookMenu();
            case '2':
                return returnBookMenu();
            default:
                return accountMenu();
        }
    }

    else {
        std::cout << "\n";
        std::cout << Color::blue << "============== ALL RENTS ===============" << Color::gray << std::endl;
        for (const auto& rent : rentStorage.getRents()) {
            std::cout << rent->printInfo() << std::endl;
        }
        std::cout << "Input anything to go back..." << std::endl;
        std::cout << Color::blue << "========================================" << Color::gray << std::endl;
        std::cout << ">>> ";

        std::cin >> inputAction;
        return accountMenu();
    }
}

void Library::addBookMenu() {
    std::string inputAction;
    std::string inputTitle;
    std::string inputAuthor;
    std::string inputGenre;

    printMessage("ADD BOOK", "Enter book's title");
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::getline(std::cin, inputTitle);

    printMessage("ADD BOOK", "Enter book's author");
    std::getline(std::cin, inputAuthor);

    printMessage("ADD BOOK", "Enter book's genre");
    std::getline(std::cin, inputGenre);

    std::cout << "\n";
    std::cout << Color::blue << "=============== ADD BOOK ===============" << Color::gray << std::endl;
    std::cout << "Book's title: " + inputTitle << std::endl;
    std::cout << "Book's author: " + inputAuthor << std::endl;
    std::cout << "Book's genre: " + inputGenre << std::endl;
    std::cout << "Would you like to add it?" << std::endl;
    std::cout << "1) Yes" << std::endl;
    std::cout << "2) No" << std::endl;
    std::cout << Color::blue << "========================================" << Color::gray << std::endl;
    std::cout << ">>> ";
    std::cin >> inputAction;

    std::shared_ptr<Book> book;
    bool added;

    switch (inputAction[0]) {
        case '1':
            book = std::make_shared<Book>(inputTitle, inputAuthor, inputGenre);
            added = bookStorage.addBook(book);

            if (added) {
                std::cout << Color::green << "*** Book has been added ***" << Color::gray << std::endl;
                break;
            }
        default:
            std::cout << Color::yellow << "*** No changes have been made ***" << Color::gray << std::endl;
            break;
    }
    return accountMenu();
}

void Library::removeBookMenu() {
    std::string inputId;
    std::string inputAction;

    printMessage("REMOVE BOOK", "Enter book's ID");
    std::cin >> inputId;

    try {
        std::stoi(inputId);
    }
    catch (...) {
        inputId = "-1";
    }

    auto book = bookStorage.findBook(std::stoi(inputId));

    if (book != nullptr && !book->getStatus()) {
        printQuestion("REMOVE BOOK", "Would you like to remove this book?", book->printInfo());

        std::cin >> inputAction;

        bool removed;
        switch (inputAction[0]) {
            case '1':
                removed = bookStorage.removeBook(book);

                if (removed) {
                    std::cout << Color::green << "*** Book has been removed ***" << Color::gray << std::endl;
                    break;
                }
            default:
                std::cout << Color::yellow << "*** Book has not been removed ***" << Color::gray << std::endl;
                break;
        }
    }
    else if (book != nullptr) {
        std::cout << Color::red << "*** Book cannot be deleted, rent activated ***" << Color::gray << std::endl;
        return accountMenu();
    }
    else {
        std::cout << Color::red << "*** Book does not exist ***" << Color::gray << std::endl;
    }

    return accountMenu();

}

void Library::rentBookMenu() {
    std::string inputId;
    std::string inputAction;

    if (rentManager.rentCountOnAccount(loginManager.getLoggedAccount()) == 3) {
        std::cout << Color::red << "*** You have reached the maximum number of rents (3) ***" << Color::gray << std::endl;
        return accountMenu();
    }

    printMessage("RENT BOOK", "Enter book's ID");
    std::cin >> inputId;

    try {
        std::stoi(inputId);
    }
    catch (...) {
        inputId = "-1";
    }

    auto book = bookStorage.findBook(std::stoi(inputId));

    if (book != nullptr && book->getStatus()) {
        std::cout << Color::red << "*** Book has already been rented ***" << Color::gray << std::endl;
    }
    else if (book != nullptr) {
        printQuestion("RENT BOOK", "Would you like to rent this book?", book->printInfo());

        std::cin >> inputAction;

        bool rented;
        std::shared_ptr<Rent> rent;

        switch (inputAction[0]) {
            case '1':
                rent = std::make_shared<Rent>(book, loginManager.getLoggedAccount());
                rented = rentStorage.addRent(rent);

                if (rented) {
                    std::cout << Color::green << "*** Book has been rented ***" << Color::gray << std::endl;
                    break;
                }
            default:
                std::cout << Color::yellow << "*** Book has not been rented ***" << Color::gray << std::endl;
                break;
        }
    }
    else {
        std::cout << Color::red << "*** Book does not exist ***" << Color::gray << std::endl;
    }

    return accountMenu();

}

void Library::returnBookMenu() {
    std::string inputId;
    std::string inputAction;

    if (!loginManager.loggedAccountIsAdmin()) {
        printMessage("RETURN BOOK", "Enter rent's ID");
    }
    else {
        printMessage("REMOVE RENT", "Enter rent's ID");
    }

    std::cin >> inputId;

    try {
        std::stoi(inputId);
    }
    catch (...) {
        inputId = "-1";
    }

    auto rent = rentStorage.findRent(std::stoi(inputId));

    if (rentManager.rentOnAccount(rent, loginManager.getLoggedAccount()) || rent != nullptr && loginManager.loggedAccountIsAdmin()) {
        printQuestion("RETURN BOOK", "Would you like to end this rent?", rent->printInfo());

        std::cin >> inputAction;
        bool removed;

        switch (inputAction[0]) {
            case '1':
                removed = rentStorage.removeRent(rent);
                if (removed) {
                    std::cout << Color::green << "*** Rent has been removed ***" << Color::gray << std::endl;
                    break;
                }
            default:
                std::cout << Color::yellow << "*** Rent has not been removed ***" << Color::gray << std::endl;
                break;
        }
    }
    else if (rent != nullptr && !loginManager.loggedAccountIsAdmin()) {
        std::cout << Color::red << "*** Rent does not belong to your account ***" << Color::gray << std::endl;
    }
    else {
        std::cout << Color::red << "*** Rent does not exist ***" << Color::gray << std::endl;
    }

    return accountMenu();
}









