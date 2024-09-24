#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  string s;
  vector<char> vec;

  cin >> s;
  
  for (int i = 0; i < s.length(); i++) {
    if (i == 0) {
      vec.push_back(s.at(i));
    } else if (i % 2 == 0) {
      vec.push_back(s.at(i));
    }
  }
  
  sort(vec.begin(), vec.end());

  for (int i = 0; i < vec.size(); i++) {
    cout << vec.at(i);
    if (i != vec.size() - 1) {
      cout << "+";
    } else {
      cout << endl;
    }
  }

  return 0;
}
