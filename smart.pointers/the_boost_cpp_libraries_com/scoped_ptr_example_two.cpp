// boost::scoped_ptr is a smart pointer that is the sole owner of a dynamically
// alocated object.
// boost::scoped_ptr cannot be moved or copied. 

#include <boost/scoped_ptr.hpp>
#include <iostream>

int main(int argc, char** argv)
{
    boost::scoped_ptr<int> p(new int(1));
    std::cout << *p << std::endl;

    p.reset(new int(2));
    std::cout << *p.get() << std::endl;

    p.reset();
    //std::cout << std::boolalpha << static_cast<bool>(p) << std::endl;
    std::cout << static_cast<bool>(p) << std::endl;
}

// A smart pointer of type boost::scoped_ptr can't transfer ownership of an
// object. Once initialized with an address, the dynamically allocated object is
// released when the destructor is executed or when the member function reset is
// called.
//
// The above example uses a smart pointer "p" with type boost::scoped_ptr<int>.
// "p" is initialized with a pointer to a dynamically allocated object that
// stores the number 1. Via operator*() function "p" is dereferenced and 1 is
// written to the standard output.
//
// With reset() a new address of the object can be stored in the smart pointer.
// That way the example passes the address of a newly allocated int object
// containing number 2 to "p". With the call to reset(), the currently
// referenced object in "p" is automatically destroyed.
//
// get() returns the address of the object anchored in the smart pointer. The
// example dereferences the address returned by get() to write 2 to standard
// output.
//
// The destructor of the boost::scoped_ptr releases the referenced object with
// delete. That's why boost::scoped_ptr must not be initialized with the address
// of a dynamically allocated array, which would have to be relaeased with
// delete[].
//
// For arrays, Boost.SmartPointers provides the class boost:;scoped_array.
