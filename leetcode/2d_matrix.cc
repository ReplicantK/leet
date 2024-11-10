#include <iostream>
#include <algorithm>
#include <vector>

bool search_matrix(std::vector<std::vector<int>>& matrix, int target) {
  for (int i = 0; i < matrix.size(); i++) {
    if (matrix[i][0] == target) {
      return true;
    } else if (matrix[i][0] > target) {
      return std::binary_search(matrix[i - 1].begin(), matrix[i - 1].end(), target);
    }
  }

  return false;
}

int main() {
  int targetTest1 = 3;
  
  std::vector<std::vector<int>> arrTest1 = {
    {1, 3, 5, 7},
    {10, 11, 16, 20},
    {23, 30, 34, 60}
  };

  int targetTest2 = 13;
  
  std::vector<std::vector<int>> arrTest2 = {
    {1, 3, 5, 7},
    {10, 11, 16, 20},
    {23, 30, 34, 60}
  };

  std::cout << "test case 1: ";
  if (search_matrix(arrTest1, targetTest1)) {
    std::cout << "true" << std::endl; 
  } else {
    std::cout << "false" << std::endl; 
  }

  std::cout << "test case 2: ";
  if (search_matrix(arrTest2, targetTest2)) {
    std::cout << "true" << std::endl; 
  } else {
    std::cout << "false" << std::endl; 
  }

  return 0;
}
