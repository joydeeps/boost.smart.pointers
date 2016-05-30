#include  "scoped_ptr_example.hpp"
#include <iostream>

class example::implementation
{
    public: 
        ~implementation() 
        {
            std::cout << "destroying implementation" << std::endl;
        }
};

example::example() : _imp(new implementation) {}

void example::do_something()
{
    std::cout << "did something" << std::endl;
}

example::~example() {}
