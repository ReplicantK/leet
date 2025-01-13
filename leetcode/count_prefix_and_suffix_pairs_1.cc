#include <vector>
#include <string>

class Solution {
 public:
  int CountPrefixSuffixPairs(std::vector<std::string>& words) {
    if (words.size() == 1) {
      return 0;
    }

    int total = 0;

    for (int i = 0; i < words.size() - 1; i++) {
      for (int j = i + 1; j < words.size(); j++) {
        auto control_forward = words[i].begin();
        auto control_back = words[i].rbegin();

        auto compare_forward = words[j].begin();
        auto compare_back = words[j].rbegin();

        while (control_forward != words[i].end()) {
          if (*control_forward == *compare_forward && *control_back == *compare_back) {
            control_forward++;
            control_back++;

            compare_forward++;
            compare_back++;
          } else {
            break;
          }
        }

        if (control_forward == words[i].end()) {
          total++;
        }
      }
    }

    return total;
  }
};
