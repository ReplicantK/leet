#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main() {
  // test case
  ListNode* head = new ListNode(1);
  ListNode* head1 = new ListNode(2);
  ListNode* head2 = new ListNode(3);
  ListNode* head3 = new ListNode(4);
  ListNode* head4 = new ListNode(5);
  ListNode* head5 = new ListNode(6);

  head->next = head1;
  head1->next = head2;
  head2->next = head3;
  head3->next = head4;
  head4->next = head5;

  // solution
  vector<ListNode*> vector;

  while (head != NULL) {
    vector.push_back(head);
    head = head->next;
  }

  cout << vector.at(ceil(vector.size() / 2))->val << endl;

  return 0;
}
