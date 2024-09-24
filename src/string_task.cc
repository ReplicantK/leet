#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string test;
  vector<char> store;

  cin >> test;

  for (int i = 0; i < test.length(); i++) {
    test[i] = tolower(test[i]);

    if (!((test[i] == a) ||(test[i] == o) ||(test[i] == y) ||(test[i] == e) || (test[i] == u) || (test[i] == i))) {
      store.push_back(test[i]);
    }
  }

  for (int i = 0; i < store.size(); i++) {
    cout << "." << store[i];
  }

  cout << endl;

  return 0;
}
