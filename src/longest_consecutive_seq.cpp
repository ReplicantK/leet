#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int longestConsecutive(vector<int>& nums) {
  if (nums.empty()) {
    return 0;
  }

  sort(nums.begin(), nums.end());

  int counter = 1, max = 1, last = nums[0];

  for (int i = 1; i < nums.size(); i++) {
    if (last == nums[i]) {
      continue;
    } else if (nums[i] - 1 == last) {
      counter++;
    } else {
      counter = 1;
    }

    if (counter > max) {
      max = counter;
    }

    last = nums[i];
  }

  return max;
}

int main() {
  vector<int> nums = {100, 4, 200, 1, 3, 2};
  assert(longestConsecutive(nums) == 4);

  nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  assert(longestConsecutive(nums) == 9);

  nums = {};
  assert(longestConsecutive(nums) == 0);

  nums = {9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6};
  assert(longestConsecutive(nums) == 7);

  nums = {1};
  assert(longestConsecutive(nums) == 1);

  cout << "All tests passed." << endl;

  return 0;
}
