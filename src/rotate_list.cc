#include <unordered_map>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) {
 if (head == nullptr || head->next == nullptr) {
   return head;
 }

 unordered_map<int, ListNode*> mp;

 ListNode* current = head;
 int index = 0;
 mp[index] = current;

 current = current->next;
 while (current->next) {
   index++;
   mp[index] = current;
   current = current->next;
 }

 index++;
 mp[index] = current;

 int reverseK = k % mp.size();

 if (reverseK == 0) {
   return head;
 }

 ListNode* newHead = mp[mp.size() - reverseK - 1]->next;
 current->next = head;
 mp[mp.size() - reverseK - 1]->next = nullptr;

 return newHead;
}

int main() {
  ListNode* test1 = new ListNode(1, new ListNode(2));
  test1->next->next = new ListNode(3);
  test1->next->next->next = new ListNode(4);
  test1->next->next->next->next = new ListNode(5);

  ListNode* print = test1;

  while (print != nullptr) {
    cout << print->val << " ";
    print = print->next;
  }
  cout << "\n";

  print = rotateRight(test1, 2);
  while (print != nullptr) {
    cout << print->val << " ";
    print = print->next;
  }
  cout << "\n\n";

  ListNode* test2 = new ListNode(0, new ListNode(1));
  test2->next->next = new ListNode(2);
  print = test2;

  while (print != nullptr) {
    cout << print->val << " ";
    print = print->next;
  }
  cout << "\n";

  print = rotateRight(test2, 4);
  while (print != nullptr) {
    cout << print->val << " ";
    print = print->next;
  }

  cout << endl;

  return 0;
}
