#include <iostream>
#include <string>
#include <unordered_map>

int lengthOfLongestSubstring(std::string s) {
  int longest = 0;
  int windowStart = 0;

  std::unordered_map<char, int> m;

  for (int i = 0; i < s.size(); i++) {
    if (m.contains(s[i]) && m[s[i]] >= windowStart) {
      if ((i - windowStart) > longest) {
        longest = i - windowStart;
      }

      windowStart = m[s[i]] + 1;
    }

    m[s[i]] = i;
  }

  if ((s.size() - windowStart) > longest) {
    longest = s.size() - windowStart;
  }

  return longest;
}

int main() {
  std::string case1 = "abcabcbb";
  std::string case2 = "bbbbb";
  std::string case3 = "pwwkew";
  std::string case4 = "dvdf";
  std::string case5 = "anviaj";
  std::string case6 = "cdd";

  std::cout << "case 1 expected: " << 3;
  std::cout << ", got: " << lengthOfLongestSubstring(case1) << "\n";

  std::cout << "case 2 expected: " << 1;
  std::cout << ", got: " << lengthOfLongestSubstring(case2) << "\n";

  std::cout << "case 3 expected: " << 3;
  std::cout << ", got: " << lengthOfLongestSubstring(case3) << "\n";

  std::cout << "case 4 expected: " << 3;
  std::cout << ", got: " << lengthOfLongestSubstring(case4) << "\n";

  std::cout << "case 5 expected: " << 5;
  std::cout << ", got: " << lengthOfLongestSubstring(case5) << "\n";

  std::cout << "case 6 expected: " << 2;
  std::cout << ", got: " << lengthOfLongestSubstring(case6) << std::endl;
  
  return 0;
}
