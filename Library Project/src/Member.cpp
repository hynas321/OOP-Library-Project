#include "Member.h"

Member::Member(std::string name, std::string username, std::string password) : Account(name, username, password) {
    setMaxRents(3);
}
Member::~Member() = default;


int Member::getMaxRents() {
    return maxRents;
}

void Member::setMaxRents(int maxRents) {
    this->maxRents = maxRents;
}

std::string Member::getRole() {
    return role;
}

std::string Member::printInfo() {
    return Account::printInfo() + "Role: " + role + "\n" + "Max rents: " + std::to_string(maxRents) + "\n";
}


