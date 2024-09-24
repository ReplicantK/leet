#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void sortColors(vector<int>& nums) {
  unordered_map<int, int> mp;

  for (int i : nums) {
    mp[i]++;
  }

  int i = 0;
  while (mp[0] > 0) {
    nums[i] = 0;
    mp[0]--;
    i++;
  }

  while (mp[1] > 0) {
    nums[i] = 1;
    mp[1]--;
    i++;
  }
  
  while (mp[2] > 0) {
    nums[i] = 2;
    mp[2]--;
    i++;
  }
}

int main() {
  vector<int> nums = {2,0,2,1,1,0};

  sortColors(nums);
  for (int i : nums) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
