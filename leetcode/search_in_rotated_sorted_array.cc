#include <vector>
#include <iostream>

int search(const std::vector<int>& nums, int target) {
  int l = 0;
  int r = nums.size() - 1;

  while (l <= r) {
    int mid = l + (r - l) / 2;

    if (nums[mid] == target) {
      return mid;
    }

    if (nums[r] >= target) {
      if (nums[mid] < target || nums[mid] > nums[r]) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    } else {
      if (nums[mid] > target || nums[mid] < nums[l]) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
  }

  return -1;
}

int main() {
  std::cout << "CASE1\n" << search({4, 5, 6, 7, 0, 1, 2}, 0) << " :got\n";
  std::cout << "4 :expected\n\n";

  std::cout << "CASE2\n" << search({4, 5, 6, 7, 0, 1, 2}, 3) << " :got\n";
  std::cout << "-1 :expected\n\n";

  std::cout << "CASE3\n" << search({1}, 0) << " :got\n";
  std::cout << "-1 :expected\n\n";

  std::cout << "CASE4\n" << search({1, 3, 5}, 5) << " :got\n";
  std::cout << "2 :expected\n\n";

  std::cout << "CASE5\n" << search({5, 1, 3}, 3) << " :got\n";
  std::cout << "2 :expected\n\n";

  std::cout << "CASE6\n" << search({5, 1, 3}, 5) << " :got\n";
  std::cout << "0 :expected\n\n";

  std::cout << "CASE7\n" << search({4, 5, 6, 7, 8, 1, 2, 3}, 8) << " :got\n";
  std::cout << "4 :expected" << std::endl;

  return 0;
}
