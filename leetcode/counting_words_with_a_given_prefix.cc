#include <vector>

class Solution {
 public:
  int PrefixCount(std::vector<std::string>& words, std::string pref) {
    int total = 0;

    for (const std::string& i : words) {
      if (i.starts_with(pref)) {
        total++;
      }
    }

    return total;
  }
};
