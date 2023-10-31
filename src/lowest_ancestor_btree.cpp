#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> find(TreeNode* node_t_find, TreeNode* node_explored) {
  // once null is reached or if node is found
  if (node_explored == node_t_find) {
    vector<TreeNode*> found = {node_explored};
    return found;
  } else if (node_explored == NULL) {
    vector<TreeNode*> found;
    return found;
  }

  // returning back up from the deep dive
  auto left = find(node_t_find, node_explored->left);
  auto right = find(node_t_find, node_explored->right);

  if (!left.empty()) {
    left.push_back(node_explored);
    return left;
  } else if (!right.empty()) {
    right.push_back(node_explored);
  }
  
  return right;
}

int main() {
  // test tree for case 1.1 and 1.2
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);
  root->right = new TreeNode(1);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);

  // test case 1.1
  //TreeNode* q = root->right;
  //TreeNode* p = root->left;

  // test case 1.2
  TreeNode* q = root->left->right->right;
  TreeNode* p = root->left;

  // test tree for case 2
  //TreeNode* root = new TreeNode(1);
  //root->left = new TreeNode(2);

  //TreeNode* q = root->left;
  //TreeNode* p = root;

  auto path_t_q = find(q, root);
  auto path_t_p = find(p, root);

  cout << "find path to: " << q->val << "\npath in reverse order: ";
  for (auto i : path_t_q) {
    cout << i->val << " ";
  }
  cout << "\n\n";

  cout << "find path to: " << p->val << "\npath in reverse order: ";
  for (auto i : path_t_p) {
    cout << i->val << " ";
  }
  cout << "\n";

  TreeNode* answer = NULL;
  if (path_t_q.size() >= path_t_p.size()) {
    int i = 0;
    while (answer == NULL) {
      for (auto j : path_t_p) {
        if (j == path_t_q[i]) {
          answer = j;
          break;
        }
      }

      i++;
    }
  } else {
    int i = 0;
    while (answer == NULL) {
      for (auto j : path_t_q) {
        if (j == path_t_p[i]) {
          answer = j;
          break;
        }
      }

      i++;
    }
  }

  cout << "\nlowest common ancestor: " << answer->val << endl;

  return 0;
}
