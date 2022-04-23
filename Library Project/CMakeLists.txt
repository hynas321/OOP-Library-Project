cmake_minimum_required(VERSION 3.20)
project(Library_Project)
set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS audio REQUIRED)
include_directories(include ${SFML_INCLUDE_DIR})

add_executable(Library_Project
        include/Account.h           src/Account.cpp
        include/AccountManager.h    src/AccountManager.cpp
        include/AccountStorage.h    src/AccountStorage.cpp
        include/Admin.h             src/Admin.cpp
        include/Book.h              src/Book.cpp
        include/BookStorage.h       src/BookStorage.cpp
        include/Member.h            src/Member.cpp
        include/FileManager.h       src/FileManager.cpp
        include/Library.h           src/Library.cpp
        include/LoginManager.h      src/LoginManager.cpp
        include/Rent.h              src/Rent.cpp
        include/RentManager.h       src/RentManager.cpp
        include/RentStorage.h       src/RentStorage.cpp
        src/main.cpp)

target_link_libraries(Library_Project sfml-audio)

enable_testing()
set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.67.0 COMPONENTS unit_test_framework date_time REQUIRED)
include_directories(
        include
        ${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIR})
add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

add_executable(Library_Project_Test
        include/Account.h           src/Account.cpp
        include/AccountManager.h    src/AccountManager.cpp
        include/AccountStorage.h    src/AccountStorage.cpp
        include/Book.h              src/Book.cpp
        include/BookStorage.h       src/BookStorage.cpp
        include/Member.h            src/Member.cpp
        include/FileManager.h       src/FileManager.cpp
        include/Library.h           src/Library.cpp
        include/LoginManager.h      src/LoginManager.cpp
        include/Rent.h              src/Rent.cpp
        include/RentManager.h       src/RentManager.cpp
        include/RentStorage.h       src/RentStorage.cpp

        test/master.cpp
        test/AccountManagerTest.cpp
        test/AccountStorageTest.cpp
        test/BookStorageTest.cpp
        test/LoginManagerTest.cpp
        test/RentManagerTest.cpp
        test/RentStorageTest.cpp)

target_link_libraries(Library_Project_Test
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} sfml-audio)

add_test(Library_Test Library_Project_Tester
        --report_level=detailed
        --log_level=all
        --color_output=yes)