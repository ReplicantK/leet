#include <iostream>
#include <deque>
#include <cassert>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// solution starts here
bool isSameTree(TreeNode* p, TreeNode* q) {
  deque<TreeNode*> qp;
  deque<TreeNode*> qq;

  qp.push_back(p);
  qq.push_back(q);

  // bfs
  while (!qp.empty()) {
    TreeNode* a = qp.front();
    TreeNode* b = qq.front();

    qp.pop_front();
    qq.pop_front();

    if (a == nullptr && b == nullptr) {
      continue;
    } else if (a == nullptr || b == nullptr) {
      return false;
    } else if (a->val != b->val) {
      return false;
    }

    if ((a->left != nullptr || a->right != nullptr) || (b->left != nullptr || b->right != nullptr)) {
      qp.push_back(a->left);
      qp.push_back(a->right);

      qq.push_back(b->left);
      qq.push_back(b->right);
    }
  }

  return true;
}

// driver code for running tests against solution
int main() {
  TreeNode* p = nullptr;
  TreeNode* q = nullptr;
  assert(isSameTree(p, q) == true);

  p = new TreeNode(1);
  q = nullptr;
  assert(isSameTree(p, q) == false);

  p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  q = nullptr;
  assert(isSameTree(p, q) == false);

  p = new TreeNode(1);
  q = new TreeNode(1);
  assert(isSameTree(p, q) == true);

  p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  q = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  assert(isSameTree(p, q) == true);

  p = new TreeNode(1, new TreeNode(2), nullptr);
  q = new TreeNode(1, nullptr, new TreeNode(2));
  assert(isSameTree(p, q) == false);

  p = new TreeNode(1, new TreeNode(2), new TreeNode(1));
  q = new TreeNode(1, new TreeNode(1), new TreeNode(2));
  assert(isSameTree(p, q) == false);

  p = new TreeNode(1, nullptr, new TreeNode(1));
  q = new TreeNode(1, nullptr, new TreeNode(1));
  assert(isSameTree(p, q) == true);

  p = new TreeNode(1, new TreeNode(1, new TreeNode(1), nullptr), nullptr);
  q = new TreeNode(1, new TreeNode(1, new TreeNode(1), nullptr), nullptr);
  assert(isSameTree(p, q) == true);

  cout << "All tests passed." << endl;

  return 0;
}
