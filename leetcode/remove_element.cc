#include <vector>

class Solution {
 public:
  int RemoveElement(std::vector<int>& nums, int val) {
    std::vector<int> temp;
    temp.reserve(nums.size());

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != val) {
        temp.emplace_back(nums[i]);
      }
    }

    nums = temp;
    return nums.size();
  }
};
