#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;

  cin >> s;
   
  int total = 1;

  for (int i = 1; i < s.length(); i++) {
    bool add = true;
    
    for (int j = 0; j < i; j++) {
      if (s[i] == s[j]) {
        add = false;
      }
    }

    if (add) {
      total++;
    }
  }

  if (total % 2 == 0) {
    cout << "CHAT WITH HER!" << endl;
  } else {
    cout << "IGNORE HIM!" << endl;
  }
  
  return 0;
}
