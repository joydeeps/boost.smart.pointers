#include <boost/scoped_ptr.hpp>
#include <iostream>
#include <cstdlib>

struct Shoe
{
    ~Shoe()
    {
        std::cout << "Buckle my shoe" << std::endl;
    }
};

class MyClass
{
        boost::scoped_ptr<int> ptr;

    public:

        MyClass() : ptr(new int)
        {  
            *ptr = 10;
        }

        int add_one()
        {
            return ++(*ptr);
        }
};

int main(int argc, char** argv)
{
    boost::scoped_ptr<Shoe> x(new Shoe);

    MyClass my_instance;

    std::cout << my_instance.add_one() << std::endl;
    std::cout << my_instance.add_one() << std::endl;

    return EXIT_SUCCESS;
}

