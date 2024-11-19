#include <iostream>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int recurse(TreeNode* root, int& d) {
  if (!root) {
    return 0;
  }

  int left = recurse(root->left, d);
  int right = recurse(root->right, d);

  if (left + right > d) {
    d = left + right;
  }

  if (left > right) {
    return left + 1;
  }

  return right + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
  int d = 0;
  recurse(root, d);
  return d;
}

void deleteNodes(TreeNode* root) {
  if (!root) {
    return;
  }

  deleteNodes(root->left);
  deleteNodes(root->right);

  delete(root);
  return;
}

int main() {
  // test case 1
  TreeNode* root = new TreeNode(
    1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3)
  );

  int d = diameterOfBinaryTree(root);
  std::cout << "CASE 1\nExpected: 3\nReceived: " << d << "\n\n";
  deleteNodes(root);

  // test case 2
  root = new TreeNode(1, new TreeNode(2), nullptr);

  d = diameterOfBinaryTree(root);
  std::cout << "CASE 2\nExpected: 1\nReceived: " << d << "\n\n";
  deleteNodes(root);
  
  // test case 3
  root = new TreeNode(4, new TreeNode(-7), new TreeNode(-3,
    new TreeNode(-9, new TreeNode(9, new TreeNode(6,
    new TreeNode(0, nullptr, new TreeNode(-1)), new TreeNode(6,
    new TreeNode(-4), nullptr)), nullptr), new TreeNode(-7,
    new TreeNode(-6, new TreeNode(5), nullptr), new TreeNode(-6,
    new TreeNode(9, new TreeNode(-2), nullptr), nullptr))),
    new TreeNode(-3, new TreeNode(-4), nullptr))
  );

  d = diameterOfBinaryTree(root);
  std::cout << "CASE 3\nExpected: 8\nReceived: " << d << std::endl;
  deleteNodes(root);

  return 0;
}
