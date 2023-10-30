#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int find_depth(TreeNode* node, int counter) {
  if (node == nullptr) {
    return counter;
  }

  int left = find_depth(node->left, counter + 1);
  int right = find_depth(node->right, counter + 1);

  int max = left;

  if (right > max) {
    max = right;
  }

  return max;
}

int main() {
  // test case 1
  TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

  // test case 2
  //TreeNode* root = new TreeNode(1);
  //root->right = new TreeNode(2);

  cout << find_depth(root, 0) << endl;

  return 0;
}
