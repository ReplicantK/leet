#include <vector>
#include <iostream>
#include <functional>
#include <queue>

class Solution {
 public:
  int findKthLargest(std::vector<int> nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    for (int i : nums) {
      if (pq.size() < k) {
        pq.push(i);
      } else if (i > pq.top()) {
        pq.pop();
        pq.push(i);
      }
    }

    return pq.top();
  }
};

int main() {
  Solution s;
  std::cout << "CASE1\nExpected: 5\nReceived: ";
  std::cout << s.findKthLargest({3,2,1,5,6,4}, 2) << "\n\n";

  std::cout << "CASE2\nExpected: 4\nReceived: ";
  std::cout << s.findKthLargest({3,2,3,1,2,4,5,5,6}, 4) << std::endl;

  return 0;
}
