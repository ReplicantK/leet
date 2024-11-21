#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<int> rightSideView(TreeNode* root) {
  std::vector<int> ans;
  std::queue<TreeNode*> q;

  if (root) {
    q.push(root);
  }

  while (!q.empty()) {
    int maxLoop = q.size();
    ans.push_back(q.front()->val);

    for (int i = 0; i < maxLoop; i++) {
      if (q.front()->right) {
        q.push(q.front()->right);
      }

      if (q.front()->left) {
        q.push(q.front()->left);
      }

      q.pop();
    }
  }

  return ans;
}

void printVector(const std::vector<int>& v) {
  if (v.empty()) {
    std::cout << "[]";
    return;
  }

  std::cout << "[";

  for (int i = 0; i < v.size() - 1; i++) {
    std::cout << v[i] << ",";
  }

  std::cout << v[v.size() - 1] << "]";
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
    1, new TreeNode(2, nullptr, new TreeNode(5)),
    new TreeNode(3, nullptr, new TreeNode(4))
  );

  std::cout << "CASE1\nExpected: [1,3,4]\nReceived: ";
  printVector(rightSideView(root));
  freeNodes(root);

  // case 2
  root = new TreeNode(1, nullptr, new TreeNode(3));

  std::cout << "\n\nCASE2\nExpected: [1,3]\nReceived: ";
  printVector(rightSideView(root));
  freeNodes(root);

  // case 3
  root = nullptr;

  std::cout << "\n\nCASE3\nExpected: []\nReceived: ";
  printVector(rightSideView(root));
  std::cout << std::endl;

  return 0;
}
