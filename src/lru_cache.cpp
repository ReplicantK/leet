#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
  private:
    int val = INT_MAX;
    Node* next = NULL;
    Node* prev = NULL;

  public:
    // constructor
    Node(int val) {
      this->val = val;
    }

    // setter and getter for value in list node
    int getVal() {
      return val;
    }

    void setVal(int val) {
      this->val = val;
    }

    // setter and getter for next pointer in list node
    Node* getNext() {
      return next;
    }

    void setNext(Node* next) {
      this->next = next;
    }

    // setter and getter for prev pointer in list node
    Node* getPrev() {
      return prev;
    }

    void setPrev(Node* prev) {
      this->prev = prev;
    }
};

class LRUCache {
  private:
    unordered_map<int, Node*> map;
    unordered_map<Node*, int> map2;
    int capacity = 0;
    int currentSize = 0;
    Node* tail = NULL;
    Node* head = NULL;

  public:
    LRUCache(int capacity) {
      this->capacity = capacity;
    }

    int get(int key) {
      Node* value = NULL;

      if (!map.contains(key)) {
        return -1;
      } else {
        value = map[key];
      }

      if (value != head) {
        if (value == tail) {
          tail = value->getNext();
        } else {
          value->getPrev()->setNext(value->getNext());
        }

        value->getNext()->setPrev(value->getPrev());
        head->setNext(value);
        value->setPrev(head);
        head = value;
        head->setNext(NULL);
      }

      return value->getVal();
    }

    void put(int key, int value) {
      if ((head == NULL) && (tail == NULL)) {
        Node* newNode = new Node(value);

        head = newNode;
        tail = newNode;

        tail->setNext(head);
        head->setPrev(tail);

        currentSize++;
      } else if (map.contains(key)) {
        Node* temp = map.at(key);

        if (temp == tail) {
          temp->getNext()->setPrev(NULL);

          head->setNext(temp);
          temp->setPrev(head);

          tail = temp->getNext();
          head = temp;
          head->setNext(NULL);
        } else if (temp != head) {
          temp->getPrev()->setNext(temp->getNext());
          temp->getNext()->setPrev(temp->getPrev());

          head->setNext(temp);
          temp->setPrev(head);
          temp->setNext(NULL);

          head = temp;
        } 

        head->setVal(value);

      } else if (currentSize < capacity) {
        Node* newNode = new Node(value);

        newNode->setPrev(head);
        head->setNext(newNode);
        head = newNode;
        tail->setPrev(NULL);

        currentSize++;
      } else {
        Node* newNode = new Node(value);
        Node* temp = tail;

        if (capacity != 1) {
          tail = tail->getNext();
          tail->setPrev(NULL);

          head->setNext(newNode);
          newNode->setPrev(head);

          head = newNode;

        } else {
          head = newNode;
          tail = newNode;

          tail->setNext(head);
          head->setPrev(tail);
        }

        map.erase(map2.at(temp));
        map2.erase(temp);

        delete temp;
      }

      map.insert({key, head});
      map2.insert({head, key});
    }

    void test() {
      cout << head << endl;
      cout << tail << endl;
      //cout << "capacity " << capacity << " current size " << currentSize << endl;
      //for (auto it = map.begin(); it != map.end(); it++) {
      //  cout << "{" << it->first << ": " << it->second->getVal() << "}" << endl;
      //}

      //cout << endl;
      //Node* test = tail;
      //while (test != NULL) {
      //  cout << test->getVal() << endl;
      //  test = test->getNext();
      //}
    }
};

int main() {
  LRUCache* obj = new LRUCache(1);
  cout << obj->get(6) << endl;
  cout << obj->get(8) << endl;
  obj->put(12, 1);
  cout << obj->get(2) << endl;
  obj->put(15, 11);
  obj->put(5, 2);
  obj->put(1, 15);
  obj->put(4, 2);
  cout << obj->get(5) << endl;
  obj->put(15, 15);

  return 0;
}
