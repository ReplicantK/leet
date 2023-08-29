#include <iostream>
#include <vector>

using namespace std;

int main() {
  // test cases
  //int n = 3;
  //int n = 5;
  int n = 15;
  //int n = 1;
  //int n = 10000;

  // solution
  vector<string> fizzBuzz;

  for (int i = 1; i <= n; i++) {
    if ((i % 3 == 0) && (i % 5 == 0)) {
      fizzBuzz.push_back("FizzBuzz");
    } else if (i % 3 == 0) {
      fizzBuzz.push_back("Fizz");
    } else if (i % 5 == 0) {
      fizzBuzz.push_back("Buzz");
    } else {
      fizzBuzz.push_back(to_string(i));
    }
  }

  // output checking
  for (int i = 0; i < fizzBuzz.size(); i++) {
    cout << fizzBuzz.at(i) << endl;
  }

  return 0;
}
