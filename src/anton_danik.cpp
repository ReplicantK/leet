#include <iostream>
#include <string>

using namespace std;

int main() {
  int n = 0;
  string s;

  cin >> n >> s;

  int a = 0;
  int d = 0;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == A) {
      a++;
    } else {
      d++;
    }

  }

  if (a > d) {
    cout << "Anton" << endl;
  } else if (d > a) {
    cout << "Danik" << endl;
  } else {
    cout << "Friendship" << endl;
  }
   
  return 0;
}
