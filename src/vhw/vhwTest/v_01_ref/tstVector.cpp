// to compile the program
// $ gcc tstVector.c -o tstVector.o

// note: use 'c++98'
// note: use 'gnu++98'
// note: use 'c++11'
// note: use 'gnu++11'
// note: use 'c++14'
// note: use 'gnu++14'
// note: use 'c++17'
// note: use 'gnu++17'
// note: use 'c++20'
// note: use 'gnu++20'
// note: use 'c++2b'
// note: use 'gnu++2b'

// // C++ program to demonstrate
// // array of string using STL array
// #include <array>
// #include <iostream>
// #include <string>
// 
// using namespace std;
// 
// // Driver code
// int main()
// {
//     // Initialize array
//     array<string, 4> colour{ "Blue", "Red", "Orange",
//                              "Yellow" };
// 
//     // Printing Strings stored in array
//     for (int i = 0; i < 4; i++)
//         cout << colour[i] << "\n";
// 
//     return 0;
// }

// // C++ code to demonstrate working of array,
// // at() and get()
// #include<iostream>
// #include<array> // for array, at()
// #include<tuple> // for get()
// using namespace std;
// int main()
// {
// 	// Initializing the array elements
// 	array<int,6> ar = {1, 2, 3, 4, 5, 6};
// 
// 	// Printing array elements using at()
// 	cout << "The array elements are (using at()) : ";
// 	for ( int i=0; i<6; i++)
// 	cout << ar.at(i) << " ";
// 	cout << endl;
// 
// 	// Printing array elements using get()
// 	cout << "The array elements are (using get()) : ";
// 	cout << get<0>(ar) << " " << get<1>(ar) << " ";
// 	cout << get<2>(ar) << " " << get<3>(ar) << " ";
// 	cout << get<4>(ar) << " " << get<5>(ar) << " ";
// 	cout << endl;
// 
// 	// Printing array elements using operator[]
// 	cout << "The array elements are (using operator[]) : ";
// 	for ( int i=0; i<6; i++)
// 	cout << ar[i] << " ";
// 	cout << endl;
// 
// 	return 0;
// 
// }
// 

// // ************
// 
// #include <algorithm>
// #include <array>
// #include <iostream>
// #include <iterator>
// #include <string>
//  
// int main()
// {
//     // construction uses aggregate initialization
//     std::array<int, 3> a1{{1, 2, 3}};  // double-braces required in C++11 prior to
//                                        // the CWG 1270 revision (not needed in C++11
//                                        // after the revision and in C++14 and beyond)
//  
//     std::array<int, 3> a2 = {1, 2, 3}; // double braces never required after =
//  
//     std::array<std::string, 2> a3 = { std::string("E"), "\u018E" };
//  
//     // container operations are supported
//     std::sort(a1.begin(), a1.end());
//     //std::ranges::reverse_copy(a2, std::ostream_iterator<int>(std::cout, " "));
//     std::cout << '\n';
//  
//     // ranged for loop is supported
//     for (const auto& s: a3)
//         std::cout << s << ' ';
//  
//     // deduction guide for array creation (since C++17)
//     [[maybe_unused]] std::array a4{3.0, 1.0, 4.0}; // std::array<double, 3>
//  
//     // Corner cases:
//     [[maybe_unused]] std::array<int, 2> a5; // a5[0] and a5[1] are default initialized
//     [[maybe_unused]] std::array<int, 2> a6 = {}; // a6[0] and a6[1] are 0
//     [[maybe_unused]] std::array<int, 2> a7 = {1}; // a7[0] == 1, a7[1] == 0
// }
// 
// 
// 


#include <algorithm>
#include <iostream>
#include <list>

int main()
{
    // Create a list containing integers
    std::list<int> l = {7, 5, 16, 8};
 
    // Add an integer to the front of the list
    l.push_front(25);
    // Add an integer to the back of the list
    l.push_back(13);
 
    // Insert an integer before 16 by searching
    auto it = std::find(l.begin(), l.end(), 16);
    if (it != l.end())
        l.insert(it, 42);
 
    // Print out the list
    std::cout << "l = { ";
    for (int n : l)
        std::cout << n << ", ";
    std::cout << "};\n";
}


// // ***************
// 
// #include <iostream>
// #include <vector>
//  
// int main()
// {
//     // Create a vector containing integers
//     std::vector<int> v = {7, 5, 16, 8};
//  
//     // Add two more integers to vector
//     v.push_back(25);
//     v.push_back(13);
//  
//     // Print out the vector
//     std::cout << "v = { ";
//     for (int n : v)
//         std::cout << n << ", ";
//     std::cout << "}; \n";
// }
// 
// 