#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  int u = 0;
  int l = 0;

  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    if (isupper(s[i])) {
      u++;
    } else {
      l++;
    }
  }

  if ((u == l) || (u < l)) {
    for (int i = 0; i < s.length(); i++) {
      s[i] = tolower(s[i]);
    }
  } else {
    for (int i = 0; i < s.length(); i++) {
      s[i] = toupper(s[i]);
    }
  }

  cout << s << endl;
   
  return 0;
}
