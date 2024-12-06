#include <iostream>
#include <vector>
#include <string>

class Solution {
 public:
  int n_ = 0;
  std::vector<std::string> v_;

  void Dfs(int o, int c, std::string s) {
    if (o == n_ && c == n_) {
      v_.push_back(s);
      return;
    }
    
    if (o < n_) {
      std::string curr = s + '(';
      Dfs(o + 1, c, curr);
    }

    if (c < o) {
      std::string curr = s + ')';
      Dfs(o, c + 1, curr);
    }
  }
  
  std::vector<std::string> GenerateParenthesis(int n) {
    n_ = n;
    Dfs(0, 0, "");
    return v_;
  }
};

int main() {
  Solution s;
  std::cout << "CASE1\nExpected: ((())),(()()),(())(),()(()),()()()\n";
  std::cout << "Received: ";
  std::vector<std::string> v = s.GenerateParenthesis(3);

  std::cout << v[0];
  for (int i = 1; i < v.size(); i++) {
    std::cout << "," << v[i];
  }

  Solution s1;
  std::cout << "\n\nCASE2\nExpected: ()\n";
  std::cout << "Received: ";
  v = s1.GenerateParenthesis(1);
  std::cout << v[0] << "\n";

  return 0;
}
