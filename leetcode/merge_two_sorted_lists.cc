#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  ListNode* ans = nullptr;
  ListNode* forward = nullptr;
  
  if (list1 == nullptr && list2 == nullptr) {
    return ans;
  } else if (list1 != nullptr && list2 == nullptr) {
    forward = list1;
    list1 = list1->next;
  } else if (list2 != nullptr && list1 == nullptr) {
    forward = list2;
    list2 = list2->next;
  } else if (list1->val < list2->val) {
    forward = list1;
    list1 = list1->next;
  } else {
    forward = list2;
    list2 = list2->next;
  }

  ans = forward;

  while (list1 != nullptr || list2 != nullptr) {
    if (list1 != nullptr && list2 == nullptr) {
      forward->next = list1;
      list1 = list1->next;
    } else if (list2 != nullptr && list1 == nullptr) {
      forward->next = list2;
      list2 = list2->next;
    } else if (list1->val < list2->val) {
      forward->next = list1;
      list1 = list1->next;
    } else {
      forward->next = list2;
      list2 = list2->next;
    }

    forward = forward->next;
  }

  return ans;
}

void listPrinter(ListNode* l) {
  std::cout << "[";

  if (l == nullptr) {
    std::cout << "]";
    return;
  }

  while (l->next != nullptr) {
    std::cout << l->val << ",";
    l = l->next;
  }
  std::cout << l->val << "]";
}

int main() {
  ListNode* case1list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
  ListNode* case1list2 = new ListNode(1, new ListNode(3, new ListNode(4)));

  ListNode* case2list1 = nullptr;
  ListNode* case2list2 = nullptr;

  ListNode* case3list1 = nullptr;
  ListNode* case3list2 = new ListNode(0);

  ListNode* case4list1 = new ListNode(1);
  ListNode* case4list2 = new ListNode(2);

  std::cout << "CASE1\n";
  listPrinter(mergeTwoLists(case1list1, case1list2));
  std::cout << " :got\n[1,1,2,3,4,4] :expected\n\n";

  std::cout << "CASE2\n";
  listPrinter(mergeTwoLists(case2list1, case2list2));
  std::cout << " :got\n[] :expected\n\n";

  std::cout << "CASE3\n";
  listPrinter(mergeTwoLists(case3list1, case3list2));
  std::cout << " :got\n[0] :expected\n\n";

  std::cout << "CASE4\n";
  listPrinter(mergeTwoLists(case4list1, case4list2));
  std::cout << " :got\n[1,2] :expected" << std::endl;

  delete(case1list1);
  delete(case1list2);

  delete(case2list1);
  delete(case2list2);

  delete(case3list1);
  delete(case3list2);

  delete(case4list1);
  delete(case4list2);

  return 0;
}
