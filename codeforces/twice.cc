#include <iostream>
#include <unordered_map>

int main() {
  int tests = 0;
  std::cin >> tests;

  for (int i = 0; i < tests; i++) {
    std::unordered_map<int, int> mp;
    int max = 0;

    int arr_sz = 0;
    std::cin >> arr_sz;

    for (int i = 0; i < arr_sz; i++) {
      int num = 0;
      std::cin >> num;

      if (arr_sz == 1) {
        continue;
      }

      mp[num]++;

      if (mp[num] % 2 == 0) {
        max++;
      }
    }

    std::cout << max << std::endl;
  }

  return 0;
}
