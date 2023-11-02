#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int preorder_start, int inorder_start, int inorder_end) {
  if (preorder_start > preorder.size() - 1 || inorder_start > inorder_end) {
    return nullptr;
  }

  TreeNode* parent = new TreeNode(preorder[preorder_start]);

  int inorder_index = 0;
  for (int i = inorder_start; i <= inorder_end; i++) {
    if (inorder[i] == parent->val) {
      inorder_index = i;
      break;
    }
  }

  parent->left = buildTree(preorder, inorder, preorder_start + 1, inorder_start, inorder_index - 1);
  parent->right = buildTree(preorder, inorder, preorder_start + inorder_index - inorder_start + 1, inorder_index + 1, inorder_end);

  return parent;
}

int main() {
  vector<int> preorder = {3,9,20,15,7};
  vector<int> inorder = {9,3,15,20,7}; 

  auto test = buildTree(preorder, inorder, 0, 0, inorder.size() - 1);

  cout << test->val << endl;
  cout << test->left->val << endl;
  cout << test->right->val << endl;
  cout << test->right->left->val << endl;
  cout << test->right->right->val << endl;

  return 0;
}
