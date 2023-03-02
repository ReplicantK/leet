#include <iostream>
#include <string>

using namespace std;

int main() {
  string players;
  int count = 1;

  cin >> players;

  for (int i = 0; i < players.length(); i++) {
    count = 1;

    for (int j = i+1; i < players.length(); j++) {
      if (players[j] == players[i]) {
        count++;
      } else {
        break;
      }
    }

    if (count > 6) {
      break;
    }
  }

  if (count > 6) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
   
  return 0;
}
