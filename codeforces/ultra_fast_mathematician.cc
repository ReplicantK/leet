#include <iostream>
#include <string>

int main() {
  std::string s1;
  std::string s2;

  std::cin >> s1 >> s2;

  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] != s2[i]) {
      s1[i] = '1';
    } else {
      s1[i] = '0';
    }
  }

  std::cout << s1 << std::endl;

  return 0;
}
