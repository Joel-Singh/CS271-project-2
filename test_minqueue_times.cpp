
#include "MinQueue.h"
#include <chrono>
#include <iostream>
using namespace std;

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
  int input_sizes[5] = {1, 10, 100, 1000, 10000};

  // min
  for (int input_size : input_sizes) {
    MinQueue<int> mq = create_unheaped_minqueue(input_size);
    mq.build_heap();
    TIME_TEST((mq.min()), "mq.min of input size " + to_string(input_size))
  }

  // MinQueue<int> mq;
  // // TO-DO: generate large minqueue
  // int size = -1; // TO-DO: set size of large minqueue
  // int total = 0;
  //
  // int val = rand() % 100000;
  // auto begin = std::chrono::high_resolution_clock::now();
  //
  // mq.insert(val);
  //
  // auto end = std::chrono::high_resolution_clock::now();
  // auto elapsed =
  //     std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  // cout << "insert time test took " << elapsed.count() << " nanoseconds" <<
  // endl; total += elapsed.count();
  //
  // begin = std::chrono::high_resolution_clock::now();
  // _ = mq.extract_min();
  // end = std::chrono::high_resolution_clock::now();
  // elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end -
  // begin); cout << "extract min time test took " << elapsed.count() << "
  // nanoseconds "
  //      << endl;
  // total += elapsed.count();
  //
  // int last_index = size - 1;  // indexing starts at 0
  // int new_val = mq.min() - 1; // ensure we're decreasing the key
  // begin = std::chrono::high_resolution_clock::now();
  //
  // mq.decrease_key(last_index, new_val);
  //
  // end = std::chrono::high_resolution_clock::now();
  // elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end -
  // begin); cout << "decrease key time test took " << elapsed.count() << "
  // nanoseconds "
  //      << endl;
  // total += elapsed.count();
  // cout << " Total time : " << total << endl;
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
    int random = rand() % 100000;
    mq.set(i, random);
  }

  return mq;
}
