#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int currentCycle(TreeNode* root, bool& ans) {
  if (!root) {
    return 0;
  }

  int left = currentCycle(root->left, ans);
  int right = currentCycle(root->right, ans);
  int newDepth = 0;

  if (left > right) {
    newDepth = left + 1;
  } else {
    newDepth = right + 1;
  }

  if (ans && ((left - right > 1) || (right - left > 1))) {
    ans = false;
  }

  return newDepth;
}

bool isBalanced(TreeNode* root) {
  bool ans = true;
  currentCycle(root, ans);
  return ans;
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
    3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7))
  );
  
  std::cout << "CASE1\nExpected: true\nReceived: ";
  if (isBalanced(root)) {
    std::cout << "true\n\n";
  } else {
    std::cout << "false\n\n";
  }

  freeNodes(root);

  // case 2
  root = new TreeNode(
    1, new TreeNode(2, new TreeNode(3, new TreeNode(4), new TreeNode(4)), 
    new TreeNode(3)), new TreeNode(2)
  );
  
  std::cout << "CASE2\nExpected: false\nReceived: ";
  if (isBalanced(root)) {
    std::cout << "true\n\n";
  } else {
    std::cout << "false\n\n";
  }

  freeNodes(root);

  // case 3
  root = nullptr;
  
  std::cout << "CASE3\nExpected: true\nReceived: ";
  if (isBalanced(root)) {
    std::cout << "true" << std::endl;;
  } else {
    std::cout << "false" << std::endl;
  }

  return 0;
}
