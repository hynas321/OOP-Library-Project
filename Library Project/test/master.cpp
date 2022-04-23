#define BOOST_AUTO_TEST_MAIN//root of all tests suites and cases
#define BOOST_TEST_DYN_LINK //use shared boost library
#include <boost/test/unit_test.hpp>
using namespace boost::unit_test;

struct MyConfig {
    MyConfig() {}
    ~MyConfig() {}
};

BOOST_GLOBAL_FIXTURE(MyConfig);