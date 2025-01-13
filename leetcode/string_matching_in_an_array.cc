#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> StringMatching(std::vector<std::string>& words) {
    std::vector<std::string> v;
    v.reserve(words.size());

    for (int i = 0; i < words.size(); i++) {
      for (int j = 0; j < words.size(); j++) {
        if (j != i && words[i].size() <= words[j].size() && words[j].contains(words[i])) {
          v.emplace_back(words[i]);
          break;
        }
      }
    }

    return v;
  }
};
