#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

bool UniqueOccurrences(std::vector<int> arr) {
  std::sort(arr.begin(), arr.end());
  std::unordered_set<int> st;

  int counter = 1;

  for (int i = 0; i < arr.size(); i++) {
    if (i != arr.size() -  1 && arr[i] == arr[i + 1]) {
      counter++;
    } else if (!st.contains(counter)) {
      st.insert(counter);
      counter = 1;
    } else {
      return false;
    }
  }

  return true;
}

int main() {
  std::cout << "CASE1\nExpected: 1\nReceived: ";
  std::cout << UniqueOccurrences({1, 2, 2, 1, 1, 3}) << "\n\n";

  std::cout << "CASE2\nExpected: 0\nReceived: ";
  std::cout << UniqueOccurrences({1, 2}) << "\n\n";

  std::cout << "CASE3\nExpected: 1\nReceived: ";
  std::cout << UniqueOccurrences({-3, 0, 1, -3, 1, 1, 1, -3, 10, 0}) << "\n";

  return 0;
}
