#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  // test cases
  //vector<int> nums = {1, 2, 3};
  //vector<int> nums = {0, 1};
  //vector<int> nums = {1};
  vector<int> nums = {0, -1, 1};

  // solution
  vector<vector<int>> permute;
  sort(nums.begin(), nums.end());

  do {
    permute.push_back(nums);
  } while (next_permutation(nums.begin(), nums.end()));

  for (auto i : permute) {
    for (int j : i) {
      cout << j << " ";
    }

    cout << endl;
  }

  return 0;
}
