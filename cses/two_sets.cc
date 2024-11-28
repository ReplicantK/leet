#include <iostream>
#include <vector>

int main() {
  double size = 0;
  std::cin >> size;

  long int total = (size / 2) * (1 + size);

  std::vector<int> v1;
  std::vector<int> v2;

  if (total % 2 == 0) {
    long int require = total / 2;

    long int st1 = 0;
    long int st2 = 0;

    long int rev = size;

    while (st1 < require || st2 < require) {
      if (rev != 0 && st1 + rev <= require) {
        st1 += rev;
        v1.push_back(rev);
        rev--;
      }

      if (rev != 0 && st2 + rev <= require) {
        st2 += rev;
        v2.push_back(rev);
        rev--;
      }
    }
  }

  if (v1.empty() && v2.empty()) {
    std::cout << "NO";
  } else {
    std::cout << "YES";
    std::cout << "\n" << v1.size() << "\n";

    for (int i : v1) {
      std::cout << i << " ";
    }

    std::cout << "\n" << v2.size() << "\n";
    for (int i : v2) {
      std::cout << i << " ";
    }
  }

  std::cout << std::endl;

  return 0;
}
