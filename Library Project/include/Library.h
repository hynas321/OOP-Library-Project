#ifndef LIBRARY_LIBRARYMENU_H
#define LIBRARY_LIBRARYMENU_H
#include <thread>
#include <iostream>
#include <ostream>
#include <string>
#include <memory>
#include <SFML/Audio.hpp>
#include "AccountManager.h"
#include "BookStorage.h"
#include "LoginManager.h"
#include "RentManager.h"

class Library {
private:
    LoginManager loginManager;
    AccountManager accountManager;
    AccountStorage accountStorage;
    BookStorage bookStorage;
    RentManager rentManager;
    RentStorage rentStorage;

    sf::Music music;

public:
    explicit Library(const std::shared_ptr<Admin>& adminAccount);
    ~Library();

    void menu();
    void printMessage(std::string title, std::string text);
    template<typename T> void printQuestion(std::string title, std::string text, T function);

    void logInMenu();
    void logOutMenu();
    void signUpMenu();

    void accountMenu();
    void deleteAccountMenu();

    void addBookMenu();
    void removeBookMenu();
    void rentBookMenu();
    void returnBookMenu();

    void printBooks();
    void printAccounts();
    void printRents();

    void exit();
};


#endif //LIBRARY_LIBRARYMENU_H
