// ************************************
//  test_minqueue_example.cpp
//  CS 271
//  Project 2
//
// ************************************
#include "MinQueue.h"
#include <chrono>
#include <iostream>
#include <stdexcept>

using namespace std;

void test_minqueue()
{

    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try
    {

        MinQueue<int> empty;
        string mq_str = empty.to_string();

        if (mq_str != "")
        {
            cout << "Incorrect result from empty constructor. Expected an" <<
            "empty string but got : " << mq_str << endl;
        }

        MinQueue<int> mq(int_data, 10);
        mq_str = mq.to_string();

        if (mq_str != "1 2 4 3 6 5 8 10 7 9")
        {
            cout << "Incorrect result from empty constructor. Expected 1 2 4 " << 
            "3 6 5 8 10 7 9 but got : " << mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error creating the priority queue : " << e.what() << endl;
    }

    delete[] int_data;
}
//
// void test_insert()
// {
//
//     int *int_data = new int[10];
//     for (int i = 0; i < 10; i++)
//     {
//         int_data[i] = 10 - i;
//     }
//
//     try
//     {
//
//         MinQueue<int> empty;
//         empty.insert(0);
//         string mq_str = empty.to_string();
//
//         if (mq_str != "0")
//         {
//             cout << "Incorrect insert result. Epected 0 but got : " << mq_str
//             << endl;
//         }
//
//         MinQueue<int> mq(int_data, 10);
//         mq.insert(25);
//         mq.insert(0);
//         mq_str = mq.to_string();
//
//         if (mq_str != "0 2 1 3 6 4 8 10 7 9 25 5")
//         {
//             cout << "Incorrect insert result. Expected 0 2 1 3 6 4 8 10 7 9
//             25 5 but got : " << mq_str << endl;
//         }
//     }
//     catch (exception &e)
//     {
//         cerr << "Error inserting into the priority queue : " << e.what() <<
//         endl;
//     }
//
//     delete[] int_data;
// }
//
// void test_min()
// {
//
//     int *int_data = new int[10];
//     for (int i = 0; i < 10; i++)
//     {
//         int_data[i] = 10 - i;
//     }
//
//     try{
//         MinQueue<int> empty;
//         int min = empty.min();
//         string mq_str = empty.to_string();
//         cout << "Incorrectly returned min from empty queue: " << min << endl;
//     }
//     catch (exception &e)
//     {
//         // expect an underflow error
//         cout << "Correctly caught error trying to get min from empty queue: "
//         << e.what() << endl;
//     }
//
//     try
//     {
//         MinQueue<int> mq(int_data, 10);
//         int min = mq.min();
//         if (min != 1)
//         {
//             cout << "Incorrect min result. Expect 0 but got : " << min <<
//             endl;
//         }
//     }
//     catch (exception &e)
//     {
//         cerr << "Error in determining min of the priority queue : " <<
//         e.what() << endl;
//     }
//
//     delete[] int_data;
// }
//
// void test_extract_min()
// {
//
//     int *int_data = new int[10];
//     for (int i = 0; i < 10; i++)
//     {
//         int_data[i] = 10 - i;
//     }
//
//     try{
//         MinQueue<int> empty;
//         int min = empty.extract_min();
//         string mq_str = empty.to_string();
//         cout << "Incorrectly extracted min from empty queue: " << min <<
//         endl;
//     }
//     catch (exception &e)
//     {
//         // expect an underflow error
//         cout << "Correctly caught error trying to extract min from empty
//         queue: " << e.what() << endl;
//     }
//     try
//     {
//         MinQueue<int> mq(int_data, 10);
//         int min = mq.extract_min();
//         string mq_str = mq.to_string();
//
//         if (min != 1 || mq_str != "2 3 4 7 6 5 8 10 9")
//         {
//             cout << "Incorrect extract min result. Expected 0 and the queue 2
//             3 4 7 6 5 8 10 9 but got : " << min << " and a queue of : " <<
//             mq_str << endl;
//         }
//     }
//     catch (exception &e)
//     {
//         cerr << "Error in determining min of the priority queue : " <<
//         e.what() << endl;
//     }
//
//     delete[] int_data;
// }
//
// void test_decrease_key()
// {
//
//     int *int_data = new int[10];
//     for (int i = 0; i < 10; i++)
//     {
//         int_data[i] = 10 - i;
//     }
//
//     try
//     {
//         MinQueue<int> mq(int_data, 10);
//         mq.decrease_key(0, -6);
//         mq.decrease_key(9, -1);
//         string mq_str = mq.to_string();
//
//         if (mq_str != "-6 -1 4 3 2 5 8 10 7 6")
//         {
//             cout << "Incorrect decrease key result. Expected empty queue but
//             got : " << mq_str << endl;
//         }
//     }
//     catch (exception &e)
//     {
//         cerr << "Error in decreasing key : " << e.what() << endl;
//     }
//
//     delete[] int_data;
// }
//
// void test_heapify()
// {
//
//     int *empty_data = new int[0];
//
//     int *int_data = new int[10];
//     for (int i = 0; i < 10; i++)
//     {
//         int_data[i] = 10 - i;
//     }
//
//     try
//     {
//
//         MinQueue<int> empty;
//         empty.min_heapify(1);
//         string mq_str = empty.to_string();
//
//         if (mq_str != "")
//         {
//             cout << "Incorrect heapify result. Expected empty string but got
//             : " << mq_str << endl;
//         }
//
//         MinQueue<int> mq(int_data, 10);
//         string o_mq_str = mq.to_string();
//         mq.set(1, 11);
//         mq.min_heapify(1);
//
//         mq_str = mq.to_string();
//
//         if (mq_str != "1 3 4 7 6 5 8 10 11 9")
//         {
//             cout << "Incorrect heapify result in heapifying index 1 in the
//             minqueue " << o_mq_str << " after setting to 11. Expected 1 3 4 7
//             6 5 8 10 11 9 but got : " << mq_str << endl;
//         }
//     }
//     catch (exception &e)
//     {
//         cerr << "Error in heapify : " << e.what() << endl;
//     }
//
//     delete[] empty_data;
//     delete[] int_data;
// }
//
// void test_build_min_heap()
// {
//
//     int *int_data = new int[10];
//     for (int i = 0; i < 10; i++)
//     {
//         int_data[i] = 10 - i;
//     }
//
//     try
//     {
//
//         MinQueue<int> mq;
//         mq.allocate(10);
//         for (int i = 0; i < 10; i++)
//         {
//             mq.set(i, int_data[i]);
//         }
//         string o_mq_str = mq.to_string();
//
//         mq.build_heap();
//         string mq_str = mq.to_string();
//
//         if (mq_str != "1 2 4 3 6 5 8 10 7 9")
//         {
//             cout << "Incorrect build_heap result from " << o_mq_str << ".
//             Expected 1 2 4 3 6 5 8 10 7 9 but got : " << mq_str << endl;
//         }
//     }
//     catch (exception &e)
//     {
//         cerr << "Error in building min heap : " << e.what() << endl;
//     }
//
//     delete[] int_data;
// }
//
// void test_heapsort()
// {
//
//     int *empty_data = new int[0];
//
//     int *int_data = new int[10];
//     for (int i = 0; i < 10; i++)
//     {
//         int_data[i] = 10 - i;
//     }
//
//     try
//     {
//
//         MinQueue<int> empty;
//         empty.sort(empty_data);
//
//         MinQueue<int> heap(int_data, 10);
//         heap.sort(int_data);
//
//         string sorted_str = to_string(int_data[0]);
//
//         for (int i = 1; i < 10; i++)
//         {
//             sorted_str += (" " + to_string(int_data[i]));
//         }
//
//         if (sorted_str != "1 2 3 4 5 6 7 8 9 10")
//         {
//             cout << "Incorrect heapsort result. Expected 1 2 3 4 5 6 7 8 9 10
//             but got : " << sorted_str << endl;
//         }
//     }
//     catch (exception &e)
//     {
//         cerr << "Error in sorting : " << e.what() << endl;
//     }
//
//     delete[] empty_data;
//     delete[] int_data;
// }

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

// void test_application_waitlist()
// {
//     // create a minqueue of students
//     MinQueue<StudentRecord> waitlist;
//     waitlist.insert({"Alice", SR});
//     waitlist.insert({"Bob", JR});
//     waitlist.insert({"Charlie", SO});
//     waitlist.insert({"David", FR});
//     waitlist.insert({"Eve", SR});
//     waitlist.insert({"Frank", JR});
//     waitlist.insert({"Grace", SO});
//     waitlist.insert({"Heidi", FR});
//     waitlist.insert({"Ivan", SR});
//     waitlist.insert({"Judy", JR});
//     waitlist.insert({"Mallory", SO});
//     waitlist.insert({"Niaj", FR});
//     waitlist.insert({"Olivia", SR});
//     waitlist.insert({"Peggy", JR});
//
//     // process the waitlist and print the order in which students are
//     registered cout << "Registration order:" << endl;
//
//     // assume there are only 10 spots available
//     for (int i = 0; i < 10; i++)
//     {
//         StudentRecord student = waitlist.extract_min();
//         cout << student << endl;
//     }
//
// }
//
// void time_test()
// {
//     MinQueue<int> mq;
//     // TO-DO: generate large minqueue
//     int size = -1; // TO-DO: set size of large minqueue
//     int total = 0;
//
//     int val = rand() % 100000;
//     auto begin = std::chrono::high_resolution_clock::now();
//     mq.insert(val);
//     auto end = std::chrono::high_resolution_clock::now();
//     auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end -
//     begin); cout << "insert time test took " << elapsed.count() << "
//     nanoseconds" << endl; total += elapsed.count();
//
//     begin = std::chrono::high_resolution_clock::now();
//     int _ = mq.min();
//     end = std::chrono::high_resolution_clock::now();
//     elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end -
//     begin); cout << "min time test took " << elapsed.count() << "
//     nanoseconds" << endl; total += elapsed.count();
//
//     begin = std::chrono::high_resolution_clock::now();
//     _ = mq.extract_min();
//     end = std::chrono::high_resolution_clock::now();
//     elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end -
//     begin); cout << "extract min time test took " << elapsed.count() << "
//     nanoseconds" << endl; total += elapsed.count();
//
//     int last_index = size - 1;  // indexing starts at 0
//     int new_val = mq.min() - 1; // ensure we're decreasing the key
//     begin = std::chrono::high_resolution_clock::now();
//     mq.decrease_key(last_index, new_val);
//     end = std::chrono::high_resolution_clock::now();
//     elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end -
//     begin); cout << "decrease key time test took " << elapsed.count() << "
//     nanoseconds" << endl; total += elapsed.count(); cout << "Total time: " <<
//     total << endl;
// }

int main() {

  test_minqueue();
  // test_insert();
  // test_min();
  // test_extract_min();
  // test_decrease_key();
  // test_heapify();
  // test_build_min_heap();
  // test_heapsort();
  //
  // test_application_waitlist();
  //
  // time_test();

  cout << "Testing completed" << endl;

  return 0;
}
