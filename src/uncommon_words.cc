#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

vector<string> uncommonFromSentences(string s1, string s2) {
  unordered_map<string, int> mp;
  vector<string> a;

  string c = "";
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] == ' ') {
      mp[c]++;
      c = "";
      continue;
    }

    c += s1[i];
  }

  mp[c]++;
  c = "";
  for (int i = 0; i < s2.size(); i++) {
    if (s2[i] == ' ') {
      mp[c]++;
      c = "";
      continue;
    }

    c += s2[i];
  }
  mp[c]++;

  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it->second == 1) {
      a.push_back(it->first);
    }
  }

  return a;
}

int main() {
  string s1 = "this apple is sweet";
  string s2 = "this apple is sour";

  for (string i : uncommonFromSentences(s1, s2)) {
    cout << i << " ";
  }
  cout << "\nTest 1 pass!\n\n";

  s1 = "apple apple";
  s2 = "banana";
  for (string i : uncommonFromSentences(s1, s2)) {
    cout << i << " ";
  }
  cout << "\nTest 2 pass!" << endl;

  return 0;
}
