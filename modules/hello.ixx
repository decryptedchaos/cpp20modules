// There does not seem to be a set place where to put this module; section,  some put it here some put it under the export module
// The key point to understand is this is required in modules that use #include for normal headers.
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
