// boost::weak_ptr only makes sense if used in conjunction with
// boost::shared_ptr.
//
// Using boost::weak_ptr

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <thread>
#include <functional>
#include <iostream>
#include <chrono>

void reset(boost::shared_ptr<int> &sh)
{
	sh.reset();
}

void print(boost::weak_ptr<int> &w)
{
	boost::shared_ptr<int> sh = w.lock();
	//std::this_thread::sleep_for(std::chrono::seconds(2));
	if (sh)
		std::cout << *sh << "\n";
}

int main()
{
  boost::shared_ptr<int> sh(new int(99));
	boost::weak_ptr<int> w(sh);

	std::thread t1(reset, std::ref(sh));
	std::thread t2(print, std::ref(w));

	t1.join();
	t2.join();
}

/*
 * boost::weak_ptr must be initialized with boost::shared_ptr.
 * 
 * It's most important member function is lock(). lock() returns a 
 * boost::shared_ptr that shares ownership with the shared pointer used to 
 * initialize the weak pointer. 
 *
 * In case, the shared_pointer is empty, the returned pointer will be empty as 
 * well.
 *
 * boost::weak_ptr makes sense whenever a function is expected to work with an
 * object managed by a shared_pointer, but the lifetime of the object does not
 * depend on the function itself. The function can only use the object as long as
 * it is owned by atleast one shared pointer somewhere else in the program. In 
 * case the shared pointer is reset, the object cannot be kept alive because of 
 * an additional shared pointer inside the corresponding function.
 *
 * The above program creates two threads in main(). The first thread executes the 
 * function reset(), which receives a reference to a shared pointer. The second 
 * thread executes the function print(), which receives a reference to a weak 
 * pointer. This weak pointer has been previously initialized with the shared 
 * pointer.
 *
 * Once the program is launched, both reset() and print() are executed at the 
 * same time. However, the order of execution cannot be predicted. This leads to 
 * the potential problem of reset() destroying the object while it is being 
 * accessed by print().
 *
 * The weak pointer solves this issue as follows: invoking lock() returns a 
 * shared pointer that points to a valid object if one exists at the time of the 
 * call. If not, the shared pointer is set to 0 and is equivalent to a null 
 * pointer.
 *
 * boost::weak_ptr itself does not have any impact on the lifetime of an object. 
 * To safely access the object within the print() function, lock() returns a 
 * boost::shared_ptr. This guarantees that even if a different thread attempts to
 * release the object, it will continue to exist thanks to the returned shared 
 * pointer.
 * 
 */
