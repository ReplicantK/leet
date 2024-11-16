#include <iostream>
#include <queue>
#include <stack>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* invertTree(TreeNode* root) {
  std::stack<TreeNode*> st;

  if (root) {
    st.push(root);
  }

  while (!st.empty()) {
    TreeNode* current = st.top();
    st.pop();

    TreeNode* swap = current->left;
    current->left = current->right;
    current->right = swap;

    if (current->left) {
      st.push(current->left);
    }

    if (current->right) {
      st.push(current->right);
    }
  }

  return root;
}

void treePrinterAndDelete(TreeNode* root) {
  if (!root) {
    return;
  }

  std::queue<TreeNode*> q;
  std::vector<int> v;

  q.push(root);

  while (!q.empty()) {
    TreeNode* current = q.front();
    q.pop();

    v.push_back(current->val);

    if (current->left) {
      q.push(current->left);
    }

    if (current->right) {
      q.push(current->right);
    }

    delete(current);
  }

  for (int i = 0; i < v.size() - 1; i++) {
    std::cout << v[i] << ",";
  }

  std::cout << v[v.size() - 1];
}

int main() {
  // case 1
  TreeNode* root = new TreeNode(
    4, new TreeNode(2, new TreeNode(1), new TreeNode(3)),
    new TreeNode(7, new TreeNode(6), new TreeNode(9))
  );

  std::cout << "CASE1\nExpected: [4,7,2,9,6,3,1]\nReceived: [";
  treePrinterAndDelete(invertTree(root));

  // case 2
  root = new TreeNode(2, new TreeNode(1), new TreeNode(3));

  std::cout << "]\n\nCASE2\nExpected: [2,3,1]\nReceived: [";
  treePrinterAndDelete(invertTree(root));

  // case 3
  root = nullptr;

  std::cout << "]\n\nCASE3\nExpected: []\nReceived: [";
  treePrinterAndDelete(invertTree(root));
  std::cout << "]" << std::endl;
  
  return 0;
}
