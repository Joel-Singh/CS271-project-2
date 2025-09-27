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

template <class T> class MinQueue {
public:
  MinQueue();
  ~MinQueue();
  MinQueue(T *A, int n);
  void insert(const T &item);
  T min();
  T extract_min();
  void decrease(int i, T k);
};

#include "MinQueue.cpp"

#endif
