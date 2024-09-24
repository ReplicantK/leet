#include <iostream>
#include <vector>

using namespace std;

class MinStack {
  private:
    vector<int> vec;
    int min = INT_MAX;

  public:
    MinStack() {

    }

    void push(int val) {
      if (val < min) {
        min = val;
      }

      vec.push_back(val);
    }

    void pop() {
      int popped = vec.at(vec.size() - 1);
      vec.pop_back();

      if (popped == min) {
        min = INT_MAX;
        for (int i = 0; i < vec.size(); i++) {
          if (vec.at(i) < min) {
            min = vec.at(i);
          }
        }
      } 
    }

    int top() {
      return vec.at(vec.size() - 1);
    }

    int getMin() {
      return min;
    }

    void test() {
      for (auto it = vec.begin(); it != vec.end(); it++) {
        cout << *it << " ";
      }

      cout << endl;
    }
};

int main() {
  MinStack* minStack = new MinStack();

  // test case
  minStack->push(5);
  minStack->push(3);
  minStack->push(4);

  cout << minStack->getMin() << endl;
  minStack->pop();
  minStack->pop();
  cout << minStack->top() << endl;
  cout << minStack->getMin() << endl;

  return 0;
}
