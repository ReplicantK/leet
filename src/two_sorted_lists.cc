#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main() {
  // next 3 lines: gen the first list
  ListNode* list1 = new ListNode(1, new ListNode(2));
  list1->next->next = new ListNode(4);
  list1->next->next->next = new ListNode(-9);

  // next 3 lines: gen the second list 
  ListNode* list2 = new ListNode(1, new ListNode(3));
  list2->next->next = new ListNode(4);
  list2->next->next->next = new ListNode(9);

  ListNode* head = list1;
  ListNode* head2 = list1;
  while (head->next != 0x0) {
    head = head->next;
  }

  head->next = list2;
  head = list1;

  while (list1 != 0x0) {
    cout << list1->val << " "; 
    list1 = list1->next;
  }
  cout << "\n";

  list1 = head;

  while (head->next != 0x0) {
    while (head2->next != 0x0) {
      if (head2->val > head2->next->val) {
        int swap = head2->val;
        head2->val = head2->next->val;
        head2->next->val = swap;
      }

      head2 = head2->next;
    }
      
    head2 = list1;
    head = head->next;
  }

  while (list1 != 0x0) {
    cout << list1->val << " "; 
    list1 = list1->next;
  }
  cout << endl;
  
  delete(list1);
  delete(list2);

  return 0;
}
