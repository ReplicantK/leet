#include <vector>
#include <iostream>

using namespace std;

int main() {
  // test cases
  //vector<int> nums = {1,2,3,1};
  //vector<int> nums = {1,2,3,4};
  //vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
  vector<int> nums = {2,14,18,22,22};

  // solution 
  bool dup = false;
  sort(nums.begin(), nums.end());
  
  ::vector<int>::iterator i = nums.begin();
  int current = *i;

  i++;

  for (; i != nums.end(); i++) {
    if (*i == current) {
      dup = true;
      break;
    } else {
      current = *i;
    }
  }

  cout << dup << endl;
  return 0;
}
