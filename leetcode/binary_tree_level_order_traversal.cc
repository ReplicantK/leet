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

std::vector<std::vector<int>> levelOrder(TreeNode* root) {
  std::vector<std::vector<int>> ans;
  std::queue<TreeNode*> q;

  if (root) {
    q.push(root);
  }

  while (!q.empty()) {
    int maxLoops = q.size();
    std::vector<int> newV(maxLoops);

    for (int i = 0; i < maxLoops; i++) {
      TreeNode* front = q.front();

      newV[i] = front->val;

      if (front->left) {
        q.push(front->left);
      }

      if (front->right) {
        q.push(front->right);
      }

      q.pop();
    }

    ans.push_back(newV);
  }

  return ans;
}

void printVector(const std::vector<std::vector<int>>& v) {
  if (v.empty()) {
    std::cout << "[]";
    return;
  }

  std::cout << "[";
  for (int i = 0; i < v.size() - 1; i++) {
    std::cout << "[";

    for (int j = 0; j < v[i].size() - 1; j++) {
      std::cout << v[i][j] << ",";
    }

    std::cout << v[i][v[i].size() - 1] << "],";
  }

  std::cout << "[";
  for (int i = 0; i < v[v.size() -1].size() - 1; i++) {
    std::cout << v[v.size() -1][i] << ",";
  }
  std::cout << v[v.size() - 1][v[v.size() - 1].size() - 1] << "]]";
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
    3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7))
  );

  std::cout << "CASE1\nExpected: [[3],[9,20],[15,7]]\nReceived: ";
  printVector(levelOrder(root));
  freeNodes(root);

  // case 2
  root = new TreeNode(1);

  std::cout << "\n\nCASE2\nExpected: [[1]]\nReceived: ";
  printVector(levelOrder(root));
  freeNodes(root);

  // case 3
  root = nullptr;

  std::cout << "\n\nCASE3\nExpected: []\nReceived: ";
  printVector(levelOrder(root));
  std::cout << std::endl;

  return 0;
}
