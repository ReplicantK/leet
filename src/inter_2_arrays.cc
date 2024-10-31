#include <vector>
#include <unordered_set>
#include <iostream>

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
  std::unordered_set<int> s;
  std::vector<int> ans;

  for (int i : nums1) {
    s.insert(i);
  }

  for (int i : nums2) {
    if (s.contains(i)) {
      ans.push_back(i);
      s.erase(i);
    }
  }

  return ans;
}

void vPrinter(const std::vector<int>& ans) {
  std::cout << "[";
  for (int i = 0; i < ans.size() - 1; i++) {
    std::cout << ans[i] << ",";
  }
  std::cout << ans[ans.size() - 1] << "]";
}

int main() {
  std::vector<int> nums1case1 = {1,2,2,1};
  std::vector<int> nums2case1 = {2,2};

  std::cout << "CASE 1\ngot ";
  vPrinter(intersection(nums1case1, nums2case1));
  std::cout << "\nexpected [2]\n\n";

  std::vector<int> nums1case2 = {4,9,5};
  std::vector<int> nums2case2 = {9,4,9,8,4};

  std::cout << "CASE 2\ngot ";
  vPrinter(intersection(nums1case2, nums2case2));
  std::cout << "\nexpected [4,9]" << std::endl;;

  return 0;
}
