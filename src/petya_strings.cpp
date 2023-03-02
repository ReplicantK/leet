#include <iostream>
#include <string>

using namespace std;

int main() {
  string str;
  string str2;
   
  cin >> str >> str2;

  int results = 0;

  for (int i = 0; i < str.length(); i++) {
    str.at(i) = tolower(str.at(i));
    str2.at(i) = tolower(str2.at(i));

    if (int(str.at(i)) < int(str2.at(i))) {
      results = -1;
      break;
    } else if (int(str.at(i)) > int(str2.at(i))) {
      results = 1;
      break;
    }
  }

  cout << results << endl;

  return 0;
}
