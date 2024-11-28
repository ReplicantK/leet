#include <iostream>
#include <vector>

int main() {
  int sz = 0;
  std::cin >> sz;

  int last = sz - 1;
  if (sz == 1) {
    last = sz;
  } else {
    last = sz - 1;
  }

  std::vector<int> arr(sz);
  arr[0] = last;
  bool sol = true;

  for (int i = 1; i < sz; i++) {
    int current = arr[i - 1] - 2;

    if (current <= 0) {
      current = sz;

      if (current - arr[i - 1] < 2) {
        sol = false;
        break;
      }
    } else {
      if (arr[i - 1] - current < 2) {
        sol = false;
        break;
      }
    }

    arr[i] = current;
  }

  if (sol) {
    for (int i : arr) {
      std::cout << i << " ";
    }
  } else {
    std::cout << "NO SOLUTION";
  }

  std::cout << std::endl;

  return 0;
}
