#include <array>
#include <string>

class Solution {
 public:
  int MinimumLength(std::string s) {
    std::array<int, 26> arr;

    for (char i : s) {
      arr[i - 'a']++;
    }

    int total = 0;
    for (int i : arr) {
      if (i == 0) {
        continue;
      } else if (i % 2 == 1) {
        total += 1;
      } else {
        total += 2;
      }
    }

    return total;
  }
};
