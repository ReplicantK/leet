#include <iostream>
#include <string>

int main() {
  int tests = 0;
  std::cin >> tests;

  for (int i = 0; i < tests; i++) {
    int n = 0;
    std::cin >> n;

    if (n == 1 || n == 3) {
      std::cout << "-1";
    } else if (n == 2) {
      std::cout << "66";
    } else if (n == 5) {
      std::cout << "36366";
    } else if (n % 2 == 0) {
      for (int i = 0; i < n - 2; i++) {
        std::cout << "3";
      }
      std::cout << "66";
    } else {
      for (int i = 0; i < n - 5; i++) {
        std::cout << "3";
      }
      std::cout << "36366";
    }

    std::cout << "\n";
  }

  return 0;
}
