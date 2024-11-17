#include <iostream>
#include <stack>
#include <utility>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode* root) {
  int max = 0;
  std::stack<std::pair<TreeNode*, int>> st;

  if (root) {
    st.push({root, 0});
  }

  while (!st.empty()) {
    std::pair<TreeNode*, int> current = st.top();
    st.pop();

    int add1 = current.second + 1;

    if (!current.first->left && !current.first->right && add1 > max) {
      max = add1;
      continue;
    }

    if (current.first->right) {
      st.push({current.first->right, add1});
    }

    if (current.first->left) {
      st.push({current.first->left, add1});
    }
  }

  return max;
}

void deleteNodes(TreeNode* root) {
  std::stack<TreeNode*> st;

  if (root) {
    st.push(root);
  }

  while (!st.empty()) {
    TreeNode* current = st.top();
    st.pop();

    if (current->left) {
      st.push(current->left);
    }

    if (current->right) {
      st.push(current->right);
    }

    delete(current);
  }
}

int main() {
  // case 1
  TreeNode* root = new TreeNode(
    3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7))
  );

  std::cout << "CASE1\nExpected: 3\nReceived: " << maxDepth(root) << "\n\n";
  deleteNodes(root);

  // case 2
  root = new TreeNode(1, nullptr, new TreeNode(2));

  std::cout << "CASE2\nExpected: 2\nReceived: " << maxDepth(root) << std::endl;
  deleteNodes(root);

  return 0;
}
