#include <iostream>
#include <boost/any.hpp>

int test_boost()
{
    boost::any a(5);
    a = 7.67;
    std::cout << boost::any_cast<double>(a) << std::endl;
    return 0;
}
