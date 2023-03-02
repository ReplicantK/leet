#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;

  int lucky = 0;

  for (int i = 0; i < s.length(); i++) {
    if ((s[i] == 7) || (s[i] == 4)) {
      lucky++;
    }
  }

  if ((lucky == 7) || (lucky == 4)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
   
  return 0;
}
