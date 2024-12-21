#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int size = 0;
  std::cin >> size;
  std::vector<int> v(size);

  for (int i = 0; i < size; i++) {
    int j = 0;
    std::cin >> j;
    v[i] = j;
  }

  std::sort(v.begin(), v.end());

  long long t = 0;

  for (int i : v) {
    if (i <= t + 1) {
      t += i;
    } else {
      break;
    }
  }

  std::cout << t + 1 << "\n";

  return 0;
}
