#include <iostream>
#include <unordered_set>
#include <string>

char repeatedCharacter(const std::string& s) {
  std::unordered_set<char> us;
  char ans = '0';

  for (char i : s) {
    if (us.contains(i)) {
      ans = i;
      break;
    } else {
      us.insert(i);
    }
  }

  return ans;
}

int main() {
  std::cout << "CASE 1\n" << repeatedCharacter("abccbaacz") << " -got\n";
  std::cout << "c -expected\n\n";

  std::cout << "CASE 2\n" << repeatedCharacter("abcdd") << " -got\n";
  std::cout << "d -expected" << std::endl;

  return 0;
}
