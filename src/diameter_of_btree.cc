#include <iostream>
#include <utility>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

pair<int, int> edges(TreeNode* node) {
  if (node == nullptr) {
    return {-69, -1};
  }
  
  auto left = edges(node->left);
  auto right = edges(node->right);

  left.second += 1;
  right.second += 1;

  int it_total = left.second + right.second;
  int current_max = left.first;

  if (right.first > current_max) {
    current_max = right.first;
  }
  if (it_total > current_max) {
    current_max = it_total;
  }

  int it_win = 0;
  if (left.second >= right.second) {
    it_win = left.second;
  } else {
    it_win = right.second;
  }

  return {current_max, it_win};
}

int main() {
  // test case 1
  //TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));

  // test case 2
  //TreeNode* root = new TreeNode(1);
  //root->left = new TreeNode(2);

  // test case 3
  //TreeNode* root = new TreeNode(4);
  //root->left = new TreeNode(2, new TreeNode(1), new TreeNode(3));

  // test case 4
  TreeNode* root = new TreeNode(1, new TreeNode(5), new TreeNode(7));
  root->left->left = new TreeNode(9);
  root->left->left->left = new TreeNode(3);
  root->left->left->left->right = new TreeNode(4);
  root->left->right = new TreeNode(2);
  root->left->right->left = new TreeNode(15);
  root->left->right->right = new TreeNode(69);
  root->left->right->right->right = new TreeNode(2040);

  auto left = edges(root->left);
  auto right = edges(root->right);

  int sub_max = 0;
  if (left.first >= right.first) {
    sub_max = left.first;
  } else {
    sub_max = right.first;
  }

  int root_max = (left.second + 1) + (right.second + 1);

  if (sub_max >= root_max) {
    cout << sub_max << endl;
  } else {
    cout << root_max << endl;
  }

  return 0;
}
