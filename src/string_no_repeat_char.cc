#include <iostream>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

int lengthOfLongestSubstring(string s) {
  int p1 = 0;
  int longest = 0;
  int c_long = 0;

  unordered_map<char, int> mp;

  for (int i = 0; i < s.size(); i++) {
    if (!mp.contains(s[i]) || mp[s[i]] < p1) {
      c_long++;

      if (c_long > longest) {
        longest = c_long;
      }

      mp[s[i]] = i;
      continue;
    }

    c_long = i - mp[s[i]];
    p1 = mp[s[i]] + 1;
    mp[s[i]] = i;
  }

  return longest;
}

int main() {
  string s1 = "abcabcbb";
  string s2 = "bbbbb";
  string s3 = "pwwkew";
  string s4 = "dvdf";
  string s5 = "aab";
  string s6 = "tmmzuxt";

  cout << lengthOfLongestSubstring(s1) << endl;
  cout << lengthOfLongestSubstring(s2) << endl;
  cout << lengthOfLongestSubstring(s3) << endl;
  cout << lengthOfLongestSubstring(s4) << endl;
  cout << lengthOfLongestSubstring(s5) << endl;
  cout << lengthOfLongestSubstring(s6) << endl;

  return 0;
}
