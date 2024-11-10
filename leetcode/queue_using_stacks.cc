#include <iostream>
#include <vector>

using namespace std;

class MyQueue {
  private: 
    vector<int> vec;

  public: 
    MyQueue() {

    }

    void push(int x) {
      vec.push_back(x);
    }

    int pop() {
      int value = *vec.begin();

      vec.erase(vec.begin());

      return value;
    }

    int peek() {
      return *vec.begin();
    }

    bool empty() {
      return vec.empty();
    }

};

int main() {
  MyQueue* my = new MyQueue();

  // test case
  my->push(1);
  my->push(2);

  cout << my->peek() << endl;
  cout << my->pop() << endl;
  cout << my->empty() << endl;

  return 0;
}
