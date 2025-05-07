// Simple Hello World program
#include <iostream>

import mymath;
import hello;
import hermath;

int main() {
	std::cout << helloWorld::hello() << " 2 + 3 is " << mymath::add(2, 3)  << " What $20,000 Looks like to your girlfriend " << girlmath::girlfriend(20000) << '\n';
	return 0;
}
