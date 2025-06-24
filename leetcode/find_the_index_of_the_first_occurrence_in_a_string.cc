#include <iostream>
#include <string>

class Solution {
public:
  int strStr(std::string haystack, std::string needle) {
    for (int i = 0; i < haystack.size(); i++) {
      if (haystack[i] == needle.front()) {
        int search_haystack = i + 1;
        int search_needle = 1;
  
        while (search_haystack < haystack.size() && search_needle < needle.size()) {
          if (haystack[search_haystack] != needle[search_needle]) {
            break;
          } else {
            search_haystack++;
            search_needle++;
          }
        }
  
        if (search_needle == needle.size()) {
          return i;
        }
      }
    }

    return -1;
  }
};

int main() {
  Solution s;

  std::cout << "Expected: 0, got: " << s.strStr("sadbutsad", "sad") << '\n';
  std::cout << "Expected: -1, got: " << s.strStr("leetcode", "leeto") << '\n';

  return 0;
}
