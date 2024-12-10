#include <iostream>
#include <vector>

int RemoveDuplicates(std::vector<int>& nums) {
  int u = 1;

  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] == nums[i - 1]) {
      continue;
    }

    nums[u] = nums[i];
    u++;
  }

  return u;
}

int main() {
  std::vector<int> nums = {1, 1, 2};
  std::cout << "CASE1\nExpected: [1,2]\nReceived: [";
  
  int r = RemoveDuplicates(nums);

  for (int i = 0; i < r; i++) {
    if (i == 0) {
      std::cout << nums[i];
    } else {
      std::cout << "," << nums[i];
    }
  }
  
  std::cout << "]\n\n";
  
  nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  std::cout << "CASE2\nExpected: [0,1,2,3,4]\nReceived: [";

  r = RemoveDuplicates(nums);

  for (int i = 0; i < r; i++) {
    if (i == 0) {
      std::cout << nums[i];
    } else {
      std::cout << "," << nums[i];
    }
  }
  
  std::cout << "]\n";

  return 0;
}
