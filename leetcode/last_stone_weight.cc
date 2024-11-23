#include <iostream>
#include <queue>
#include <vector>

class Solution {
 public:
  int lastStoneWeight(std::vector<int> stones) {
    std::priority_queue<int> pq;

    for (int i : stones) {
      pq.push(i);
    }

    while (!pq.empty()) {
      if (pq.size() == 1) {
        return pq.top();
      }

      int a = pq.top();
      pq.pop();
      int b = pq.top();
      pq.pop();

      if (a - b > 0) {
        pq.push(a - b);
      }
    }

    return 0;
  }
};

int main() {
  Solution* s = new Solution();
  std::cout << "CASE1\nExpected: 1\nReceived: ";
  std::cout << s->lastStoneWeight({2,7,4,1,8,1}) << "\n\n";
  delete(s);

  s = new Solution();
  std::cout << "CASE2\nExpected: 1\nReceived: ";
  std::cout << s->lastStoneWeight({1}) << std::endl;
  delete(s);

  return 0;
}
