#include <iostream>
#include <vector>

int findMin(const std::vector<int>& nums) {
  int ans = nums[0];
  int l = 0;
  int r = nums.size() - 1;
  int m = 0;
  
  while (l <= r) {
    // this formula avoids integer overflow divison, compared to: m = (l + r) / 2
    m = l + (r - l) / 2;

    if (nums[m] < ans) {
      ans = nums[m];
    }

    if (nums[m] <= nums[r]) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  return ans;
}

int main() {
  std::cout << "CASE 1\n" << findMin({3, 4, 5, 1, 2}) << " :got\n";
  std::cout << "1 :expected\n\n";

  std::cout << "CASE 2\n" << findMin({4, 5, 6, 7, 0, 1, 2}) << " :got\n";
  std::cout << "0 :expected\n\n";

  std::cout << "CASE 3\n" << findMin({11, 13, 15, 17}) << " :got\n";
  std::cout << "11 :expected" << std::endl;

  return 0;
}
