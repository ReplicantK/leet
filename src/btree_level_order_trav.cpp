#include <iostream>
#include <deque>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int main() {
  // test case 1
  //TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

  // test case 2
  //TreeNode* root = new TreeNode(1);

  // test case 3 -- need to test incase root is empty in final submission. note: does not run in this program.
  //TreeNode* root = nullptr;

  // test case 4
  //TreeNode* root = new TreeNode(1, new TreeNode(2),   new TreeNode(3));
  //root->left->left = new TreeNode(4);
  //root->right->right = new TreeNode(5);

  // test case 5
  //TreeNode* root = new TreeNode(1);
  //root->left = new TreeNode(2);

  // test case 6
  //TreeNode* root = new TreeNode(1, new TreeNode(2),   new TreeNode(3));
  //root->left->left = new TreeNode(4, new TreeNode(6), new TreeNode(7));
  //root->right->right = new TreeNode(5, new TreeNode(8), new TreeNode(9));

  // test case 7
  //TreeNode* root = new TreeNode(1);
  //root->left = new TreeNode(2);
  //root->left->left = new TreeNode(3);
  //root->left->left->left = new TreeNode(4);
  //root->left->left->left->left = new TreeNode(5);

  // test case 8
  TreeNode* root = new TreeNode(0, new TreeNode(2), new TreeNode(4));
  root->left->left = new TreeNode(1, new TreeNode(5), new TreeNode(1));

  root->right->right = new TreeNode(-1);
  root->right->right->right = new TreeNode(8);

  root->right->left = new TreeNode(3);
  root->right->left->right = new TreeNode(6);

  vector<vector<int>> sol;

  deque<TreeNode*> q;
  q.push_front(root);

  while (!q.empty()) {
    vector<int> values;
    vector<int> temp;

    int current_size = q.size();

    for (int i = 0; i < current_size; i++) {
      values.push_back(q.front()->val);

      if (q.front()->left != nullptr) {
        q.push_back(q.front()->left);
      }
      if (q.front()->right != nullptr) {
        q.push_back(q.front()->right);
      }

      q.pop_front();
    }

    // for testing
    //for (auto i : values) {
    //  cout << i << " ";
    //}
    //cout << endl;

    for (int i = 0; i < values.size(); i++) {
      if (temp.size() < current_size) {
        temp.push_back(values[i]);
      } else {
        sol.push_back(temp);
        temp.clear();
        temp.push_back(values[i]);
      }

      if (i == (values.size() - 1)) {
        sol.push_back(temp);
      }
    }
  }

  cout << "[";
  for (int i = 0; i < sol.size() - 1; i++) {
    cout << "[";
    for (int j = 0; j < sol[i].size() - 1; j++) {
      cout << sol[i][j] << ",";
    }

    cout << sol[i][sol[i].size() - 1] << "],";
  }

  cout << "[";
  int i;
  for (i = 0; i < sol[sol.size() -1].size() - 1; i++) {
    cout << sol[sol.size() -1][i] << ",";
  }

  cout << sol[sol.size() -1][i++] << "]]" << endl;

  return 0;
}
