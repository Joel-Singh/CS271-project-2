#include <iostream>

using namespace std;

//=================================================
// stringify
// Create a string from a string, number, or type implementing to_string
//
// Parameters:
//  value: value to convert
//=================================================
template <typename T> string stringify(const T &value) {
  if constexpr (std::is_same_v<T, bool>) {
    if (value) {
      return "true";
    } else {
      return "false";
    }
  } else if constexpr (std::is_arithmetic_v<T>) {
    return std::to_string(value);
  } else if constexpr (std::is_same_v<T, std::string>) {
    return value;
  } else {
    return value.to_string();
  }
}

template <typename T>
void test(std::string description, const T &actual, std::string expected) {
  cout << "Running: `" << description << "`" << endl;
  if (stringify(actual) != expected) {
    cout << "FAILED: `" << description << "`" << endl;
    cout << "Expected: `" << expected << "`" << endl;
    cout << "Actual: `" << stringify(actual) << "`" << endl;

  } else {
    cout << "Successful: `" << description << "`" << endl;
  }
  cout << "------------------------------" << endl;
}

//=================================================
// array_to_string
// Convert an array to a string representation
//
// PARAMETERS:
//  A: Array to convert
//  len: Length of `A`
//
// RETURN VALUE:
//  string representation of `A`
//=================================================
template <typename T> string array_to_string(T *A, int len) {
  if (len == 0) {
    return "";
  } else {
    string str = to_string(A[0]);

    for (int i = 1; i < len; i++) {
      str += (" " + to_string(A[i]));
    }

    return str;
  }
}
