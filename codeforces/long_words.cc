#include <iostream>
#include <string>

using namespace std;

int main() {
  int number = 0;
  string hi;

  cin >> number;

  for (int i = 0; i < number; i++) {
    cin >> hi;

    if (hi.length() > 10) {
      cout << hi[0] << hi.length() - 2 << hi[hi.length() - 1] << endl;
    }
    else {
      cout << hi << endl;
    }
  }
  
  return 0;
}
