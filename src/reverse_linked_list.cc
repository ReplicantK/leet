#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

int main() {
  // this is the first test case declaration
  ListNode* head = new ListNode(1);
  ListNode* head1 = new ListNode(2);
  ListNode* head2 = new ListNode(3);
  ListNode* head3 = new ListNode(4);
  ListNode* head4 = new ListNode(5);

  head->next = head1;
  head1->next = head2;
  head2->next = head3;
  head3->next = head4;

  // solution
  vector<ListNode*> vector;

  while (head != NULL) {
    vector.push_back(head);
    head = head->next;
  }

  ListNode* inverted = vector.at(vector.size() - 1);
  while (!vector.empty()) {
    if (vector.size() == 1) {
      vector.at(vector.size() - 1)->next = NULL;
    } else {
      vector.at(vector.size() - 1)->next = vector.at(vector.size() - 2);
    }

    vector.pop_back();
  }

  while (inverted != NULL) {
    cout << inverted->val << endl;
    inverted = inverted->next;
  }

  return 0;
}
