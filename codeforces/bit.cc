#include <iostream>
#include <string>

using namespace std;

int main() {
  int lines = 0;

  cin >> lines;

  int total = 0;
  string temp;

  for (int i = 0; i < lines; i++) {
    cin >> temp;

    if (temp.at(0) == '+' || temp.at(2) == '+') {
      total++;
    } else if (temp.at(0) == '-' || temp.at(2) == '-') {
      total--;
    }
  }

  cout << total << endl;

  return 0;
}
