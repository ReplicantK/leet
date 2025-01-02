#include <iostream>
#include <vector>

std::vector<std::vector<int>> Generate(int  numRows) {
  std::vector<std::vector<int>> a;
  a.reserve(numRows);

  for (int i = 0; i < numRows; i++) {
    std::vector<int> c;
    c.reserve(i + 1);

    if (i + 1 <= 2) {
      for (int j = 0; j < i + 1; j++) {
        c.emplace_back(1);
      }
    } else {
      c.emplace_back(1);

      for (int j = 0; j < a.back().size() - 1; j++) {
        c.emplace_back(a.back()[j] + a.back()[j + 1]);
      }

      c.emplace_back(1);
    }

    a.emplace_back(c);
  }

  return a;
}

void VPrinter(std::vector<std::vector<int>> ans) {
  std::cout << "[";

  for (int i = 0; i < ans.size() - 1; i++) {
    std::cout << "[";
    for (int j = 0; j < ans[i].size() - 1; j++) {
      std::cout << ans[i][j] << ",";
    }
    std::cout << ans[i].back() << "],";
  }

  std::cout << "[";

  for (int i = 0; i < ans.back().size() - 1; i++) {
    std::cout << ans.back()[i] << ",";
  }

  std::cout << ans.back().back() << "]]";
}

int main() {
  std::cout << "CASE1\nExpected: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]";
  std::cout << "\nReceived: ";
  VPrinter(Generate(5));

  std::cout << "\n\nCASE2\nExpected: [[1]]\nReceived: ";
  VPrinter(Generate(1));
  std::cout << "\n";

  return 0;
}
