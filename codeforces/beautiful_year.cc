#include <iostream>
#include <string>
#include <unordered_set>

int main() {
  int year = 0;
  std::cin >> year;

  int prev_yr = year + 1;
  std::string s_new_yr = std::to_string(prev_yr);

  while (true) {
    std::unordered_set<char> st;
    bool good = true;

    for (char i : s_new_yr) {
      if (st.contains(i)) {
        good = false;
        break;
      } else {
        st.insert(i);
      }
    }

    if (good) {
      break;
    }

    prev_yr++;
    s_new_yr = std::to_string(prev_yr);
  }

  std::cout << s_new_yr << std::endl;

  return 0;
}
