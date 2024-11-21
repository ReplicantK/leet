#include <iostream>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void findNode(TreeNode* root, TreeNode* target, std::vector<TreeNode*>& v) {
  v.push_back(root);

  if (root != target && target->val < root->val) {
    findNode(root->left, target, v);
  } else if (root != target && target->val > root->val) {
    findNode(root->right, target, v);
  }
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  std::vector<TreeNode*> pVector;
  std::vector<TreeNode*> qVector;

  findNode(root, p, pVector);
  findNode(root, q, qVector);

  int maxIndex = 0;

  if (pVector.size() < qVector.size()) {
    maxIndex = pVector.size();
  } else {
    maxIndex = qVector.size();
  }

  for (int i = 0; i < maxIndex; i++) {
    if (pVector[i] != qVector[i]) {
      return pVector[i - 1];
    }
  }

  return pVector[maxIndex - 1];
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
    6, new TreeNode(2, new TreeNode(0), 
    new TreeNode(4, new TreeNode(3), new TreeNode(5))), 
    new TreeNode(8, new TreeNode(7), new TreeNode(9))
  );
  TreeNode* p = root->left;
  TreeNode* q = root->right;

  std::cout << "CASE1\nExpected: 6\nReceived: ";
  std::cout << lowestCommonAncestor(root, p, q)->val << "\n\n";

  freeNodes(root);

  // case 2
  root = new TreeNode(
    6, new TreeNode(2, new TreeNode(0), 
    new TreeNode(4, new TreeNode(3), new TreeNode(5))), 
    new TreeNode(8, new TreeNode(7), new TreeNode(9))
  );
  p = root->left;
  q = root->left->right;

  std::cout << "CASE2\nExpected: 2\nReceived: ";
  std::cout << lowestCommonAncestor(root, p, q)->val << "\n\n";

  freeNodes(root);

  // case 3
  root = new TreeNode(2, new TreeNode(1), nullptr);
  p = root;
  q = root->left;

  std::cout << "CASE3\nExpected: 2\nReceived: ";
  std::cout << lowestCommonAncestor(root, p, q)->val << std::endl;

  freeNodes(root);

  return 0;
}
