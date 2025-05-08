// Simple Hello World program

//in C++20 we still include system headers in every file that needs them C++23 lets you import system headers like you do modules but brings its own
// set of issues to deal with
#include <iostream>

import mymath;
import hello;
import hermath;
import holyshit;

int main() {
	std::cout << helloWorld::hello()
			  << "\n2 + 3 = " << mymath::add(2, 3)
			  <<  "\nWhat $20,000 Looks like to your girlfriend " << girlmath::girlfriend(20000)
			  << "\n5 + 1 = " << wellshit::plusOne(5)
			  << "\n5 - 1 = " << toInfinity::minusOne(5) << '\n';
	return 0;
}
