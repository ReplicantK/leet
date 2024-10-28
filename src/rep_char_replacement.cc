#include <iostream>
#include <string>
#include <unordered_map>

int characterReplacement(std::string s, int k) {
  int longest = 0;

  std::unordered_map<char, int> mp;

  char longestChar = s[0];
  int windowStart = 0;

  for (int i = 0; i < s.size(); i++) {
    mp[s[i]]++;

    if (mp[s[i]] > mp[longestChar]) {
      longestChar = s[i];
    }

    if (i - windowStart + 1 - mp[longestChar] > k) {
      mp[s[windowStart]]--;
      windowStart++;
      continue;
    }

    if (i - windowStart + 1 > longest) {
      longest = i - windowStart + 1;
    }
  }

  return longest;
}

int main() {
  std::cout << "case 1 got: " << characterReplacement("ABAB", 2);
  std::cout << ", expected: 4\n";

  std::cout << "case 2 got: " << characterReplacement("AABABBA", 1);
  std::cout << ", expected: 4\n";

  std::cout << "case 3 got: " << characterReplacement("ABAB", 0);
  std::cout << ", expected: 1\n";

  std::cout << "case 4 got: " << characterReplacement("ABBB", 2);
  std::cout << ", expected: 4\n";

  std::cout << "case 5 got: " << characterReplacement("AAAAABBBBCBB", 4);
  std::cout << ", expected: 10" << std::endl;
  
  return 0;
}
