// ************************************
//  test_minqueue_example.cpp
//  CS 271
//  Project 2
//
// ************************************
#include "MinQueue.h"
#include "test.cpp"
#include "test_minqueue_times.cpp"
#include <iostream>
#include <stdexcept>

using namespace std;

void test_minqueue() {

  int *int_data = new int[10];
  for (int i = 0; i < 10; i++) {
    int_data[i] = 10 - i;
  }

  try {

    MinQueue<int> empty;
    test("Empty minqueue is empty", empty, "");

    MinQueue<int> mq(int_data, 10);

    test("Minqueue is heap on constructor", mq, "1 2 4 3 6 5 8 10 7 9");
  } catch (exception &e) {
    cerr << "Error creating the priority queue : " << e.what() << endl;
  }

  delete[] int_data;
}

void test_insert() {

  int *int_data = new int[10];
  for (int i = 0; i < 10; i++) {
    int_data[i] = 10 - i;
  }

  try {
    {
      MinQueue<int> mq;
      mq.insert(0);
      test("Insert single element", mq, "0");
    }

    {
      MinQueue<int> mq(int_data, 10);

      mq.insert(0);
      test("Insert one element into len 10 mq", mq, "0 1 4 3 2 5 8 10 7 9 6");
    }

    {
      MinQueue<int> mq(int_data, 10);
      mq.insert(25);
      mq.insert(0);
      test("Insert two elements into len 10 mq", mq,
           "0 2 1 3 6 4 8 10 7 9 25 5");
    }
  } catch (exception &e) {
    cerr << "Error inserting into the priority queue : " << e.what() << endl;
  }

  delete[] int_data;
}

void test_min() {

  int *int_data = new int[10];
  for (int i = 0; i < 10; i++) {
    int_data[i] = 10 - i;
  }

  try {
    MinQueue<int> empty;
    int min = empty.min();
    string mq_str = empty.to_string();
    cout << "Incorrectly returned min from empty queue: " << min << endl;
  } catch (exception &e) {
    // expect an underflow error
    cout << "Correctly caught error trying to get min from empty queue: "
         << e.what() << endl;
  }

  try {
    MinQueue<int> mq(int_data, 10);
    int min = mq.min();
    test("Calling min on minQueue", min, "1");
  } catch (exception &e) {
    cerr << "Error in determining min of the priority queue : " << e.what()
         << endl;
  }

  delete[] int_data;
}

void test_extract_min() {

  int *int_data = new int[10];
  for (int i = 0; i < 10; i++) {
    int_data[i] = 10 - i;
  }

  try {
    MinQueue<int> empty;
    int min = empty.extract_min();
    string mq_str = empty.to_string();
    cout << "Incorrectly extracted min from empty queue: " << min << endl;
  } catch (exception &e) {
    // expect an underflow error
    cout << "Correctly caught error trying to extract min from empty"
         << " queue: " << e.what() << endl;
  }
  try {
    MinQueue<int> mq(int_data, 10);
    int min = mq.extract_min();

    test("Correct min extracted", min, "1");
    test("Is heap after min extraction", mq, "2 3 4 7 6 5 8 10 9");
  } catch (exception &e) {
    cerr << "Error in determining min of the priority queue : " << e.what()
         << endl;
  }

  delete[] int_data;
}

void test_decrease_key() {
  int *int_data = new int[10];
  for (int i = 0; i < 10; i++) {
    int_data[i] = 10 - i;
  }

  try {
    {
      MinQueue<int> mq(int_data, 1);
      mq.decrease_key(0, -6);
      test("Decrease key on MinQueue", mq, "-6");
    }

    {
      MinQueue<int> mq(int_data, 2);
      mq.decrease_key(0, -6);
      test("Decrease key on MinQueue", mq, "-6 10");
    }

    {
      MinQueue<int> mq(int_data, 3);
      mq.decrease_key(0, -6);
      test("Decrease key on MinQueue", mq, "-6 9 10");
    }

    {
      MinQueue<int> mq(int_data, 10);
      mq.decrease_key(0, -6);
      mq.decrease_key(9, -1);
      test("Decrease key on MinQueue", mq, "-6 -1 4 3 2 5 8 10 7 6");
    }
  } catch (exception &e) {
    cerr << "Error in decreasing key : " << e.what() << endl;
  }

  delete[] int_data;
}

