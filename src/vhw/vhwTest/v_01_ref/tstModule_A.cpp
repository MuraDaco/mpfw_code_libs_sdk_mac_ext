// helloworld.cpp
export module helloworld; // module declaration
 
#include <iostream>        // import declaration
 
export void hello()       // export declaration
{
    std::cout << "Hello world!\n";
}