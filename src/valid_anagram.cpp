#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isAnagram(string s, string t) {
  bool ana = true;

  transform(s.begin(), s.end(), s.begin(), ::tolower);
  transform(t.begin(), t.end(), t.begin(), ::tolower);

  sort(s.begin(), s.end());
  sort(t.begin(), t.end());

  if (s != t) {
    ana = false;
  }

  return ana;
}

int main() {
  // example 1
  string s1 = "anagram";
  string t1 = "nagaram";

  // example 2
  string s2 = "rat";
  string t2 = "car";

  cout << isAnagram(s1, t1) << "\n";
  cout << isAnagram(s2, t2) << "\n";

  return 0;
}