void test_heapify() {

  int *empty_data = new int[0];

  int *int_data = new int[10];
  for (int i = 0; i < 10; i++) {
    int_data[i] = 10 - i;
  }

  try {

    {
      MinQueue<int> mq;
      mq.min_heapify(1);

      test("Heapify on empty MinQueue", mq, "");
    }

    {
      int *data = new int[1];
      data[0] = 5;
      MinQueue<int> mq(data, 1);
      mq.min_heapify(1);
      test("Heapify on single element MinQueue", mq, "5");
    }

    {
      int *data = new int[2];
      data[0] = 0;
      data[1] = 3;
      MinQueue<int> mq(data, 2);
      mq.min_heapify(2);
      test("Heapify on two elements MinQueue already in a heap", mq, "0 3");
    }

    {
      int *data = new int[2];
      data[0] = 2;
      data[1] = 1;
      MinQueue<int> mq(data, 2);
      mq.min_heapify(0);
      test("Heapify on two elements MinQueue not already in a heap", mq, "1 2");
    }

    {
      int count = 3;
      int *data = new int[count];
      data[0] = 2;
      data[1] = 1;
      data[2] = 0;
      MinQueue<int> mq(data, count);
      mq.min_heapify(0);
      test("Heapify on three elements MinQueue not already in a heap", mq,
           "0 1 2");
    }

    {
      int count = 4;
      int *data = new int[count];
      data[0] = 2;
      data[1] = 0;
      data[2] = 1;
      data[3] = 0;
      MinQueue<int> mq(data, count);
      mq.min_heapify(0);
      test("Heapify on three elements MinQueue not already in a heap", mq,
           "0 0 1 2");
    }

    {
      MinQueue<int> mq(int_data, 10);

      mq.set(1, 11);

      mq.min_heapify(1);

      test("Heapify on non-empty MinQueue", mq, "1 3 4 7 6 5 8 10 11 9");
    }
  } catch (exception &e) {
    cerr << "Error in heapify : " << e.what() << endl;
  }

  delete[] empty_data;
  delete[] int_data;
}

void test_build_min_heap() {

  int *int_data = new int[10];
  for (int i = 0; i < 10; i++) {
    int_data[i] = 10 - i;
  }

  {
    MinQueue<int> mq;
    mq.build_heap();
    test("Build heap on empty MinQueue ", mq, "");
  }

  {
    MinQueue<int> mq;
    int size = 1;
    mq.allocate(size);
    for (int i = 0; i < size; i++) {
      mq.set(i, int_data[i]);
    }
    mq.build_heap();
    test("Build heap on single element MinQueue ", mq, "10");
  }

  {
    MinQueue<int> mq;
    int size = 2;
    mq.allocate(size);
    for (int i = 0; i < size; i++) {
      mq.set(i, int_data[i]);
    }
    mq.build_heap();
    test("Build heap on two element MinQueue ", mq, "9 10");
  }

  {

    MinQueue<int> mq;
    int size = 10;
    mq.allocate(size);
    for (int i = 0; i < size; i++) {
      mq.set(i, int_data[i]);
    }
    mq.build_heap();

    test("Building a heap on MinQueue", mq, "1 2 4 3 6 5 8 10 7 9");
  }

  delete[] int_data;
}

void test_heapsort() {

  try {

    {
      int *empty_data = new int[0];

      MinQueue<int> empty;
      empty.sort(empty_data);
      test("Empty sorted heap stays empty", empty, "");

      delete[] empty_data;
    }

    {
      const int LENGTH = 10;
      int *int_data = new int[LENGTH];
      for (int i = 0; i < LENGTH; i++) {
        int_data[i] = LENGTH - i;
      }

      MinQueue<int> heap(int_data, LENGTH);
      heap.sort(int_data);

      test("Heap sort on len 10 mq", array_to_string(int_data, LENGTH),
           "1 2 3 4 5 6 7 8 9 10");

      delete[] int_data;
    }

    {
      const int LENGTH = 10;
      int *int_data = new int[LENGTH];
      int_data[0] = 2;
      int_data[1] = 5;
      int_data[2] = 4;
      int_data[3] = 8;
      int_data[4] = 6;
      int_data[5] = 10;
      int_data[6] = 7;
      int_data[7] = 17;
      int_data[8] = 12;
      int_data[9] = 9;

      MinQueue<int> heap(int_data, LENGTH);
      heap.sort(int_data);

      test("Heap sort on len 10 mq", array_to_string(int_data, LENGTH),
           "2 4 5 6 7 8 9 10 12 17");

      delete[] int_data;
    }

  } catch (exception &e) {
    cerr << "Error in sorting : " << e.what() << endl;
  }
}

