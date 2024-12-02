#include <iostream>
#include <fstream>
#include <vector>

int main() {
  std::ifstream in("cowsignal.in");
  std::ofstream out("cowsignal.out");

  int y = 0;
  int x = 0;
  int m = 0;
  in >> y >> x >> m;

  std::vector<std::vector<char>> v(y);

  for (int i = 0; i < y; i++) {
    std::vector<char> v2(x);
    char r;

    for (int j = 0; j < x; j++) {
      in >> r;
      v2[j] = r;
    }

    v[i] = v2;
  }

  std::vector<std::vector<char>> v_ans(y * m);

  int index_out = 0;

  for (auto i : v) {
    std::vector<char> v2_add(x * m);
    int index = 0;

    for (auto j : i) {
      for (int k = 0; k < m; index++, k++) {
        v2_add[index] = j;
      }
    }
    
    for (int j = 0; j < m; index_out++, j++) {
      v_ans[index_out] = v2_add; 
    }
  }

  for (auto i : v_ans) {
    for (auto j : i) {
      out << j;
    }
    
    out << std::endl;
  }

  return 0;
}
