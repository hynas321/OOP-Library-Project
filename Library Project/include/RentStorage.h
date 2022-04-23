#ifndef LIBRARY_RENTSTORAGE_H
#define LIBRARY_RENTSTORAGE_H
#include <vector>
#include "Rent.h"

class RentStorage {
    static std::vector<std::shared_ptr<Rent>> rents;

public:
    RentStorage();
    ~RentStorage();

    bool addRent(const std::shared_ptr<Rent>& rent);
    bool removeRent(const std::shared_ptr<Rent>& rent);
    std::shared_ptr<Rent> findRent(int id);
    std::vector<std::shared_ptr<Rent>> getRents();
    int getRentsCount();
};


#endif //LIBRARY_RENTSTORAGE_H
