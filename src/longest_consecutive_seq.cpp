#include <iostream>
#include <queue>
#include <vector>
#include <cassert>
#include <unordered_map>

using namespace std;

int longestConsecutive(vector<int>& nums) {
  if (nums.size() == 0) {
    return 0;
  }

  priority_queue<int, vector<int>, greater<int>> q;
  unordered_map<int, bool> mp;

  for (auto num : nums) {
    if (!mp[num]) {
      q.push(num);
      mp[num] = true;
    }
  }

  int max = 0, counter = 1, last = q.top();
  q.pop();

  while (!q.empty()) {
    if (last + 1 == q.top()) {
      counter++;
    } else {
      if (counter > max) {
        max = counter;
      }

      counter = 1;
    }

    last = q.top();
    q.pop();
  }

  if (counter > max) {
    max = counter;
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

  cout << "All tests passed." << endl;

  return 0;
}
