#include <string>
#include <cassert>
#include <cctype>
#include <iostream>

int lengthOfLastWord(std::string s) {
  int max = 0;

  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] != ' ') {
      max++;
    } else if (s[i] == ' ' && max > 0) {
      break;
    }
  }

  return max;
}

int main() {
  assert(lengthOfLastWord("Hello, World") == 5);
  assert(lengthOfLastWord("   fly me   to   the moon  ") == 4);
  assert(lengthOfLastWord("luffy is still joyboy") == 6);

  std::cout << "All tests passed.\n";

  return 0;
}
