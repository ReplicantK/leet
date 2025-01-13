#include <string>
#include <vector>

class Solution {
 public:
  std::vector<int> MinOperations(std::string boxes) {
    std::vector<int> v(boxes.size());

    for (int i = 0; i < boxes.size(); i++) {
      int counter = 0;

      for (int j = 0; j < boxes.size(); j++) {
        if (boxes[j] == '1') {
          counter += std::abs(i - j);
        }
      }

      v[i] = counter;
    }
    
    return v;  
  }
};
