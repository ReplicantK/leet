#include <iostream>
#include <string>
#include <stack>

bool is_valid(std::string s) {
  std::stack<char> st;

  for (char i : s) {
    if (i == '(' || i == '{' || i == '[') {
      st.push(i);
      continue;
    }

    if (st.empty()) {
      return false;
    } else if (i == ']' && st.top() != '[') {
      return false;
    } else if (i == '}' && st.top() != '{') {
      return false;
    } else if (i == ')' && st.top() != '(') {
      return false;
    } 

    st.pop();
  }

  if (!st.empty()) {
    return false;
  }

  return true;
}

int main() {
  std::string s1 = "[";
  std::string s2 = "]";
  std::string s3 = "((";
  std::string s4 = "()";
  std::string s5 = "()[]{}";
  std::string s6 = "(]";
  std::string s7 = "{[]}";
  std::string s8 = "{[](}}";
  std::string s9 = "(){()}}{";

  std::cout << "case 1 got: " << is_valid(s1) << ", expected: 0\n";
  std::cout << "case 2 got: " << is_valid(s2) << ", expected: 0\n";
  std::cout << "case 3 got: " << is_valid(s3) << ", expected: 0\n";
  std::cout << "case 4 got: " << is_valid(s4) << ", expected: 1\n";
  std::cout << "case 5 got: " << is_valid(s5) << ", expected: 1\n";
  std::cout << "case 6 got: " << is_valid(s6) << ", expected: 0\n";
  std::cout << "case 7 got: " << is_valid(s7) << ", expected: 1\n";
  std::cout << "case 8 got: " << is_valid(s8) << ", expected: 0\n";
  std::cout << "case 9 got: " << is_valid(s9) << ", expected: 0" << std::endl;

  return 0;
}
