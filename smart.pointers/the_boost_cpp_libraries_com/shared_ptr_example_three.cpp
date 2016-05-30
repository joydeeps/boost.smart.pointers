// Using boost::make_shared
//
#include <boost/make_shared.hpp>
#include <typeinfo>
#include <iostream>

int main()
{
    auto p1 = boost::make_shared<int>(1);
    std::cout << typeid(p1).name() << std::endl;

    auto p2 = boost::make_shared<int[]>(10);
    std::cout << typeid(p2).name() << std::endl;
}

// With boost::make_shared() you can create a smart pointer of type
// boost::shared_ptr without having to call the constructor of boost::shared_ptr
// yourself.
//
//
