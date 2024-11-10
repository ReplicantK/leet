#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
  // test case 1
  vector<int> nums = {1,1,1,2,2,3};
  int k = 2;

  // test case 2
  //vector<int> nums = {3,0,1,0};
  //int k = 1;

  // solution
  unordered_map<int, int> mp;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

  for (int i = 0; i < nums.size(); i++) {
    mp[nums.at(i)]++;
  }

  for (unordered_map<int, int>::iterator i = mp.begin(); i != mp.end(); i++) {
    if (q.size() < k) {
      q.push(make_pair(i->second, i->first));
      continue;
    }

    if (q.top().first < i->second) {
      q.pop();
      q.push(make_pair(i->second, i->first));
    }
  }

  nums.clear();
  while (q.size()) {
    nums.push_back(q.top().second);
    q.pop();
  }

  for (int i = 0; i < nums.size(); i++) {
    cout << nums.at(i) << endl;
  }

  return 0;
}
