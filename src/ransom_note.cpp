#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
  unordered_map<char, int> mp;
  for (int i = 0; i < magazine.size(); i++) {
    mp[magazine[i]]++;
  }

  for (char i : ransomNote) {
    if (mp[i] != 0) {
      mp[i]--;
    } else {
      return false;
    }
  }

  return true;
}

int main() {
  // test case 1
  string ransomNote1 = "a";
  string magazine1 = "b";

  // test case 2
  string ransomNote2 = "aa";
  string magazine2 = "ab";

  // test case 3
  string ransomNote3 = "aa";
  string magazine3 = "aab";

  // test case 4
  string ransomNote4 = "bg";
  string magazine4 = "efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj";

  cout << canConstruct(ransomNote1, magazine1) << endl;
  cout << canConstruct(ransomNote2, magazine2) << endl;
  cout << canConstruct(ransomNote3, magazine3) << endl;
  cout << canConstruct(ransomNote4, magazine4) << endl;

  return 0;
}
