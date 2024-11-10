#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

int main() {
  vector<vector<int>> mat = {{1,1,0,0,0}, {1,1,1,1,0}, {1,0,0,0,0}, {1,1,0,0,0}, {1,1,1,1,1}};
  vector<pair<int, int>> vec;
  vector<int> vec2;

  int k = 3;

  for (int i = 0; i < mat.size(); i++) {
    int add = 0;

    for (auto j : mat.at(i)) {
      if (j == 1) {
        add++;
      }
    }

    vec.push_back(make_pair(add, i));
  }

  sort(vec.begin(), vec.end());

  for (int i = 0; i < k; i++) {
    vec2.push_back(vec.at(i).second);
  }

  return 0;
}
