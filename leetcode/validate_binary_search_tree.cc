#include <iostream>
#include <climits>

struct TreeNode {
  long int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(long int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(long int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// solution
long int last = LONG_MIN;

bool isValidBST(TreeNode* root) {
  if (!root) {
    return true;
  }

  if (!isValidBST(root->left) || root->val <= last) {
    return false;
  }

  last = root->val;
  return isValidBST(root->right);
}

// clean up
void freeNodes(TreeNode* root) {
  if (!root) {
    return;
  }

  freeNodes(root->left);
  freeNodes(root->right);

  delete(root);
}

// driver
int main() {
  // case 1
  TreeNode* root = new TreeNode(2, new TreeNode(1), new TreeNode(3));

  std::cout << "CASE1\nExpected: true\nReceived: ";
  if (isValidBST(root)) {
    std::cout << "true\n\n";
  } else {
    std::cout << "false\n\n";
  }
  freeNodes(root);
  last = LONG_MIN;

  // case 2
  root = new TreeNode(
    5, new TreeNode(1), new TreeNode(4, new TreeNode(3), new TreeNode(6))
  );

  std::cout << "CASE2\nExpected: false\nReceived: ";
  if (isValidBST(root)) {
    std::cout << "true\n\n";
  } else {
    std::cout << "false\n\n";
  }
  freeNodes(root);
  last = LONG_MIN;

  // case 3
  root = new TreeNode(-2147483648);

  std::cout << "CASE3\nExpected: true\nReceived: ";
  if (isValidBST(root)) {
    std::cout << "true\n\n";
  } else {
    std::cout << "false\n\n";
  }
  freeNodes(root);
  last = LONG_MIN;

  // case 4
  root = new TreeNode(2, new TreeNode(2), new TreeNode(2));

  std::cout << "CASE4\nExpected: false\nReceived: ";
  if (isValidBST(root)) {
    std::cout << "true" << std::endl;
  } else {
    std::cout << "false" << std::endl;
  }
  freeNodes(root);

  return 0;
}
