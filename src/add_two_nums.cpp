#include <iostream>
#include <string>
#include <iostream>
#include <cassert>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  string s1;
  string s2;

  // first string
  while (l1 != nullptr) {
    s1 += to_string(l1->val);
    l1 = l1->next;
  }

  // second string
  while (l2 != nullptr) {
    s2 += to_string(l2->val);
    l2 = l2->next;
  }

  int carry = -1;
  std::string::iterator s1_it = s1.begin();
  std::string::iterator s2_it = s2.begin();

  string add = "";

  while (carry != -1 || s1_it != s1.end() || s2_it != s2.end()) {
    int current = 0;

    if (s1_it != s1.end()) {
      current += (*s1_it) - '0';
      s1_it++;
    }

    if (s2_it != s2.end()) {
      current += (*s2_it) - '0';
      s2_it++;
    }

    if (carry != -1) {
      current += carry;
      carry = -1;
    }

    if (current <= 9) {
      add += to_string(current);
    } else {
      string temp = to_string(current);
      add += temp[temp.size() - 1];
      temp.pop_back();
      carry = stoi(temp);
    }

  }

  ListNode* ans = new ListNode(add[0] - '0');
  ListNode* head = ans;

  for (int i = 1; i < add.size(); i++) {
    head->next = new ListNode(add[i] - '0');
    head = head->next;
  }

  return ans;
}

void check_solution(string case_ans, ListNode* user_ans) {
  string user_ans_str = "";

  cout << "Expecting answer: " << case_ans;
  while (user_ans != nullptr) {
    user_ans_str += to_string(user_ans->val);
    user_ans = user_ans->next;
  }

  cout << " Got: " << user_ans_str << "\n";
  assert(case_ans == user_ans_str);
  cout << "Passed!" << "\n";
}

int main() {
  // case 1
  ListNode* case1_l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
  ListNode* case1_l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
  string case1_ans = "708";

  // case 2
  ListNode* case2_l1 = new ListNode(0);
  ListNode* case2_l2 = new ListNode(0);
  string case2_ans = "0";

  // case 3
  ListNode* case3_l1 = new ListNode(9);
  ListNode* case3_l2 = new ListNode(1);
  ListNode* head = case3_l2;

  for (int i = 0; i < 9; i++) {
    head->next = new ListNode(9);
    head = head->next;
  }

  string case3_ans = "00000000001";

  // case 4
  ListNode* case4_l1 = new ListNode(1);
  head = case4_l1;

  for (int i = 0; i < 29; i++) {
    head->next = new ListNode(0);
    head = head->next;
  }

  head->next = new ListNode(1);
  ListNode* case4_l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
  string case4_ans = "6640000000000000000000000000001";

  // case 5
  ListNode* case5_l1 = new ListNode(9);
  head = case5_l1;

  for (int i = 0; i < 6; i++) {
    head->next = new ListNode(9);
    head = head->next;
  }

  ListNode* case5_l2 = new ListNode(9);
  head = case5_l2;

  for (int i = 0; i < 3; i++) {
    head->next = new ListNode(9);
    head = head->next;
  }

  string case5_ans = "89990001";

  // running tests
  check_solution(case1_ans, addTwoNumbers(case1_l1, case1_l2));
  check_solution(case2_ans, addTwoNumbers(case2_l1, case2_l2));
  check_solution(case4_ans, addTwoNumbers(case4_l1, case4_l2));
  check_solution(case5_ans, addTwoNumbers(case5_l1, case5_l2));

  cout << "Congratulations! all tests passed." << endl;

  return 0;
}
