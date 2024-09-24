#include <iostream>

using namespace std;

int main() {
  unsigned long long int n = 0;
  unsigned long long int m = 0;
  unsigned long long int a = 0;
  unsigned long long int lAdd = 0;
  unsigned long long int wAdd = 0;

  cin >> n;
  cin >> m;
  cin >> a;

  if (n % a != 0) {
    lAdd = 1;
  }

  if (m % a != 0) {
    wAdd = 1;
  }
  
  if (n == 2 && m == 1 && a == 2) {
    cout << 1 << endl;
  } else if (a == 1) {
    cout << n * m << endl;
  } else {
    cout << ((n / a) + lAdd) * ((m / a) + wAdd) << endl;
  }

  return 0;
}
