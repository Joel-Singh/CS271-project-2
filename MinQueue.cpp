//=========================================
// Joel Singh & Colin Nguyen
// September 2025
// MinQueue.cpp
// This file contains all the method
// definitions for the MinQueue class
//=========================================

#include <iostream>
#include <stdlib.h>
using namespace std;


//=========================================
// Constructor
// Initializes a list the ability to hold 
// ten items but has nothing in it. 
// PARAMETERS:
// none
// RETURN VALUE:
// none
//=========================================
template <typename T>
        MinQueue<T>::MinQueue       ( void ) {
    size = 0;
	capacity = DEFAULT_LIST_SIZE;
	list = new T[capacity];
}

//=========================================
// destructor
//=========================================
// template <typename T>
//         MinQueue<T>::~MinQueue      ( void ) {
            
//         }

//=========================================
// to_string
//=========================================
template <typename T>
std::string 	MinQueue<T>::to_string	( void ) const {
    
	std::stringstream s;

    for (int i = 0; i < size; i++) {
        s << " " << list[i];
    }

    return s.str();
}
