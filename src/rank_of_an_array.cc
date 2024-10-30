#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

std::vector<int> arrayRankTransform(const std::vector<int>& arr) {
  std::vector<int> sorted = arr;
  std::sort(sorted.begin(), sorted.end());

  std::unordered_map<int, int> mp;
  int rank = 1;
  for (int i = 0; i < sorted.size(); i++) {
    if (!mp.contains(sorted[i])) {
      mp[sorted[i]] = rank;
      rank++;
    }
  }

  std::vector<int> ans(arr.size());
  for (int i = 0; i < arr.size(); i++) {
    ans[i] = mp[arr[i]];
  }

  return ans;
}

void vectorPrinter(const std::vector<int>& arr) {
  std::cout << "[";
  for (int i = 0; i < arr.size() - 1; i++) {
    std::cout << arr[i] << ","; 
  }
  std::cout << arr[arr.size() - 1] << "]";
}

int main() {
  std::cout << "CASE 1\n";
  std::cout << "got      ";
  vectorPrinter(arrayRankTransform({40, 10, 20, 30}));
  std::cout << "\nexpected [4,1,2,3]\n\n";

  std::cout << "CASE 2\n";
  std::cout << "got      ";
  vectorPrinter(arrayRankTransform({100, 100, 100}));
  std::cout << "\nexpected [1,1,1]\n\n";

  std::cout << "CASE 3\n";
  std::cout << "got      ";
  vectorPrinter(arrayRankTransform({37, 12, 28, 9, 100, 56, 80, 5, 12}));
  std::cout << "\nexpected [5,3,4,2,8,6,7,1,3]" << std::endl;

  return 0;
}
