#include <iostream>
#include <algorithm>
#include <unordered_set>

int main() {
  int size = 0;
  std::cin >> size;
  std::unordered_set<int> s;

  for (int i = 0; i < size; i++) {
    s.insert(i + 1);
  }

  for (int i = 0; i < size - 1; i++) {
    int input = 0;
    std::cin >> input;

    if (s.contains(input)) {
      s.erase(input);
    }
  }

  std::cout << *s.begin() << std::endl;

  return 0;
}
