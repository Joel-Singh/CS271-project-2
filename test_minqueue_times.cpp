
#include "MinQueue.h"
#include <chrono>
#include <iostream>
using namespace std;

const int MAX_INT_VALUE = 100000;

//=================================================
// Macro: TIME_TEST
// Prints the amount of time it takes to do `call`
//
// PARAMETERS:
//  call: The code to test
//  description: Description to print out with the time
//=================================================
#define TIME_TEST(call, description)                                           \
  auto begin = chrono::high_resolution_clock::now();                           \
                                                                               \
  call;                                                                        \
                                                                               \
  auto end = chrono::high_resolution_clock::now();                             \
  auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);      \
  cout << description << " took " << elapsed.count() << " nanoseconds" << endl;

MinQueue<int> create_unheaped_minqueue(int n);

void time_test() {
  cout << "===================" << endl;
  cout << "Starting Time Tests" << endl;
  cout << "===================" << endl;
  int input_sizes[6] = {1, 10, 100, 1000, 10000, 100000};

  // min
  for (int input_size : input_sizes) {
    MinQueue<int> mq = create_unheaped_minqueue(input_size);
    mq.build_heap();
    TIME_TEST((mq.min()), "mq.min of input size " + to_string(input_size))
  }

  // insert
  for (int input_size : input_sizes) {
    MinQueue<int> mq = create_unheaped_minqueue(input_size);
    mq.build_heap();

    TIME_TEST((mq.insert(rand() % MAX_INT_VALUE)),
              "mq.insert of input size " + to_string(input_size))
  }

  // extract_min
  for (int input_size : input_sizes) {
    MinQueue<int> mq = create_unheaped_minqueue(input_size);
    mq.build_heap();

    TIME_TEST((mq.extract_min()),
              "mq.extract_min of input size " + to_string(input_size))
  }

  // decrease_key
  for (int input_size : input_sizes) {
    MinQueue<int> mq = create_unheaped_minqueue(input_size);
    mq.build_heap();

    int last_index = input_size - 1;
    int new_val = mq.min() - 1; // ensure we're decreasing the key

    TIME_TEST((mq.decrease_key(last_index, new_val)),
              "mq.decrease_key of input size " + to_string(input_size))
  }

  // min_heapify
  for (int input_size : input_sizes) {
    MinQueue<int> mq = create_unheaped_minqueue(input_size);
    mq.build_heap();

    mq.set(0, MAX_INT_VALUE);

    TIME_TEST((mq.min_heapify(0)),
              "mq.min_heapify of input size " + to_string(input_size))
  }
}

//=================================================
// create_unheaped_minqueue
// Creates a MinQueue<int> of size `n` not heapified with random values from 1
// to 100,000 using set and allocate.
//
// PARAMETERS:
//  n: the desired size
//
// RETURN VALUE:
//  MinQueue of size `n`
//=================================================
MinQueue<int> create_unheaped_minqueue(int n) {
  MinQueue<int> mq;
  mq.allocate(n);
  for (int i = 0; i < n; i++) {
    int random = rand() % MAX_INT_VALUE;
    mq.set(i, random);
  }

  return mq;
}
