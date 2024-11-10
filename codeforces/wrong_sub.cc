#include <iostream>
#include <string>

using namespace std;

int main() {
  int n = 0;
  int k = 0;

  cin >> n >> k;

  for (int i = 0; i < k; i++) {
    if (n % 10 == 0) {
      n /= 10;
    } else {
      n -= 1;
    }
  }

  cout << n << endl;
   
  return 0;
}
