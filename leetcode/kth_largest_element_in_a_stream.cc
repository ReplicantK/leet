#include <queue>
#include <vector>
#include <functional>
#include <iostream>

// solution
class KthLargest {
 public:
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
  int k = 0;

  KthLargest(int k, std::vector<int> nums) {
    this->k = k;

    for (int i : nums) {
      if (pq.size() < k) {
        pq.push(i);
      } else if (i > pq.top()) {
        pq.pop();
        pq.push(i);
      }
    }
  }

  int add(int val) {
    if (pq.size() < k) {
      pq.push(val);
    } else if (val > pq.top()) {
      pq.pop();
      pq.push(val);
    }

    return pq.top();
  }
};

int main() {
  // case 1
  KthLargest* obj = new KthLargest(3, {4,5,8,2});
  std::cout << "CASE1\n";
  std::cout << "Expected: 4\n";
  std::cout << "Received: " << obj->add(3) << "\n\n";

  std::cout << "Expected: 5\n";
  std::cout << "Received: " << obj->add(5) << "\n\n";

  std::cout << "Expected: 5\n";
  std::cout << "Received: " << obj->add(10) << "\n\n";

  std::cout << "Expected: 8\n";
  std::cout << "Received: " << obj->add(9) << "\n\n";

  std::cout << "Expected: 8\n";
  std::cout << "Received: " << obj->add(4) << "\n\n";
  delete(obj);

  // case 2
  obj = new KthLargest(4, {7,7,7,7,8,3});
  std::cout << "CASE2\n";
  std::cout << "Expected: 7\n";
  std::cout << "Received: " << obj->add(2) << "\n\n";

  std::cout << "Expected: 7\n";
  std::cout << "Received: " << obj->add(10) << "\n\n";
  
  std::cout << "Expected: 7\n";
  std::cout << "Received: " << obj->add(9) << "\n\n";

  std::cout << "Expected: 8\n";
  std::cout << "Received: " << obj->add(9) << "\n\n";
  delete(obj);

  // case 3
  obj = new KthLargest(1, {});
  std::cout << "CASE3\n";
  std::cout << "Expected: -3\n";
  std::cout << "Received: " << obj->add(-3) << "\n\n";

  std::cout << "Expected: -2\n";
  std::cout << "Received: " << obj->add(-2) << "\n\n";
  
  std::cout << "Expected: -2\n";
  std::cout << "Received: " << obj->add(-4) << "\n\n";

  std::cout << "Expected: 0\n";
  std::cout << "Received: " << obj->add(0) << "\n\n";
  
  std::cout << "Expected: 4\n";
  std::cout << "Received: " << obj->add(4) << std::endl;
  delete(obj);

  return 0;
}
