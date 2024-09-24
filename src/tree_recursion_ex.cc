#include <iostream>

using namespace std;

class Node {
  private:
    int value;
    Node* left;
    Node* right;

  public:
    Node(int num = 0, Node* left_side = nullptr, Node* right_side = nullptr) {
      this->value = num; 
      this->left = left_side; 
      this->right = right_side; 
    }

    int getValue() {
      return this->value;
    }

    Node* getLeft() {
      return this->left;
    }

    Node* getRight() {
      return this->right;
    }
};

Node* recursion(Node* parent, int match) {
  if (parent == nullptr) {
    return nullptr;
  } else if (parent->getValue() == match) {
    return parent;
  }

  Node* left = recursion(parent->getLeft(), match);
  if (left != nullptr) {
    return left;
  }

  Node* right = recursion(parent->getRight(), match);
  if (right != nullptr) {
    return right;
  }

  return nullptr;
}

int main() {
  Node* root = new Node(5, new Node(7), new Node(9, new Node(1), new Node(6)));
  int match = 6;

  Node* foundOrNot = recursion(root, match);

  if (foundOrNot != nullptr) {
    cout << "node " << foundOrNot << "'s value ";
    cout << foundOrNot->getValue() << " matches " << match << endl;
  } else {
    cout << "tree does not contain " << match << endl;
  }

  delete(root);
  return 0;
}
