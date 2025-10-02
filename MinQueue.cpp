//=========================================
// Joel Singh & Colin Nguyen
// September 2025
// MinQueue.cpp
// This file contains all the method
// definitions for the MinQueue class
//=========================================

#include "MinQueue.h"
#include <cassert>
#include <iostream>
#include <stdlib.h>
using namespace std;

//=========================================
// Empty Constructor
// Initializes a list the ability to hold
// ten items but has nothing in it.
//=========================================
template <typename T> MinQueue<T>::MinQueue(void) {
  size = 0;
  list = new T[size];
}

//=========================================
// Destructor
// This deletes the dynamically-allocated
// memory that it created for this function
// to prevent memory leaks
//=========================================
template <typename T> MinQueue<T>::~MinQueue(void) { delete[] list; }

//=========================================
// to_string
// Returns a string representation of the MinQueue
//
// RETURN VALUE:
// string
//=========================================
template <typename T> string MinQueue<T>::to_string(void) const {

  stringstream s;

  for (int i = 0; i < size - 1; i++) {
    s << list[i] << " ";
  }
  if (size != 0) {
    s << list[size - 1];
  }
  return s.str();
}

//=================================================
// constructor from existing array
// Constructs a MinQueue from an existing array
//
// PARAMETERS:
//  A: The array to copy from
//  n: The size of `A`
//=================================================
template <typename T> MinQueue<T>::MinQueue(T *A, int n) {
  list = new T[n];
  size = n;

  for (int i = 0; i < n; i++) {
    list[i] = A[i];
  }
  build_heap();
}

//=========================================
// operator[]
// This accesses and returns a value at a
// specified position. Valid indices are 0
// to `size`-1. Invalid indices generate a
// run-time error and end the program.
//
// PARAMETERS:
// a specified position
//
// RETURN VALUE:
// the value at the specified position
//=========================================
template <typename T> T &MinQueue<T>::operator[](int position) {
  if (position < size && position >= 0) {
    return list[position];
  } else {
    throw runtime_error("Invalid index\n");
  }
}

//=================================================
// min
// Returns the minimum
//
// RETURN VALUE:
//  the minimum T
//=================================================
template <typename T> T MinQueue<T>::min() {
  if (size == 0) {
    throw runtime_error("Priority Queue is empty\n");
  } else {
    return list[0];
  }
}

//=================================================
// extract_min
// Returns and removes the minimum
//
// RETURN VALUE:
//  the minimum T
//=================================================
template <typename T> T MinQueue<T>::extract_min() {
  if (size == 0) {
    throw runtime_error("Priority Queue is empty\n");
  } else {
    T minimum = min();
    list[0] = list[size - 1];
    size--;
    min_heapify(0);
    return minimum;
  }
}

//=================================================
// decrease
// Sets the element at index `i` to `k` with the assumption `k` is less than the
// element at `i`
//
// PARAMETERS:
//  i: The index to decrease
//  k: What to decrease it to
//=================================================
template <typename T> void MinQueue<T>::decrease_key(int i, T k) {
  if (k >= list[i]) {
    throw runtime_error("New key must be smaller than current key\n");
  }

  list[i] = k;
  while (i > 0 && (list[parent(i)] > list[i])) {
    swap(parent(i), i);
    i = parent(i);
  }
}

//=================================================
// min_heapify
// precondition: The left and right are subtrees
// postcondition: the subheap at `i` will be a minheap
//
// PARAMETERS:
// i: The index of a parent where the left and right are subtrees
//=================================================
template <typename T> void MinQueue<T>::min_heapify(int i) {
  int l = left(i);
  int r = right(i);
  int smallest;

  if (l < size && list[l] < list[i]) {
    smallest = l;
  } else {
    smallest = i;
  }

  if (r < size && list[r] < list[smallest]) {
    smallest = r;
  }

  if (smallest != i) {
    swap(i, smallest);
    min_heapify(smallest);
  }
}

//=================================================
// left
// Returns the index of the left node for `i`
//
// PARAMETERS:
//  i: The node to get the left for
//
// RETURN VALUE:
//  The left child's node index
//=================================================
template <typename T> int MinQueue<T>::left(int i) { return 2 * i + 1; }

//=================================================
// right
// Returns the index of the right node for `i`
//
// PARAMETERS:
//  i: The node to get the right for
//
// RETURN VALUE:
//  The right child's node index
//=================================================
template <typename T> int MinQueue<T>::right(int i) { return 2 * i + 2; }

//=================================================
// swap
// Swaps the values of two nodes at `i` and `k`
//
// PARAMETERS:
//  i: Node being swapped
//  k: Node being swapped
//=================================================
template <typename T> void MinQueue<T>::swap(int i, int k) {
  int copy;

  copy = list[i];
  list[i] = list[k];
  list[k] = copy;
}

//=================================================
// build_heap
// Arranges the member array, `list`, into a min_heap
//=================================================
template <typename T> void MinQueue<T>::build_heap() {
  for (int i = (size / 2) - 1; i >= 0; i--) {
    min_heapify(i);
  }
}

//=================================================
// sort
// Puts a sorted array consisting of the private member array's elements into A
//
// PARAMETERS:
//  A: The array to put the sorted elements into
//=================================================
template <typename T> void sort(T *A) {}

//=================================================
// set
// Set the element at `i` to `k`
//
// PARAMETERS:
//  i: the index
//  k: the new value
//=================================================
template <typename T> void MinQueue<T>::set(int i, T k) {
  assert(i >= 0);
  assert(i < size);

  if (i >= size) {
    allocate(i + 1);
  }

  list[i] = k;
}

//=================================================
// allocate
// Ensures the list is of atleast size n.
//
// PARAMETERS:
//  n: The minimum needed size
//=================================================
template <typename T> void MinQueue<T>::allocate(int n) {
  if (this->size < n) {
    this->size = n;

    T *newList = new T[this->size];
    for (int i = 0; i < n; i++) {
      newList[i] = list[i];
    }
    delete list;
    list = newList;
  }
}

//=================================================
// parent
//=================================================
template <typename T> int MinQueue<T>::parent(int i) {
  assert(i != 0);
  int parent = (i - 1) / 2;
  return parent;
}
