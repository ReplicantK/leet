#include <iostream>
#include <cassert>
#include <string>
#include <unordered_map>

using namespace std;

bool isIsomorphic(string s, string t) {
  unordered_map<char, int> mp;
  unordered_map<char, int> mp2;

  for (int i = 0; i < s.length(); i++) {
    mp[s[i]] = -1;
    mp2[t[i]] = -1;
  }

  for (int i = 0; i < s.length(); i++) {
    if (mp[s[i]] != mp2[t[i]]) {
      return false;
    }

    mp[s[i]] = i;
    mp2[t[i]] = i;
  }

  return true;
}

int main() {
  assert(isIsomorphic("egg", "add") == true);
  assert(isIsomorphic("foo", "bar") == false);
  assert(isIsomorphic("paper", "title") == true);
 
  cout << "All tests passed." << endl;

  return 0;
}
