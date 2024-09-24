#include <iostream>
#include <string>

using namespace std;

int main() {
  int x = 0;

  cin >> x;

  int counter = 5;
  int total = 0;

  int mod = 0;

  do {
    mod = x % counter;

    total += x / counter;
    x = x - ((x / counter) * counter);

    counter--;

  } while (mod != 0);
  
  cout << total << endl;

  return 0;
}
