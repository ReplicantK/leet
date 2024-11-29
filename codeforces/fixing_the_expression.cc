#include <iostream>
#include <string>

int main() {
  int tests = 0;
  std::cin >> tests;

  for (int i = 0; i < tests; i++) {
    std::string s = "";
    std::cin >> s;

    std::string num1s = "";
    num1s += (s[0]);

    std::string num2s = "";
    num2s += (s[2]);

    int n1 = std::stoi(num1s);
    int n2 = std::stoi(num2s);

    if (n1 > n2 && s[1] != '>') {
      std::cout << n1 << ">" << n2 << "\n";
    } else if (n1 < n2 && s[1] != '<') {
      std::cout << n1 << "<" << n2 << "\n";
    } else if (n1 == n2 && s[1] != '=') {
      std::cout << n1 << "=" << n2 << "\n";
    } else {
      std::cout << s << "\n";
    }
  }

  return 0;
}
