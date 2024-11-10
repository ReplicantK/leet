#include <iostream>
#include <string>

using namespace std;

int main() {
  string address = "255.100.50.0";
  string d = "[.]";
  string a = "";

  for (int i = 0; i < address.length(); i++) {
    if (address.at(i) == '.') {
      a += d;
    } else {
      a += address.at(i);
    }
  }

  cout << a << endl;

  return 0;
}
