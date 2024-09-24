#include <iostream>
#include <vector>
#include <limits.h>
#include <unordered_map>

using namespace std;

int main() {
  // test cases
  int target = 9;
  vector<int> nums = {2, 7, 11, 15};

  //int target = 6;
  //vector<int> nums = {3, 2, 4};

  //int target = 6;
  //vector<int> nums = {3, 3};

  // solution
  unordered_map<int, int> mp;

  for (int i = 0; i < nums.size(); i++) {
    mp.insert({nums.at(i), i});
  }

  int needed = INT_MAX;
  for (int i = 0; i < nums.size(); i++) {
    needed = target - nums.at(i);
    if (!mp.contains(needed)) {
      continue;
    }

    if (mp[needed] != i) {
      nums.clear();
      nums.push_back(i);
      nums.push_back(mp[needed]);
      break;
    }
  }

  // simply printing out the answer
  for (int i : nums) {
    cout << i << endl;
  }

  return 0;
}
