#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
  int low = 0;
  int mid = 0;
  int high = nums.size() - 1;
  int found = -1;

  while (low <= high) {
    mid = (low + high) / 2;

    if (nums.at(mid) < target) {
      low = mid + 1;
    } else if (nums.at(mid) > target) {
      high = mid - 1;
    } else {
      found = mid;
      break;
    }
  }

  return found;
}

int main() {

  // example 1
  vector<int> nums1;
  nums1.push_back(-1);
  nums1.push_back(0);
  nums1.push_back(3);
  nums1.push_back(5);
  nums1.push_back(9);
  nums1.push_back(12);
  int target1 = 9;

  // example 2
  int target2 = 2;

  // example 3
  vector<int> nums3;
  nums3.push_back(5);
  int target3 = 5;

  // example 4
  int target4 = -5;

  // example 5
  vector<int> nums4;
  nums4.push_back(2);
  nums4.push_back(5);
  int target5 = 5;

 cout << search(nums1, target1) << "\n";
 cout << search(nums1, target2) << "\n";
 cout << search(nums3, target3) << "\n";
 cout << search(nums3, target4) << "\n";
 cout << search(nums4, target5) << endl;

  return 0;
}
