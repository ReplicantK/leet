#include <iostream>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode* head) {
  ListNode* pointer = head;
  std::vector<ListNode*> v;

  while (pointer != nullptr) {
    ListNode* save = pointer->next;
    pointer->next = nullptr;
    v.push_back(pointer);

    pointer = save;
  }

  int l = 1;
  int r = v.size() - 1;  

  while (l < r) {
    head->next = v[r];
    head->next->next = v[l];

    head = v[l];

    r--;
    l++;
  }

  if (v.size() % 2 == 0) {
    head->next = v[l];
  }
}

void printList(ListNode* list) {
  ListNode* forward = list;
  while (forward->next != nullptr) {
    std::cout << forward->val << "->"; 
    forward = forward->next;
  }
  std::cout << forward->val;
}

int main() {
  ListNode* list = new ListNode(
    1, new ListNode(2, new ListNode(3, new ListNode(4)))
  );

  std::cout << "CASE1\nExpected: 1->4->2->3\n";
  reorderList(list);
  std::cout << "Received: ";
  printList(list);

  delete(list);
  list = new ListNode(
    1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))
  );

  std::cout << "\n\nCASE2\nExpected: 1->5->2->4->3\n";
  reorderList(list);
  std::cout << "Received: ";
  printList(list);

  delete(list);
  list = new ListNode(1);

  std::cout << "\n\nCASE3\nExpected: 1\n";
  reorderList(list);
  std::cout << "Received: ";
  printList(list);
  std::cout << std::endl;

  delete(list);
  list = nullptr;

  return 0;
}
