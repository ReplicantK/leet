#include <iostream>
#include <vector>

using namespace std;

int max_profit(vector<int>& prices) {
  int least = INT_MAX;
  int profit = 0;
  int profit_sold_today = 0;

  for (int i = 0; i < prices.size(); i++) {
    if (prices.at(i) < least) {
      least = prices.at(i);
    }

    profit_sold_today = prices.at(i) - least;

    if (profit < profit_sold_today) {
      profit = profit_sold_today;
    }
  }

  return profit;
}

int main() {
  // the two test i will run
  vector<int> test1;
  vector<int> test2;
  vector<int> test3;
  vector<int> test4;
  vector<int> test5;

  // filling in test 1
  test1.push_back(7);
  test1.push_back(1);
  test1.push_back(5);
  test1.push_back(3);
  test1.push_back(6);
  test1.push_back(4);

  // filling in test 2
  test2.push_back(7);
  test2.push_back(6);
  test2.push_back(4);
  test2.push_back(3);
  test2.push_back(1);

  // filling in test 3
  test3.push_back(2);
  test3.push_back(1);
  test3.push_back(2);
  test3.push_back(0);
  test3.push_back(1);

  // filling in test 4
  test4.push_back(3);
  test4.push_back(2);
  test4.push_back(6);
  test4.push_back(5);
  test4.push_back(0);
  test4.push_back(3);

  // filling in test 5
  test5.push_back(1);

  cout << max_profit(test1) << endl;
  cout << max_profit(test2) << endl;
  cout << max_profit(test3) << endl;
  cout << max_profit(test4) << endl;
  cout << max_profit(test5) << endl;

  return 0;
}
