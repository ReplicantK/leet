#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// solution
vector<int> twoSum(vector<int>& numbers, int target) {
  vector<int> an;

  int left_it = 0;
  int right_it = numbers.size() - 1;

  while (an.size() != 2) {
    if (numbers[right_it] > (target - numbers[left_it])) {
      right_it--;
      continue;
    }

    if (numbers[left_it] < (target - numbers[right_it])) {
      left_it++;
      continue;
    }

    an.push_back(left_it +1);
    an.push_back(right_it +1);
  }

  return an;
}

int main() {
  // case 1
  vector<int> c1 = {2,7,11,15};
  vector<int> c1_ans = {1, 2};
  int c1_target = 9;

  cout << "Expecting answer: " << "[" << c1_ans[0] << ", " << c1_ans[1] << "]";
  vector<int> user_ans = twoSum(c1, c1_target);
  cout << " Got: " << "[" << user_ans[0] << ", " << user_ans[1] << "]\n";
  assert(c1_ans[0] == user_ans[0] && c1_ans[1] == user_ans[1]);
  cout << "Passed!" << "\n";

  // case 2
  vector<int> c2 = {2,3,4};
  vector<int> c2_ans = {1, 3};
  int c2_target = 6;

  cout << "Expecting answer: " << "[" << c2_ans[0] << ", " << c2_ans[1] << "]";
  user_ans = twoSum(c2, c2_target);
  cout << " Got: " << "[" << user_ans[0] << ", " << user_ans[1] << "]\n";
  assert(c2_ans[0] == user_ans[0] && c2_ans[1] == user_ans[1]);
  cout << "Passed!" << "\n";

  // case 3
  vector<int> c3 = {-1,0};
  vector<int> c3_ans = {1, 2};
  int c3_target = -1;

  cout << "Expecting answer: " << "[" << c3_ans[0] << ", " << c3_ans[1] << "]";
  user_ans = twoSum(c3, c3_target);
  cout << " Got: " << "[" << user_ans[0] << ", " << user_ans[1] << "]\n";
  assert(c3_ans[0] == user_ans[0] && c3_ans[1] == user_ans[1]);
  cout << "Passed!" << "\n";

  // case 4
  vector<int> c4 = {5,25,75};
  vector<int> c4_ans = {2, 3};
  int c4_target = 100;

  cout << "Expecting answer: " << "[" << c4_ans[0] << ", " << c4_ans[1] << "]";
  user_ans = twoSum(c4, c4_target);
  cout << " Got: " << "[" << user_ans[0] << ", " << user_ans[1] << "]\n";
  assert(c4_ans[0] == user_ans[0] && c4_ans[1] == user_ans[1]);
  cout << "Passed!" << "\n\n";

  cout << "Congratulations! All tests passed." << endl;

  return 0;
}
