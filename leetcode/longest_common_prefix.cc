#include <string>
#include <vector>

class Solution {
 public:
  std::string LongestCommonPrefix(std::vector<std::string>& strs) {
    std::string probe = strs.front();
    std::string s;
    s.reserve(probe.size());

    for (int i = 0; i < probe.size(); i++) {
      for (int j = 1; j < strs.size(); j++) {
        if (strs[j][i] != probe[i]) {
          return s;
        }
      }
      
      s += probe[i];
    }

    return s;
  }
};
