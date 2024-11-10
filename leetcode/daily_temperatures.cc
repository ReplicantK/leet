#include <iostream>
#include <stack>
#include <vector>

std::vector<int> dailyTemperatures(const std::vector<int>& temperatures) {
  std::vector<int> ans(temperatures.size());
  std::stack<int> st;
  st.push(0);

  for (int i = 1; i < temperatures.size(); i++) {
    while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
      ans[st.top()] = i - st.top();
      st.pop();
    }

    st.push(i);
  }

  return ans;
}

void vPrinter(const std::vector<int>& v) {
  std::cout << "[";
  for (int i = 0; i < v.size() - 1; i++) {
    std::cout << v[i] << ",";
  }
  std::cout << v[v.size() - 1] << "]";
}

int main() {
  std::cout << "CASE 1\n";
  vPrinter(dailyTemperatures({73, 74, 75, 71, 69, 72, 76, 73}));
  std::cout << " -got\n[1,1,4,2,1,1,0,0] -expected\n\n";

  std::cout << "CASE 2\n";
  vPrinter(dailyTemperatures({30, 40, 50, 60}));
  std::cout << " -got\n[1,1,1,0] -expected\n\n";

  std::cout << "CASE 3\n";
  vPrinter(dailyTemperatures({30, 60, 90}));
  std::cout << " -got\n[1,1,0] -expected"<< std::endl;

  return 0;
}
