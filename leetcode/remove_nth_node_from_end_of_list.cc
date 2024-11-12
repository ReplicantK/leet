#include <iostream>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
  std::vector<ListNode*> v;

  ListNode* saveHead = head;
  ListNode* forward = head;

  while (forward != nullptr) {
    v.push_back(forward);
    forward = forward->next;
  }

  int targetIndex = v.size() - n;

  if (targetIndex == 0) {
    return head->next;
  }

  int targetIndexOneBack = targetIndex - 1;

  v[targetIndexOneBack]->next = v[targetIndex]->next;

  return saveHead;
}

void printList(ListNode* list) {
  if (!list) {
    std::cout << "nullptr";
    return;
  }

  ListNode* forward = list;
  while (forward->next != nullptr) {
    std::cout << forward->val << "->"; 
    forward = forward->next;
  }
  std::cout << forward->val;
}

int main() {
  ListNode* list = new ListNode(
    1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))
  );

  std::cout << "CASE1\nExpected: 1->2->3->5\n";
  list = removeNthFromEnd(list, 2);
  std::cout << "Received: ";
  printList(list);

  delete(list);
  list = new ListNode(1);

  std::cout << "\n\nCASE2\nExpected: nullptr\n";
  list = removeNthFromEnd(list, 1);
  std::cout << "Received: ";
  printList(list);

  delete(list);
  list = new ListNode(1, new ListNode(2));

  std::cout << "\n\nCASE3\nExpected: 1\n";
  list = removeNthFromEnd(list, 1);
  std::cout << "Received: ";
  printList(list);
  std::cout << std::endl;

  delete(list);
  list = nullptr;

  return 0;
}
