#include <iostream>
#include <utility>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

pair<bool, int> level(TreeNode* node, int counter) {
  // one return  case
  if (node == nullptr) {
    return {true, counter};
  }

  // another return case
  pair<bool, int> left = level(node->left, counter + 1);
  pair<bool, int> right = level(node->right, counter + 1);

  if (left.first == false || right.first == false) {
    return {false, 0};
  }

  // last return case
  int greater = 0;
  int balance = true;
  if (left.second >= right.second) {
    greater = left.second;

    if (greater - right.second > 1) {
      balance = false;
    }
  } else if (right.second > left.second) {
    greater = right.second;

    if (greater - left.second > 1) {
      balance = false;
    }
  }

  return {balance, greater};
}

int main() {
  // test cases
  //TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
  //TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(3, new TreeNode(4), new TreeNode(4)), new TreeNode(3)), new TreeNode(2));

  TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(2));
  root->left->left = new TreeNode(3);
  root->left->left->left = new TreeNode(4);
  root->right->right = new TreeNode(3);
  root->right->right->right = new TreeNode(4);

  pair<bool, int> results = level(root, 1);

  if (results.first == true) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }

  return 0;
}
