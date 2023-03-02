#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  string t;

  cin >> s >> t;

  bool correct = true;

  int j = s.length() - 1;
  for (int i = 0; i < s.length(); i++) {
    if (t[j] != s[i]) {
      correct = false;
      break;
    }

    j--;
  }

  if (correct) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
   
  return 0;
}
