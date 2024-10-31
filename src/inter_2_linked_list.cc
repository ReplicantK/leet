#include <iostream>
#include <unordered_set>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
  std::unordered_set<ListNode*> s;

  while (headA != nullptr) {
    s.insert(headA);
    headA = headA->next;
  }

  while (headB != nullptr) {
    if (s.contains(headB)) {
      return headB;
    }

    headB = headB->next;
  }

  return nullptr;
}

int main() {
  ListNode* listAcase1 = new ListNode(4);
  listAcase1->next = new ListNode(1);
  listAcase1->next->next = new ListNode(8);
  listAcase1->next->next->next = new ListNode(4);
  listAcase1->next->next->next->next = new ListNode(5);

  ListNode* listBcase1 = new ListNode(5);
  listBcase1->next = new ListNode(6);
  listBcase1->next->next = new ListNode(1);
  listBcase1->next->next->next = listAcase1->next->next;
  listBcase1->next->next->next->next = new ListNode(4);
  listBcase1->next->next->next->next->next = new ListNode(5);

  std::cout << "CASE 1\ngot ";
  ListNode* returnedVal = getIntersectionNode(listAcase1, listBcase1);
  if (returnedVal) {
    std::cout << returnedVal->val; 
  } else {
    std::cout << "nullptr";
  }
  std::cout << "\nexpected 8\n\n";

  ListNode* listAcase2 = new ListNode(1);
  listAcase2->next = new ListNode(9);
  listAcase2->next->next = new ListNode(1);
  listAcase2->next->next->next = new ListNode(2);
  listAcase2->next->next->next->next = new ListNode(4);

  ListNode* listBcase2 = new ListNode(3);
  listBcase2->next = listAcase2->next->next->next;
  listBcase2->next->next = new ListNode(4);

  std::cout << "CASE 2\ngot ";
  returnedVal = getIntersectionNode(listAcase2, listBcase2);
  if (returnedVal) {
    std::cout << returnedVal->val; 
  } else {
    std::cout << "nullptr";
  }
  std::cout << "\nexpected 2\n\n";
  
  ListNode* listAcase3 = new ListNode(2);
  listAcase3->next = new ListNode(6);
  listAcase3->next->next = new ListNode(4);

  ListNode* listBcase3 = new ListNode(1);
  listBcase3->next = new ListNode(5);
  
  std::cout << "CASE 3\ngot ";
  returnedVal = getIntersectionNode(listAcase3, listBcase3);
  if (returnedVal) {
    std::cout << returnedVal->val; 
  } else {
    std::cout << "nullptr";
  }
  std::cout << "\nexpected nullptr" << std::endl;

  return 0;
}
