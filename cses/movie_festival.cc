#include <functional>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

int main() {
  int n = 0;
  std::cin >> n;

  std::vector<std::pair<int, int>> v;
  v.reserve(n);

  for (int i = 0; i < n; i++) {
    int s = 0, e = 0;
    std::cin >> s >> e;

    v.push_back({s, e});
  }

  std::sort(v.begin(), v.end(), std::greater<>());

  int max = 1;
  std::pair<int, int> last = v[0];
  
  for (int i = 1; i < v.size(); i++) {
    if (v[i].second <= last.first) {
      max++;
      last = v[i];
    }
  }

  std::cout << max << "\n";

  return 0;
}
