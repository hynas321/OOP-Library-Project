#ifndef LIBRARY_FILEMANAGER_H
#define LIBRARY_FILEMANAGER_H
#include <boost/range/adaptor/sliced.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <memory>
#include "AccountStorage.h"
#include "BookStorage.h"
#include "RentStorage.h"
#include "FileManager.h"

class FileManager {
private:
    AccountStorage accountStorage;
    BookStorage bookStorage;
    RentStorage rentStorage;
    RentManager rentManager;
    std::string path;

public:
    FileManager(std::string path);
    ~FileManager();

    void saveToAFile();
    void readFromAFile();
};


#endif //LIBRARY_FILEMANAGER_H
