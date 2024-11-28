#include <iostream>

int main() {
  int size = 0;
  std::cin >> size;

  for (int i = 0; i < size; i++) {
    long int y = 0;
    long int x = 0;
    std::cin >> y >> x;

    long int diag = 0;

    if (y > x && y % 2 != 0) {
      diag = (y * y) - (y - 1);
      std::cout << diag - (y - x); 
    } else if (y > x && y % 2 == 0) {
      diag = (y * y) - (y - 1);
      std::cout << diag + (y - x);
    } else if (x > y && x % 2 != 0) {
      diag = (x * x) - (x - 1);
      std::cout << diag + (x - y);
    } else if (x > y && x % 2 == 0) {
      diag = (x * x) - (x - 1);
      std::cout << diag - (x - y);
    } else {
      diag = (y * y) - (y - 1);
      std::cout << diag;
    }

    std::cout << " ";
  }
  
  std::cout << std::endl;

  return 0;
}
