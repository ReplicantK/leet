#include <iostream>
#include <stack>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool boolSameTree(TreeNode* root, TreeNode* subRoot) {
  if (!root && !subRoot) {
    return true;
  } else if (root && !subRoot || !root && subRoot) {
    return false;
  }

  bool left = boolSameTree(root->left, subRoot->left);
  bool right = boolSameTree(root->right, subRoot->right);

  return root->val == subRoot->val && left && right;
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
  std::stack<TreeNode*> st;
  st.push(root);

  while (!st.empty()) {
    TreeNode* current = st.top();
    st.pop();

    if (current->val == subRoot->val) {
      bool left = boolSameTree(current->left, subRoot->left);
      bool right = boolSameTree(current->right, subRoot->right);

      if (left && right) {
        return true;
      }
    }

    if (current->left) {
      st.push(current->left);
    }

    if (current->right) {
      st.push(current->right);
    }
  }

  return false;
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
    3, new TreeNode(4, new TreeNode(1), new TreeNode(2)), new TreeNode(5)
  );
  TreeNode* subRoot = new TreeNode(4, new TreeNode(1), new TreeNode(2));

  std::cout << "CASE1\nExpected: true\nReceived: ";
  if (isSubtree(root, subRoot)) {
    std::cout << "true\n\n";
  } else {
    std::cout << "false\n\n";
  }

  freeNodes(root);
  freeNodes(subRoot);

  // case 2
  root = new TreeNode(
    3, new TreeNode(4, new TreeNode(1),
    new TreeNode(2, new TreeNode(0), nullptr)
    ), new TreeNode(5)
  );
  subRoot = new TreeNode(4, new TreeNode(1), new TreeNode(2));

  std::cout << "CASE2\nExpected: false\nReceived: ";
  if (isSubtree(root, subRoot)) {
    std::cout << "true\n\n";
  } else {
    std::cout << "false\n\n";
  }

  freeNodes(root);
  freeNodes(subRoot);

  // case 3
  root = new TreeNode(1);
  subRoot = new TreeNode(1);

  std::cout << "CASE3\nExpected: true\nReceived: ";
  if (isSubtree(root, subRoot)) {
    std::cout << "true\n\n";
  } else {
    std::cout << "false\n\n";
  }

  freeNodes(root);
  freeNodes(subRoot);

  // case 4
  root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  subRoot = new TreeNode(1, new TreeNode(2), nullptr);

  std::cout << "CASE4\nExpected: false\nReceived: ";
  if (isSubtree(root, subRoot)) {
    std::cout << "true" << std::endl;
  } else {
    std::cout << "false" << std::endl;
  }

  freeNodes(root);
  freeNodes(subRoot);

  return 0;
}
