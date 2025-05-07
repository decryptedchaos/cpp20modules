module;
// Put ALL #includes here:
#include <string>
#include <iostream>
#include <vector>

export module hello;  // Module declaration


export namespace helloWorld {
   std::string hello() {
   		std::string hstring = "Hello";
   		return hstring;
   }
}
