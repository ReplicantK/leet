#include <string>
#include <cassert>
#include <cctype>
#include <iostream>

using namespace std;

int lengthOfLastWord(string s) {
  int length = 0;
  int index = 0;

  // find the first letter of the word at the end
  for (int i = s.length() - 1; i > 0; i--) {
    if (!isalpha(s[i])) {
      continue;
    }

    index = i;
    break;
  }

  while (isalpha(s[index])) {
    length++;
    index--;

    if (index < 0) {
      break;
    }
  }

  return length;
}

int main() {
  assert(lengthOfLastWord("Hello, World") == 5);
  assert(lengthOfLastWord("   fly me   to   the moon  ") == 4);
  assert(lengthOfLastWord("luffy is still joyboy") == 6);

  cout << "All tests passed." << endl;

  return 0;
}
