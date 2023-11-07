#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  TreeNode* save_root = root;

  vector<TreeNode*> p_path;

  while (root->val != p->val) {
    p_path.push_back(root);

    if (p->val < root->val) {
      root = root->left;
    } else {
      root = root->right;
    }
  }

  p_path.push_back(root);

  vector<TreeNode*> q_path;
  root = save_root;

  while (root->val != q->val) {
    q_path.push_back(root);

    if (q->val < root->val) {
      root = root->left;
    } else {
      root = root->right;
    }
  }
  q_path.push_back(root);

  if (p_path.size() <= q_path.size()) {
    for (int i = p_path.size() - 1; i >= 0; i--) {
      if (p_path[i] == q_path[i]) {
        root = p_path[i];
        break;
      }
    }
  } else {
    for (int i = q_path.size() - 1; i >= 0; i--) {
      if (q_path[i] == p_path[i]) {
        root = q_path[i];
        break;
      }
    }
  }

  return root;
}

int main() {
  TreeNode* root = new TreeNode(6);
  root->left = new TreeNode(2);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(4);
  root->left->right->left = new TreeNode(3);
  root->left->right->right = new TreeNode(5);
  root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(9);

  TreeNode* p = root->left;
  TreeNode* q = root->left->right;

  cout << lowestCommonAncestor(root, p, q)->val << endl;

  return 0;
}
