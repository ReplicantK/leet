#include <stack>
#include <string>
#include <iostream>

int minLength(std::string s) {
  std::string::iterator it = s.begin();
  std::stack<char> st;
  int runningTotal = 0;

  while (it != s.end()) {
    if (st.empty()) {
      st.push(*it);
    } else if ((st.top() == 'A' && *it == 'B') || (st.top() == 'C' && *it == 'D')) {
      runningTotal += 2;
      st.pop();
    } else {
      st.push(*it);
    }

    it++;
  }

  return s.size() - runningTotal;
}

int main() {
  std::cout << "CASE 1\n" << "got " << minLength("ACDB") << "\nexpected 0\n\n";
  std::cout << "CASE 2\n" << "got " << minLength("ABFCACDB") << "\nexpected 2\n\n";
  std::cout << "CASE 3\n" << "got " << minLength("ACBBD") << "\nexpected 5" << std::endl;

  return 0;
}
