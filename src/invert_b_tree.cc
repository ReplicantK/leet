#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void invert(TreeNode* node) {
  if (node == nullptr) {
    return; 
  }
  
  invert(node->left);
  invert(node->right);

  TreeNode* temp_left = node->left;
  node->left = node->right;
  node->right = temp_left;
}

int main() {
  // test case
  TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  root->left->left = new TreeNode(5);
  root->left->right = new TreeNode(6);

  invert(root);
  
  return 0;
}
