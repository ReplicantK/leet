#include <iostream>
#include <unordered_map>

int main() {
  int loop = 0;
  std::cin >> loop;

  std::unordered_map<int, int> mp;

  for (int i = 1; i <= loop; i++) {
    int read_num = 0;
    std::cin >> read_num;

    mp[read_num] = i;
  }

  int rounds = 1;

  for (int i = 2; i <= loop; i++) {
    if (mp.at(i) < mp.at(i - 1)) {
      rounds++;
    }
  }

  std::cout << rounds << std::endl;

  return 0;
}
