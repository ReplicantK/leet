#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

int main() {
  // test case
  ListNode* index0 = new ListNode(3);
  ListNode* index1 = new ListNode(2);
  ListNode* index2 = new ListNode(0);
  ListNode* index3 = new ListNode(-4);

  index0->next = index1;
  index1->next = index2;
  index2->next = index3;
  index3->next = index1;

  set<int> set;
  ListNode* current = index0;
  bool found = false;

  if (index1 == NULL) {
    cout << found << endl;
    return 0;
  }

  while (current->next != NULL) {
    if (set.contains(current->val)) {
      found = true;
      break;
    }

    set.insert(current->val);
    current = current->next;
  }

  cout << found << endl;
  return 0;
}
