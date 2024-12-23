#include <iostream>
#include <vector>

int SingleNonDuplicate(std::vector<int> nums) {
  int l = 0, r = nums.size() - 1, mid = 0;

  while (l <= r) {
    mid = l + (r - l) / 2;

    if (mid > 0 && mid < nums.size() && nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
      break;
    } else if (mid > 0 && mid < nums.size() && mid % 2 == 0 && nums[mid] == nums[mid + 1]) {
      l = mid + 1;
    } else if (mid > 0 && mid < nums.size() && mid % 2 != 0 && nums[mid] == nums[mid - 1]) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  return nums[mid];
}

int main() {
  std::cout << "CASE1\nExpected: 2\nReceived: " << SingleNonDuplicate({1, 1, 2, 3, 3, 4, 4, 8, 8});
  std::cout << "\n\nCASE2\nExpected: 10\nReceived: " << SingleNonDuplicate({3, 3, 7, 7, 10, 11, 11});
  std::cout << "\n\nCASE3\nExpected: 2\nReceived: " << SingleNonDuplicate({1, 1, 2, 3, 3});
  std::cout << "\n";

  return 0;
}
