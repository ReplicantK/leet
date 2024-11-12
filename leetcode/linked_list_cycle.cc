#include <iostream>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool hasCycle(ListNode* head) {
  ListNode* slow = head;
  ListNode* fast = head;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
      return true;
    }
  }
  
  return false;
}

int main() {
  // used to delete all allocated nodes at the end
  std::vector<ListNode*> v;

  // case 1
  ListNode* list = new ListNode(3);
  v.push_back(list);

  ListNode* temp = new ListNode(2);
  v.push_back(temp);
  list->next = temp;

  temp = new ListNode(0);
  v.push_back(temp);
  list->next->next = temp;

  temp = new ListNode(-4);
  v.push_back(temp);
  list->next->next->next = temp;

  list->next->next->next->next = list->next;

  std::cout << "CASE1\n";
  std::cout << "Expected: true\n";
  std::cout << "Received: ";

  if (hasCycle(list)) {
    std::cout << "true\n\n";
  } else {
    std::cout << "false\n\n";
  }

  // case 2
  list = new ListNode(1);
  v.push_back(list);

  temp = new ListNode(2);
  v.push_back(temp);
  list->next = temp;

  list->next->next = list;

  std::cout << "CASE2\n";
  std::cout << "Expected: true\n";
  std::cout << "Received: ";

  if (hasCycle(list)) {
    std::cout << "true\n\n";
  } else {
    std::cout << "false\n\n";
  }

  // case 3
  list = new ListNode(1);
  v.push_back(list);

  std::cout << "CASE3\n";
  std::cout << "Expected: false\n";
  std::cout << "Received: ";

  if (hasCycle(list)) {
    std::cout << "true\n\n";
  } else {
    std::cout << "false\n\n";
  }

  // case 4
  list = nullptr;

  std::cout << "CASE4\n";
  std::cout << "Expected: false\n";
  std::cout << "Received: ";

  if (hasCycle(list)) {
    std::cout << "true\n\n";
  } else {
    std::cout << "false\n\n";
  }

  // case 5
  list = new ListNode(-1);
  v.push_back(list);

  temp = new ListNode(-7);
  v.push_back(temp);
  list->next = temp;

  temp = new ListNode(7);
  v.push_back(temp);
  list->next->next = temp;

  temp = new ListNode(-4);
  v.push_back(temp);
  list->next->next->next = temp;

  temp = new ListNode(19);
  v.push_back(temp);
  list->next->next->next->next = temp;

  temp = new ListNode(6);
  v.push_back(temp);
  list->next->next->next->next->next = temp;

  temp = new ListNode(-9);
  v.push_back(temp);
  list->next->next->next->next->next->next = temp;

  temp = new ListNode(-5);
  v.push_back(temp);
  list->next->next->next->next->next->next->next = temp;

  temp = new ListNode(-2);
  v.push_back(temp);
  list->next->next->next->next->next->next->next->next = temp;

  temp = new ListNode(-5);
  v.push_back(temp);
  list->next->next->next->next->next->next->next->next->next = temp;

  list->next->next->next->next->next->next = list->next->next->next->next;

  std::cout << "CASE5\n";
  std::cout << "Expected: true\n";
  std::cout << "Received: ";

  if (hasCycle(list)) {
    std::cout << "true\n\n";
  } else {
    std::cout << "false\n\n";
  }

  // case 6
  list = new ListNode(1);
  v.push_back(list);

  temp = new ListNode(2);
  v.push_back(temp);

  list->next = temp;

  std::cout << "CASE6\n";
  std::cout << "Expected: false\n";
  std::cout << "Received: ";

  if (hasCycle(list)) {
    std::cout << "true" << std::endl;
  } else {
    std::cout << "false" << std::endl;
  }

  // unallocated all the memory used by the nodes
  for (ListNode* i : v) {
    delete(i);
  }

  return 0;
}
