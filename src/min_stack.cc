#include <iostream>
#include <list>

class MinStack {
  private:
    std::list<int> st;
    std::list<int> minSt;

  public:
    MinStack() {
    }

    void push(int val) {
      if (minSt.empty() || val <= minSt.back()) {
        minSt.push_back(val);
      }

      st.push_back(val);
    }

    void pop() {
      if (st.back() == minSt.back()) {
        minSt.pop_back();
      }

      st.pop_back();
    }

    int top() {
      return st.back();
    }

    int getMin() {
      return minSt.back();
    }
};

int main() {
  MinStack case1;
  std::cout << "CASE 1\n";
  case1.push(-2);
  case1.push(0);
  case1.push(-3);
  std::cout << "getMin(): got " << case1.getMin() << ", expected -3\n";
  case1.pop();
  std::cout << "top()   : got " << case1.top() << ", expected 0\n";
  std::cout << "getMin(): got " <<  case1.getMin() << ", expected -2\n";

  MinStack case2;
  std::cout << "\nCASE 2\n";
  case2.push(2);
  case2.push(0);
  case2.push(3);
  case2.push(0);
  std::cout << "getMin(): got " << case2.getMin() << ", expected 0\n";
  case2.pop();
  std::cout << "getMin(): got " << case2.getMin() << ", expected 0\n";
  case2.pop();
  std::cout << "getMin(): got " << case2.getMin() << ", expected 0\n";
  case2.pop();
  std::cout << "getMin(): got " << case2.getMin() << ", expected 2" << std::endl;

  return 0;
}
