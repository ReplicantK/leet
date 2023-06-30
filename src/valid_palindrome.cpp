#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool is_palindrome(string s) {
  bool answer = true;

  for (int i = 0; i < s.length(); i++) {
    s.at(i) = tolower(s.at(i));
  }

  for (int i = 0; i < s.length(); i++) {
    if (!((isdigit(s.at(i))) || (isalpha(s.at(i))))) {
      s.erase(i, 1);
      i--;
    }
  }

  for (int i = 0, j = s.length() - 1; i < floor((s.length() / 2)); j--, i++) {
    if (s.at(i) != s.at(j)) {
      answer = false;
      break;
    }
  }

  return answer;
}

int main() {
  string s1 = "A man, a plan, a canal: Panama";
  string s2 = "race a car";
  string s3 = "";
  string s4 = "0P";

  cout << is_palindrome(s1) << endl;
  cout << is_palindrome(s2) << endl;
  cout << is_palindrome(s3) << endl;
  cout << is_palindrome(s4) << endl;

  return 0;
}
