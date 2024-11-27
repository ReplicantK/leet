#include <iostream>
#include <vector>

int main() {
  long int arr_sz = 0;
  std::cin >> arr_sz;

  long int last = 0;
  std::cin >> last;
  long int current = 0;

  long int require = 0;

  for (int i = 1; i < arr_sz; i++) {
    std::cin >> current;

    if (current < last) {
      require += (last - current);
    } else {
      last = current;
    }
  }

  std::cout << require << std::endl;

  return 0;
}
