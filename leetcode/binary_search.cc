#include <iostream>
#include <vector>

int search(const std::vector<int>& nums, int target) {
  int l = 0;
  int m = 0;
  int r = nums.size();

  while (l < r) {
    m = (l + r) / 2;

    if (nums[m] == target) {
      return m;
    } else if (nums[m] < target) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  
  return -1;
}

int main() {
  std::cout << "CASE 1\n" << search({-1, 0, 3, 5, 9, 12}, 9) << " :got\n";
  std::cout << "4 :expected\n\n";

  std::cout << "CASE 2\n" << search({-1, 0, 3, 5, 9, 12}, 2) << " :got\n";
  std::cout << "-1 :expected\n\n";

  std::cout << "CASE 3\n" << search({5}, 5) << " :got\n";
  std::cout << "0 :expected\n\n";

  std::cout << "CASE 4\n" << search({5}, -5) << " :got\n";
  std::cout << "-1 :expected\n\n";

  std::cout << "CASE 5\n" << search({2, 5}, 5) << " :got\n";
  std::cout << "1 :expected" << std::endl;

  return 0;
}
