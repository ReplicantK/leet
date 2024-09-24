#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

deque<TreeNode*> recurse(TreeNode* node) {
  // reached the end of the dive
  if (node == nullptr) {
    deque<TreeNode*> q;
    return q;
  }

  auto left = recurse(node->left);
  auto right = recurse(node->right);
  deque<TreeNode*> re;
  re.push_back(node);

  // starting from the bottom
  if (left.empty() && right.empty()) {
    return re;
  }

  // main return
  int i = 0;

  for (; i < right.size(); i++) {
    re.push_back(right[i]);
  }

  for (; i < left.size(); i++) {
    re.push_back(left[i]);
  }

  return re;
}

vector<int> rightSideView(TreeNode* root) {
  vector<int> sol;

  auto re = recurse(root); 

  for (auto i : re) {
    sol.push_back(i->val);
  }

  return sol;
}

void print(vector<int> vec) {
  for (int i : vec) {
    cout << i << " ";
  }

  cout << "\n";
}

int main() {
  // test case 1
  TreeNode* case1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  case1->left->right = new TreeNode(5);
  case1->right->right = new TreeNode(4);

  // test case 2
  TreeNode* case2 = new TreeNode(1);
  case2->right = new TreeNode(3);

  // test case 3
  TreeNode* case3 = nullptr;

  // test case 4
  TreeNode* case4 = new TreeNode(1);
  case4->left = new TreeNode(2);
  
  // test case 5
  TreeNode* case5 = new TreeNode(1);

  // test case 6
  TreeNode* case6 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  case6->left->left = new TreeNode(4);

  // test case 7
  TreeNode* case7 = new TreeNode(6);
  case7->left = new TreeNode(1);
  case7->left->right = new TreeNode(3, new TreeNode(2), new TreeNode(5));
  case7->left->right->right->left = new TreeNode(4);

  print(rightSideView(case1));
  print(rightSideView(case2));
  print(rightSideView(case3));
  print(rightSideView(case4));
  print(rightSideView(case5));
  print(rightSideView(case6));
  print(rightSideView(case7));
  
  return 0;
}
