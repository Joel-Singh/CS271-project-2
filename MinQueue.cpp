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
        MinQueue<T>::MinQueue       ( void ) 
{
    size = 0;
	capacity = DEFAULT_LIST_SIZE;
	list = new T[capacity];
}

//=========================================
// destructor
// This deletes the dynamically-allocated 
// memory that it created for this function 
// to prevent memory leaks
// PARAMETERS:
// none
// RETURN VALUE:
// none
//=========================================
template <typename T>
        MinQueue<T>::~MinQueue      ( void ) 
{
    
    delete []list;
}

//=========================================
// to_string
// This converts our output to a string
// PARAMETERS:
// none
// RETURN VALUE:
// a string s
//=========================================
template <typename T>
std::string 	MinQueue<T>::to_string	( void ) const 
{
    
	std::stringstream s;

    for (int i = 0; i < size; i++) {
        s << " " << list[i];
    }

    return s.str();
}

//=========================================
// MinQueue
//=========================================
template <typename T>
        MinQueue<T>::MinQueue           ( T* A, int n ) 
{
    list = new T[DEFAULT_LIST_SIZE];
    size = n;
    // if (n > DEFAULT_LIST_SIZE) {

    // }
    for (int i = 0; i < n; i++) {
        list[i] = A[i];
    }
}

//=========================================

//=========================================
// operator[]
// This accesses and returns a value at a 
// specified position. Valid indices are 0 
// to size-1. Invalid indices generate a 
// run-time error and end the program. 
// PARAMETERS:
// a specified position
// RETURN VALUE:
// the value at the specified position
//=========================================
template <typename T>
T &     	MinQueue<T>::operator[]  	( int position )
{
	if ( position < size && position >= 0 ) {
		return list[position];
	} else {
		throw runtime_error("Invalid index\n");
	}
}