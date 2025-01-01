#include <stack>
#include <vector>
#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool IsSymmetric(TreeNode* root) {
  std::vector<TreeNode*> v1;
  std::vector<TreeNode*> v2;

  std::stack<TreeNode*> st;
  st.push(root->left);

  while (!st.empty()) {
    TreeNode* c = st.top();
    st.pop();
    v1.emplace_back(c);

    if (c) {
      st.push(c->right);
      st.push(c->left);
    }
  }

  st.push(root->right);

  while (!st.empty()) {
    TreeNode* c = st.top();
    st.pop();
    v2.emplace_back(c);

    if (c) {
      st.push(c->left);
      st.push(c->right);
    }
  }

  for (int i = 0; i < v1.size(); i++) {
    if (v1[i] && !v2[i] || !v1[i] && v2[i] || v1[i] && v2[i] && v1[i]->val != v2[i]->val) {
      return false;
    }
  }

  return true;
}

void ClearTree(TreeNode* root) {
  if (root->left) {
    ClearTree(root->left);
  }

  if (root->right) {
    ClearTree(root->right);
  }

  delete(root);
}

int main() {
  TreeNode* root = new TreeNode(
    1, new TreeNode(2, new TreeNode(3), new TreeNode(4)),
    new TreeNode(2, new TreeNode(4), new TreeNode(3))
  );

  std::cout << "CASE1\nExpected: 1\nReceived: " << IsSymmetric(root) << "\n\n";
  ClearTree(root);

  root = new TreeNode(
    1, new TreeNode(2, nullptr, new TreeNode(3)),
    new TreeNode(2, nullptr, new TreeNode(3))
  );

  std::cout << "CASE2\nExpected: 0\nReceived: " << IsSymmetric(root) << "\n";
  ClearTree(root);

  return 0;
}
