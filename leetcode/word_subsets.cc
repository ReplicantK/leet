#include <vector>
#include <string>
#include <unordered_map>

class Solution {
 public:
  std::vector<std::string> WordSubsets(std::vector<std::string>& words1, std::vector<std::string>& words2) {
    std::vector<int> key(26, 0);

    for (const std::string& i : words2) {
      std::unordered_map<char, int> mp;

      for (char j : i) {
        mp[j]++;
  
        if (mp[j] > key[j - 'a']) {
          key[j - 'a'] = mp[j];
        }
      }
    }

    std::vector<std::vector<int>> comp;
    comp.reserve(words1.size());

    for (const std::string& i : words1) {
      std::vector<int> temp(26, 0);

      for (char j : i) {
        temp[j - 'a']++;
      }

      comp.emplace_back(temp);
    }

    std::vector<std::string> ans;
    ans.reserve(words1.size());

    for (int i = 0; i < comp.size(); i++) {
      bool add = true;

      for (int j = 0; j < comp[i].size(); j++) {
        if (comp[i][j] < key[j]) {
          add = false;
          break;
        }
      }

      if (add) {
        ans.emplace_back(words1[i]);
      }
    }

    return ans;
  }
};
