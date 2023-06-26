#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  vector<int> results;

  for (int i = 0; i < nums.size(); i++) {
    for (int j = i + 1; j < nums.size(); j++) {
      if ((nums.at(i) + nums.at(j)) == target) {
        results.push_back(i);
        results.push_back(j);
      }
    }
  }

  return results;
}

int main() {
  int target = 9;
  vector<int> nums;

  nums.push_back(2);
  nums.push_back(7);
  nums.push_back(11);
  nums.push_back(15);

  vector<int> test = twoSum(nums, target);

  return 0;
}
