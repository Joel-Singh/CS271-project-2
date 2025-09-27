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