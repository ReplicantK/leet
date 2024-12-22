#include <iostream>
#include <unordered_set>

int main() {
  int n = 0; 
  std::cin >> n;

  std::unordered_set<int> st;
  // reserve little above required buckets to avoid rehashing by
  // hitting the load factor trigger
  st.reserve(1.5 * n);

  for (int i = 0; i < n; i++) {
    int num = 0;
    std::cin >> num;
    st.emplace(num);
  }

  std::cout << st.size() << "\n";

  return 0;
}
