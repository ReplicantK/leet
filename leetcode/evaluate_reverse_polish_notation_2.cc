#include <iostream>
#include <string>
#include <stack>

class Solution {
 public:
  int EvalRPN(std::vector<std::string> tokens) {
    std::stack<int> st;

    for (std::string i : tokens) {
      if (i == "+") {
        int b = st.top();
        st.pop();
        int a = st.top();
        st.pop();

        st.push(a + b);
      } else if (i == "-") {
        int b = st.top();
        st.pop();
        int a = st.top();
        st.pop();

        st.push(a - b);
      } else if (i == "*") {
        int b = st.top();
        st.pop();
        int a = st.top();
        st.pop();

        st.push(a * b);
      } else if (i == "/") {
        int b = st.top();
        st.pop();
        int a = st.top();
        st.pop();

        st.push(a / b);
      } else {
        st.push(std::stoi(i));
      }
    }

    return st.top();
  }
};

int main() {
  Solution s;
  std::cout << "CASE1\nExpected: 9\nReceived: "; 
  std::cout << s.EvalRPN({"2","1","+","3","*"}) << "\n\n";

  std::cout << "CASE2\nExpected: 6\nReceived: "; 
  std::cout << s.EvalRPN({"4","13","5","/","+"}) << "\n\n";

  std::cout << "CASE3\nExpected: 22\nReceived: "; 
  std::cout << s.EvalRPN(
    {"10","6","9","3","+","-11","*","/","*","17","+","5","+"}
  ) << "\n";

  return 0;
}
