#include <iostream>
#include <string>
#include <set>

void CreateStrings(std::string last, std::string ops, std::set<std::string>& st) {
  if (ops.empty()) {
    st.insert(last);
    return;
  }

  for (int i = 0; i < ops.size(); i++) {
    std::string new_ops = ops;
    new_ops.erase(new_ops.begin() + i);

    std::string new_last = last + ops[i];

    CreateStrings(new_last, new_ops, st);
  }
}

int main() {
  std::string init;
  std::set<std::string> st;

  std::cin >> init;

  CreateStrings("", init, st);

  std::cout << st.size() << "\n";
  for (std::string i : st) {
    std::cout << i << "\n";
  }

  return 0;
}
