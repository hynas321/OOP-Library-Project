#ifndef LIBRARY_MEMBER_H
#define LIBRARY_MEMBER_H
#include "Account.h"

class Member : public Account {
private:
    int maxRents;
    std::string role {"Member"};

public:
    Member(std::string name, std::string username, std::string password);
    ~Member();

    int getMaxRents();
    void setMaxRents(int maxRents);
    std::string getRole() override;
    std::string printInfo() override;
};


#endif //LIBRARY_MEMBER_H
