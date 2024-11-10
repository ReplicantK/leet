#include <iostream>
#include <string>

using namespace std;

int main() {
  int n = 0;

  cin >> n;

  int previous = 0;
  int atMost = 0;
  for (int i = 0; i < n; i++) {
    int a = 0;
    int b = 0;

    cin >> a >> b;

    previous -= a;
    previous += b;

    if (previous > atMost) {
      atMost = previous;
    }
  }

  cout << atMost << endl;
   
  return 0;
}
