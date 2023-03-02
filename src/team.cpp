#include <iostream>
#include <string>

using namespace std;

int main() {
  int n = 0;
  cin >> n;
  int f1 = 0;
  int f2 = 0;
  int f3 = 0;
  int total = 0;

  for (int i = 0; i < n; i++) {
    cin >> f1;
    cin >> f2;
    cin >> f3;

    if ((f1 == 1 && f2 == 1) ||  (f1 == 1 && f3 == 1) || (f2 == 1 && f3 == 1)) {
      total += 1;
    }
  }

  cout << total << endl;

  return 0;
}
