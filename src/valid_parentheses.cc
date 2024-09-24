#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_valid(string s) {
  bool valid = true;
  vector<char> save;

  for (int i = 0; i < s.length(); i++) {
    if ((s.at(i) == '{') || (s.at(i) == '(') || (s.at(i) == '[')) {
      save.push_back(s.at(i));
    } else if (((s.at(i) == '}') || (s.at(i) == ')') || (s.at(i) == ']')) && s.length() > 1 && i != 0 && save.size() != 0) {
      if (save.at(save.size() - 1) == '{') {
        if (s.at(i) != '}') {
          valid = false;
        } else {
          save.pop_back();
        }
      } else if (save.at(save.size() - 1) == '(') {
        if (s.at(i) != ')') {
          valid = false;
        } else {
          save.pop_back();
        }
      } else if (save.at(save.size() - 1) == '[') {
        if (s.at(i) != ']') {
          valid = false;
        } else {
          save.pop_back();
        }
      } else {
        valid = false;
      }
    }
  }

  if ((s.length() < 2) || (save.size() != 0)) {
    valid = false;
  }

  return valid;
}

int main() {
  //string s = "";
  //string s = "[";
  //string s = "]";
  //string s = "((";
  //string s = "()";
  //string s = "()[]{}";
  //string s = "(]";
  //string s = "{[]}";
  //string s = "{[](}}";
  string s = "(){()}}{";

  cout << is_valid(s) << endl;

  return 0;
}
