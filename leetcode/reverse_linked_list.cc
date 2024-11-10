#include <iostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  ListNode* previous = head;
  ListNode* current = head->next;
  ListNode* newHead = current;

  previous->next = nullptr;

  while (current != nullptr) {
    ListNode* temp = current->next;
    current->next = previous;
    previous = current;
    newHead = current;
    current = temp;
  }

  return newHead;
}

void listPrinter(ListNode* head) {
  if (head == nullptr) {
    std::cout << "[]";
    return;
  }

  std::cout << "[";
  while (head->next != nullptr) {
    std::cout << head->val << ",";
    head = head->next;
  }
  std::cout << head->val << "]";
}

int main() {
  ListNode* headCase1 = new ListNode(
    1, new ListNode(2, new ListNode(3, new ListNode (4, new ListNode(5))))
  );
  ListNode* headCase2 = new ListNode(1, new ListNode(2));
  ListNode* headCase3 = nullptr;
  ListNode* headCase4 = new ListNode(1);

  std::cout << "CASE1\n";
  listPrinter(reverseList(headCase1));
  std::cout << " :got\n[5,4,3,2,1] :expected\n\n";

  std::cout << "CASE2\n";
  listPrinter(reverseList(headCase2));
  std::cout << " :got\n[2,1] :expected\n\n";

  std::cout << "CASE3\n";
  listPrinter(reverseList(headCase3));
  std::cout << " :got\n[] :expected\n\n";

  std::cout << "CASE4\n";
  listPrinter(reverseList(headCase4));
  std::cout << " :got\n[1] :expected" << std::endl;

  return 0;
}
