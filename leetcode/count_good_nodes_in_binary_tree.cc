#include <iostream>
#include <climits>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int goodNodes(TreeNode* root, int mem = INT_MIN) {
  if (!root) {
    return 0;
  }

  int thisStackFrame = 0;
  if (root->val >= mem) {
    mem = root->val;
    thisStackFrame = 1;
  }

  int left = goodNodes(root->left, mem);
  int right = goodNodes(root->right, mem);

  return thisStackFrame + left + right;
}

void freeNodes(TreeNode* root) {
  if (!root) {
    return;
  }

  freeNodes(root->left);
  freeNodes(root->right);

  delete(root);
}

int main() {
  // case 1
  TreeNode* root = new TreeNode(
    3, new TreeNode(1, new TreeNode(3), nullptr),
    new TreeNode(4, new TreeNode(1), new TreeNode(5))
  );

  std::cout << "CASE1\nExpected: 4\nReceived: " << goodNodes(root) << "\n\n";
  freeNodes(root);

  // case 2
  root = new TreeNode(
    3, new TreeNode(3, new TreeNode(4), new TreeNode(2)), nullptr
  );

  std::cout << "CASE2\nExpected: 3\nReceived: " << goodNodes(root) << "\n\n";
  freeNodes(root);

  // case 3
  root = new TreeNode(1);

  std::cout << "CASE3\nExpected: 1\nReceived: " << goodNodes(root) << "\n\n";
  freeNodes(root);

  // case 4
  root = new TreeNode(
    9, nullptr, new TreeNode(3, new TreeNode(6), nullptr)
  );

  std::cout << "CASE4\nExpected: 1\nReceived: " << goodNodes(root) << "\n\n";
  freeNodes(root);

  // case 5
  root = new TreeNode(
    -1, new TreeNode(5, new TreeNode(4),
    new TreeNode(4, new TreeNode(-4, new TreeNode(0, new TreeNode(3),
    nullptr), nullptr), nullptr)),
    new TreeNode(-2, new TreeNode(2, new TreeNode(-2, new TreeNode(-1), nullptr),
    new TreeNode(3, new TreeNode(-3), nullptr)),
    new TreeNode(-2, nullptr, new TreeNode(-2, new TreeNode(-4),
    new TreeNode(-3, new TreeNode(3), new TreeNode(-3)))))
  );

  std::cout << "CASE4\nExpected: 5\nReceived: " << goodNodes(root) << std::endl;
  freeNodes(root);
  
  return 0;
}
