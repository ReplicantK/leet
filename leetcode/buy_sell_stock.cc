#include <iostream>
#include <vector>

int maxProfit(std::vector<int>& prices) {
  int answer = 0;

  std::vector<int>::iterator it1 = prices.begin();
  std::vector<int>::iterator it2 = prices.begin() + 1;

  while (it2 != prices.end()) {
    if (*it1 >= *it2) {
      it1 = it2;
      it2++;
      continue;
    }

    if ((*it2 - *it1) > answer) {
      answer = (*it2 - *it1);
    }

    it2++;
  }

  return answer;
}

int main() {
  std::vector<int> case1 = {7, 1, 5, 3, 6, 4};
  std::vector<int> test2 = {7, 6, 4, 3, 1};
  std::vector<int> test3 = {2, 1, 2, 0, 1};
  std::vector<int> test4 = {3, 2, 6, 5, 0, 3};
  std::vector<int> test5 = {1};

  std::cout << "expected: 5, got: " << maxProfit(case1) << "\n";
  std::cout << "expected: 0, got: " << maxProfit(test2) << "\n";
  std::cout << "expected: 1, got: " << maxProfit(test3) << "\n";
  std::cout << "expected: 4, got: " << maxProfit(test4) << "\n";
  std::cout << "expected: 0, got: " << maxProfit(test5) << std::endl;

  return 0;
}
