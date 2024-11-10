#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  // setup and different tests
  vector<int> nums = {3, 2, 3};
  //vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
  //vector<int> nums = {2};

  // solution
  unordered_map<int, int> map;
  
  float limit = nums.size() / 2.0;
  int currentHigh = 0;
  int found = INT_MAX;

  for(::vector<int>::iterator it = nums.begin(); it != nums.end(); it++)  {
    map[*it]++;

    if (map[*it] > currentHigh) {
      currentHigh = map[*it];
      found = *it;
    }
  }

  cout << found << endl;

  return 0;
}
