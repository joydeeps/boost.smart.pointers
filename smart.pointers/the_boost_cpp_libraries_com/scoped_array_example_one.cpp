// using boost::scoped_array
//

#include <boost/scoped_array.hpp>

int main(int argc, char** argv)
{
    boost::scoped_array<int> p(new int[2]);
    *p.get() = 1;
    p[1] = 2;
    p.reset(new int[3]);

    return EXIT_SUCCESS;
}

// The smart pointer boost::scoped_array is used like boost::scoped_ptr. The
// crucial difference is that the destructor of boosT::scoped_array uses the
// operator delete[] to release the contained object.
// 
//
