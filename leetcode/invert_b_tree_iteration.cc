#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int main() {
  // test case
  TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(5), new TreeNode(6)), new TreeNode(3));
  queue<TreeNode*> q;

  q.push(root);

  while (!q.empty()) {
    TreeNode* front = q.front();

    TreeNode* temp_left = front->left;
    front->left = front->right;
    front->right = temp_left;

    if (front->left != nullptr) {
      q.push(front->left);
    }

    if (front->right != nullptr) {
      q.push(front->right);
    }

    q.pop();
  }

  return 0;
}
