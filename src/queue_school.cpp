#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n = 0;
  int t = 0;
  string s; 

  cin >> n >> t >> s;

  for (int i = 0; i < t; i++) {
    vector<int> pos;

    for (int j = 0; j < n; j++) {
      if ((s[j] == B) && (s[j+1] == G)) {
        pos.push_back(j);
      }
    }

    for (int k = 0; k < pos.size(); k++) {
      char temp = s[pos[k]];
      s[pos[k]] = s[pos[k] + 1];
      s[pos[k] + 1] = temp;
    }
  }
  
  cout << s << endl;
  
  return 0;
}
