// tstModule_A.cpp
export module tstModule_A; // module declaration
 
#include <iostream>        // import declaration
 
export void hello()       // export declaration
{
    std::cout << "Hello world!\n";
}