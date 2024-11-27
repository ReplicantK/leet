#include <iostream>

int main() {
  long int n = 0;

  std::cin >> n;

  while (true) {
    std::cout << n << " ";

    if (n == 1) {
      std::cout << std::endl;
      break;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n *= 3;
      n += 1;
    }
  }

  return 0;
}
