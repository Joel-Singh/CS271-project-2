//=========================================
// Joel Singh & Colin Nguyen
// September 2025
// MinQueue.h
// This file contains all the method
// declarations for the MinQueue class
//=========================================

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>

#ifndef MINQUEUE_H
#define MINQUEUE_H

using namespace std;

template <class T> class MinQueue {
public:
  MinQueue();
  ~MinQueue();
  MinQueue(T *A, int n);
  void insert(const T &item);
  T min();
  T extract_min();
  void decrease(int i, T k);
  void min_heapify(int i);
  void build_heap();
  void sort(T *A);
  string to_string();

private:
  T* list();
  int capacity;
  int DEFAULT_LIST_SIZE;
};

#include "MinQueue.cpp"

#endif
