#include <vector>
#include <iostream>
#include <stack>
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

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
  vector<TreeNode*> rootVec;
  vector<TreeNode*> subRootVec;
  stack<TreeNode*> s;

  s.push(root);
  while (!s.empty()) {
    TreeNode* current = s.top();
    s.pop();

    rootVec.push_back(current);

    if (current != nullptr) {
      s.push(current->right);
      s.push(current->left);
    }
  }

  s.push(subRoot);
  while (!s.empty()) {
    TreeNode* current = s.top();
    s.pop();

    subRootVec.push_back(current);

    if (current != nullptr) {
      s.push(current->right);
      s.push(current->left);
    }
  }

  auto rootIt = rootVec.begin();
  auto subRootIt = subRootVec.begin();

  auto saveRootIt = rootIt;

  while (rootIt != rootVec.end()) {
    if (*rootIt == nullptr && *subRootIt == nullptr) {
      rootIt++;
      subRootIt++;
    } else if ((*rootIt != nullptr && *subRootIt == nullptr) || (*rootIt == nullptr && *subRootIt != nullptr)) {
      saveRootIt++;
      rootIt = saveRootIt;
      subRootIt = subRootVec.begin();
    } else if ((*rootIt)->val != (*subRootIt)->val) {
      saveRootIt++;
      rootIt = saveRootIt;
      subRootIt = subRootVec.begin();
    } else {
      rootIt++;
      subRootIt++;
    }

    if (subRootIt == subRootVec.end()) {
      return true;
    }
  }

  return false;
}

int main() {
  TreeNode* root = new TreeNode(3, new TreeNode(4, new TreeNode(1), new TreeNode(2)), new TreeNode(5));
  TreeNode* subRoot = new TreeNode(4, new TreeNode(1), new TreeNode(2));
  assert(isSubtree(root, subRoot) == true);

  root = new TreeNode(3, new TreeNode(4, new TreeNode(1), new TreeNode(2, new TreeNode(0), nullptr)), new TreeNode(5));
  subRoot = new TreeNode(4, new TreeNode(1), new TreeNode(2));
  assert(isSubtree(root, subRoot) == false);

  root = new TreeNode(1, new TreeNode(1), nullptr);
  subRoot = new TreeNode(1);
  assert(isSubtree(root, subRoot) == true);

  root = new TreeNode(1, nullptr, new TreeNode(1, nullptr, new TreeNode(1, nullptr, new TreeNode(1, new TreeNode(2), nullptr))));
  subRoot = new TreeNode(1, nullptr, new TreeNode(1, nullptr, new TreeNode(1, new TreeNode(2), nullptr)));
  assert(isSubtree(root, subRoot) == true);

  cout << "All tests passed" << endl;

  return 0;
}
