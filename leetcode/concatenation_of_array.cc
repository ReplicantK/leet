#include <vector>

class Solution {
 public:
  std::vector<int> GetConcatenation(std::vector<int>& nums) {
    nums.reserve(nums.size() * 2);

    for (int i : nums) {
      nums.emplace_back(i);
    }

    return nums;
  }
};
