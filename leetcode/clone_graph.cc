#include <iostream>
#include <unordered_set>
#include <vector>

class Node {
 public:
  int val_;
  std::vector<Node*> neighbors_;

  Node() : val_(0), neighbors_(std::vector<Node*>()) {}
  Node(int val) : val_(val), neighbors_(std::vector<Node*>()) {}
  Node(int val, std::vector<Node*> neighbors) : val_(val), neighbors_(neighbors) {}
};

class Solution {
 public:
  std::unordered_map<Node*, Node*> mp_;

  Node* CloneGraph(Node* node) {
    if (!node) {
      return nullptr;
    } else if (mp_.contains(node)) {
      return mp_[node];
    }

    Node* add_this = new Node(node->val_);
    add_this->neighbors_.reserve(node->neighbors_.size());

    mp_[node] = add_this;

    for (int i = 0; i < node->neighbors_.size(); i++) {
      add_this->neighbors_.push_back(CloneGraph(node->neighbors_[i]));
    }

    return add_this;
  }
};

void PrintGraph(Node* n) {
  if (!n) {
    return;
  } else if (n->neighbors_.empty()) {
    std::cout << "[]";
    return;
  }

  std::unordered_set<Node*> done;
  std::stack<Node*> st;
  st.push(n);

  while (!st.empty()) {
    Node* c = st.top();
    st.pop();

    if (done.contains(c)) {
      continue;
    }

    if (done.empty()) {
      std::cout << "[";
    } else {
      std::cout << ",[";
    }

    for (int i = 0; i < c->neighbors_.size() - 1; i++) {
      if (!done.contains(c->neighbors_[i])) {
        st.push(c->neighbors_[i]);
      }

      std::cout << c->neighbors_[i]->val_ << ",";
    }

    if (!done.contains(c->neighbors_[c->neighbors_.size() - 1])) {
      st.push(c->neighbors_[c->neighbors_.size() - 1]);
    }

    std::cout << c->neighbors_[c->neighbors_.size() - 1]->val_ << "]";

    done.insert(c);
  }

  for (auto it = done.begin(); it != done.end(); it++) {
    delete(*it);
  }
}

int main() {
  // case 1
  Solution s;

  Node* head = new Node(1);
  Node* two = new Node(2);
  Node* three = new Node(3);
  Node* four = new Node(4);

  head->neighbors_.push_back(two);
  head->neighbors_.push_back(four);

  two->neighbors_.push_back(head);
  two->neighbors_.push_back(three);

  three->neighbors_.push_back(two);
  three->neighbors_.push_back(four);

  four->neighbors_.push_back(head);
  four->neighbors_.push_back(three);

  std::cout << "CASE1\nExpected: [[2,4],[1,3],[2,4],[1,3]]\nReceived: [";
  PrintGraph(s.CloneGraph(head));
  std::cout << "]\n\n";

  delete(head);
  delete(two);
  delete(three);
  delete(four);

  two = nullptr;
  three = nullptr;
  four = nullptr;

  // case 2
  head = new Node(1);
  std::cout << "CASE2\nExpected: [[]]\nReceived: [";
  PrintGraph(s.CloneGraph(head));
  std::cout << "]\n\n";
  delete(head);

  // case 3
  head = nullptr;
  std::cout << "CASE3\nExpected: []\nReceived: [";
  PrintGraph(s.CloneGraph(head));
  std::cout << "]" << std::endl;

  return 0;
}
