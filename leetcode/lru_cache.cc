#include <iostream>
#include <utility>
#include <unordered_map>
#include <list>

class LRUCache {
  private:
    std::list<std::pair<int, int>> l;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> keyValue;
    int cap = 0;

  public:
    LRUCache(int capacity) {
      cap = capacity;
    }
    
    int get(int key) {
      if (!keyValue.contains(key)) {
        return -1;
      }

      int value = keyValue[key]->first;

      l.erase(keyValue[key]);
      l.push_back({value, key});

      std::list<std::pair<int, int>>::iterator last = --l.end();
      keyValue[key] = last;

      return value;
    }
    
    void put(int key, int value) {
      if (keyValue.contains(key)) {
        l.erase(keyValue[key]);
      } else if (l.size() == cap) {
        std::list<std::pair<int, int>>::iterator first = l.begin();
        keyValue.erase(first->second);
        l.erase(first);
      } 

      l.push_back({value, key});

      std::list<std::pair<int, int>>::iterator last = --l.end();
      keyValue[key] = last;
    }
};

int main() {
  LRUCache* obj = nullptr;

  // test case 1
  std::cout << "CASE1\n";
  obj = new LRUCache(2);
  obj->put(1, 1);
  obj->put(2, 2);
  std::cout << "Expected: 1\n" << "Received: " << obj->get(1) << "\n\n";
  obj->put(3, 3);
  std::cout << "Expected: -1\n" << "Received: " << obj->get(2) << "\n\n";
  obj->put(4, 4);
  std::cout << "Expected: -1\n" << "Received: " << obj->get(1) << "\n\n";
  std::cout << "Expected: 3\n" << "Received: " << obj->get(3) << "\n\n";
  std::cout << "Expected: 4\n" << "Received: " << obj->get(4) << "\n\n";
  delete(obj);

  // test case 2
  std::cout << "-------\n\nCASE2\n";
  obj = new LRUCache(2);
  obj->put(2, 6);
  std::cout << "Expected: -1\n" << "Received: " << obj->get(1) << "\n\n";
  obj->put(1, 5);
  obj->put(1, 2);
  std::cout << "Expected: 2\n" << "Received: " << obj->get(1) << "\n\n";
  std::cout << "Expected: 6\n" << "Received: " << obj->get(2) << std::endl;

  return 0;
}
