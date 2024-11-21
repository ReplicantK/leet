#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
  if (!p && !q) {
    return true;
  } else if (p && !q || q && !p) {
    return false;
  }

  bool left = isSameTree(p->left, q->left); 
  bool right = isSameTree(p->right, q->right); 

  return p->val == q->val && left && right;
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
  // CASE 1
  TreeNode* root1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  TreeNode* root2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));

  std::cout << "CASE1\nExpected: true\nReceived: ";
  if (isSameTree(root1, root2)) {
    std::cout << "true\n\n";
  } else {
    std::cout << "false\n\n";
  }

  freeNodes(root1);
  freeNodes(root2);

  // CASE 2
  root1 = new TreeNode(1, new TreeNode(2), nullptr);
  root2 = new TreeNode(1, nullptr, new TreeNode(2));

  std::cout << "CASE2\nExpected: false\nReceived: ";
  if (isSameTree(root1, root2)) {
    std::cout << "true\n\n";
  } else {
    std::cout << "false\n\n";
  }

  freeNodes(root1);
  freeNodes(root2);

  // CASE 3
  root1 = new TreeNode(1, new TreeNode(2), new TreeNode(1));
  root2 = new TreeNode(1, new TreeNode(1), new TreeNode(2));

  std::cout << "CASE2\nExpected: false\nReceived: ";
  if (isSameTree(root1, root2)) {
    std::cout << "true" << std::endl;
  } else {
    std::cout << "false" << std::endl;
  }

  freeNodes(root1);
  freeNodes(root2);


  return 0;
}
