#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

bool testsPassed(vector<int> a, vector<int> b) {
  if (a.size() != b.size()) {
    return false;
  }

  for (auto itA = a.begin(), itB = b.begin(); itA != a.end(); itA++, itB++) {
    if (*itA != *itB) {
      return false;
    }
  }

  return true;
}

vector<int> productExceptSelf(vector<int>& nums) {
  vector<int> preFix(nums.size());
  vector<int> postFix(nums.size());

  // gets prefix
  // example: 1, 2, 3, 4 -> 1, 2, 6, 24
  int left = 1;
  for (int i = 0; i < nums.size(); i++) {
    preFix[i] = nums[i] * left;
    left = nums[i] * left;
  }

  // gets postfix
  // example: 1, 2, 3, 4 -> 24, 24, 12, 4
  int right = 1;
  for (int i = nums.size() - 1; i >= 0; i--) {
    postFix[i] = right * nums[i];
    right *= nums[i];
  }

  // gets answer
  left = 1;
  right = postFix[1];
  for (int i = 0; i < nums.size(); i++) {
    nums[i] = left * right;

    left = preFix[i];

    if ((i + 2) >= nums.size()) {
      right = 1;
    } else {
      right = postFix[i + 2];
    }
  }

  return nums;
}

int main() {
  vector<int> testVec = {1, 2, 3, 4};
  assert(testsPassed(productExceptSelf(testVec), {24, 12, 8, 6}) == true);

  testVec = {-1, 1, 0, -3, 3};
  assert(testsPassed(productExceptSelf(testVec), {0, 0, 9, 0, 0}) == true);

  testVec = {2, 3, 5, 0};
  assert(testsPassed(productExceptSelf(testVec), {0, 0, 0, 30}) == true);

  cout << "All tests passed." << endl;

  return 0;
}
