#include <iostream>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

string serialize(TreeNode* root) {
  string s = "";

  queue<TreeNode*> q;
  q.push(root);

  int last_num_index = 0;

  while (!q.empty()) {
    TreeNode* temp = q.front();
    q.pop();
    
    if (temp == nullptr) {
      s += "null ";
      continue;
    }

    s += to_string(temp->val);
    last_num_index = s.size();
    s += " ";

    q.push(temp->left);
    q.push(temp->right);
  }
  s.erase(last_num_index, s.size() - last_num_index);
  s += " /";

  return s;
}

TreeNode* deserialize(string data) {
  stringstream hi(data);
  vector<string> vec;

  string buf = "";
  hi >> buf;
  if (buf == "/") {
    return nullptr;
  }
  while (buf != "/") {
    vec.push_back(buf);
    hi >> buf;
  }

  // important part from here below
  int i = 0;
  TreeNode* root = new TreeNode(stoi(vec[i]));

  queue<TreeNode*> q;
  q.push(root);

  i++;
  while (!q.empty()) {
    if (i != vec.size()) {
      if (vec[i] != "null") {
        q.front()->left = new TreeNode(stoi(vec[i]));
      }
      i++;
    }

    if (i != vec.size()) {
      if (vec[i] != "null") {
        q.front()->right = new TreeNode(stoi(vec[i]));
      }
      i++;
    }


    if (q.front()->left != nullptr) {
      q.push(q.front()->left);
    }
    if (q.front()->right != nullptr) {
      q.push(q.front()->right);
    }

    q.pop();
  }

  return root;
}

void printer(TreeNode* root) {
  if (root == nullptr) {
    return;
  }

  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    cout << q.front()->val << " ";

    if (q.front()->left != nullptr) {
      q.push(q.front()->left);
    }
    if (q.front()->right != nullptr) {
      q.push(q.front()->right);
    }

    q.pop();
  }

  cout << endl;
}

int main() {
  // when printing out the string from serialize the last chracter is a "/"
  // this means that this is where the binary tree ends
  // when the array is reconstructed with deserialize and then printed only the values of the binary tree
  // are printed. this means that there is no "null" or "/" output

  // test case 1
  TreeNode* case1 = new TreeNode(1);
  case1->left = new TreeNode(2); 
  case1->right = new TreeNode(3);
  case1->right->left = new TreeNode(4);
  case1->right->right = new TreeNode(5);

  // test case 2
  TreeNode* case2 = new TreeNode(1);

  // test case 3
  TreeNode* case3 = new TreeNode(1);
  case3->left = new TreeNode(2);
  case3->right = new TreeNode(2);

  // test case 4
  TreeNode* case4 = nullptr;

  // test case 5
  TreeNode* case5 = new TreeNode(1);
  case5->left = new TreeNode(2); 
  case5->right = new TreeNode(3);
  case5->right->left = new TreeNode(4);
  case5->right->right = new TreeNode(5);
  case5->right->left->left = new TreeNode(6);
  case5->right->left->right = new TreeNode(7);

  // running case 1
  string data_case1 = serialize(case1);
  cout << data_case1 << endl;
  printer(deserialize(data_case1));

  // running case 2
  cout << endl;
  string data_case2 = serialize(case2);
  cout << data_case2 << endl;
  printer(deserialize(data_case2));

  // running case 3
  cout << endl;
  string data_case3 = serialize(case3);
  cout << data_case3 << endl;
  printer(deserialize(data_case3));

  // running case 4
  cout << endl;
  string data_case4 = serialize(case4);
  cout << data_case4 << endl;
  printer(deserialize(data_case4));

  // running case 5
  cout << endl;
  string data_case5 = serialize(case5);
  cout << data_case5 << endl;
  printer(deserialize(data_case5));

  return 0;
}