// use an enum to represent class year
enum Year { SR, JR, SO, FR };

// define a struct representing a student record
struct StudentRecord {
  string name;
  Year year;
  // set registration time to the current time when the student record is
  // created
  std::chrono::system_clock::time_point registration_time =
      std::chrono::system_clock::now();

  // overload < operator to compare students based on year and registration time
  bool operator<(const StudentRecord &other) const {
    return (year < other.year) ||
           (year == other.year && registration_time < other.registration_time);
  }

  // overload > operator to compare students based on year and registration time
  bool operator>(const StudentRecord &other) const {
    return (year > other.year) ||
           (year == other.year && registration_time > other.registration_time);
  }

  // overload == operator to compare students based on year and registration
  // time
  bool operator==(const StudentRecord &other) const {
    return (year == other.year && registration_time == other.registration_time);
  }

  // overload != operator to compare students based on year and registration
  // time
  bool operator!=(const StudentRecord &other) const {
    return (year != other.year || registration_time != other.registration_time);
  }

  // overload <= operator to compare students based on year and registration
  // time
  bool operator<=(const StudentRecord &other) const {
    return (year < other.year) ||
           (year == other.year && registration_time <= other.registration_time);
  }

  // overload >= operator to compare students based on year and registration
  // time
  bool operator>=(const StudentRecord &other) const {
    return (year > other.year) ||
           (year == other.year && registration_time >= other.registration_time);
  }

  // overload << operator to print student record
  friend ostream &operator<<(ostream &os, const StudentRecord &student) {
    string year_str;
    switch (student.year) {
    case SR:
      year_str = "Senior";
      break;
    case JR:
      year_str = "Junior";
      break;
    case SO:
      year_str = "Sophomore";
      break;
    case FR:
      year_str = "Freshman";
      break;
    default:
      year_str = "Unknown";
      break;
    }
    os << student.name << " (" << year_str << ")";
    return os;
  }
};

void test_application_waitlist() {
  // create a minqueue of students
  MinQueue<StudentRecord> waitlist;
  waitlist.insert({"Alice", SR});
  waitlist.insert({"Bob", JR});
  waitlist.insert({"Charlie", SO});
  waitlist.insert({"David", FR});
  waitlist.insert({"Eve", SR});
  waitlist.insert({"Frank", JR});
  waitlist.insert({"Grace", SO});
  waitlist.insert({"Heidi", FR});
  waitlist.insert({"Ivan", SR});
  waitlist.insert({"Judy", JR});
  waitlist.insert({"Mallory", SO});
  waitlist.insert({"Niaj", FR});
  waitlist.insert({"Olivia", SR});
  waitlist.insert({"Peggy", JR});

  // process the waitlist and print the order in which students are registered
  cout << "Registration order:" << endl;

  stringstream s;

  StudentRecord student = waitlist.extract_min();
  s << student;
  // assume there are only 10 spots available
  for (int i = 1; i < 10; i++) {
    student = waitlist.extract_min();
    s << " " << student;
  }

  test("Waitlist extracted in right order", s.str(),
       "Alice (Senior) Eve (Senior) Ivan (Senior) Olivia (Senior) Bob (Junior) "
       "Frank (Junior) Judy (Junior) Peggy (Junior) Charlie (Sophomore) Grace "
       "(Sophomore)");
}

//

int main() {

  test_minqueue();
  test_insert();
  test_min();
  test_extract_min();
  test_decrease_key();
  test_heapify();
  test_build_min_heap();
  test_heapsort();
  //
  test_application_waitlist();

  time_test();

  cout << "Testing completed" << endl;

  return 0;
}
