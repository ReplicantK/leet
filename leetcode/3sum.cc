#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

void printer(std::vector<std::vector<int>>& vec, int caseNum, std::string& expected) {
  std::cout << "Test Case " << caseNum << " expected: " << expected << "\n";
  std::cout << "Test Case " << caseNum << " got     : ";
  std::cout << "[";

  if (vec.empty()) {
    std::cout << "]";
    return;
  }

  for (int i = 0; i < vec.size() - 1; i++) {
    std::cout << "[";

    for (int j = 0; j < vec[i].size() - 1; j++) {
      std::cout << vec[i][j] << ",";
    }

    std::cout << vec[i][vec[i].size() - 1] << "],";
  }

  std::cout << "[";
  for (int i = 0; i < vec[vec.size() - 1].size() - 1; i++) {
    std::cout << vec[vec.size() - 1][i] << ",";
  }
  std::cout << vec[vec.size() - 1][vec[vec.size() - 1].size() - 1] << "]]";
}

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
  std::vector<std::vector<int>> answer;

  std::sort(nums.begin(), nums.end());
     
  for (int i = 0; i < nums.size() - 2; i++) {
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }

    int pointerLeft = i + 1;
    int pointerRight = nums.size() - 1;

    while (pointerLeft < pointerRight) {
      int a = nums[i];
      int b = nums[pointerLeft];
      int c = nums[pointerRight];

      if ((a + b + c) < 0) {
        pointerLeft++;
        continue;
      } else if ((a + b + c) > 0) {
        pointerRight--;
        continue;
      }

      answer.push_back({a, b, c});

      pointerLeft++;
      while (nums[pointerLeft] == b && pointerLeft < pointerRight) {
        pointerLeft++;
      }
    }
  }

  return answer;
}

int main() {
  std::vector<int> case1 = {-1, 0, 1, 2, -1, -4};
  std::string case1expected = "[[-1,-1,2],[-1,0,1]]";
  std::vector<std::vector<int>> case1a = threeSum(case1);
  printer(case1a, 1, case1expected);
  std::cout << "\n\n";

  std::vector<int> case2 = {0, 1, 1};
  std::string case2expected = "[]";
  std::vector<std::vector<int>> case2a = threeSum(case2);
  printer(case2a, 2, case2expected);
  std::cout << "\n\n";

  std::vector<int> case3 = {0, 0, 0};
  std::string case3expected = "[[0,0,0]]";
  std::vector<std::vector<int>> case3a = threeSum(case3);
  printer(case3a, 3, case3expected);
  std::cout << "\n\n";

  std::vector<int> case4 = {3, -2, 1, 0};
  std::string case4expected = "[]";
  std::vector<std::vector<int>> case4a = threeSum(case4);
  printer(case4a, 4, case4expected);
  std::cout << "\n\n";

  std::vector<int> case5 = {0, 0, 0, 0};
  std::string case5expected = "[[0,0,0]]";
  std::vector<std::vector<int>> case5a = threeSum(case5);
  printer(case5a, 5, case5expected);
  std::cout << "\n\n";

  std::vector<int> case6 = {-1, 0, 1, 0};
  std::string case6expected = "[[-1,0,1]]";
  std::vector<std::vector<int>> case6a = threeSum(case6);
  printer(case6a, 6, case6expected);
  std::cout << "\n\n";

  std::vector<int> case7 = {3, 0, -2, -1, 1, 2};
  std::string case7expected = "[[-2,-1,3],[-2,0,2],[-1,0,1]]";
  std::vector<std::vector<int>> case7a = threeSum(case7);
  printer(case7a, 7, case7expected);

  std::cout << std::endl;

  return 0;
}
