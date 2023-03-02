#include <iostream>

using namespace std;

int main() {
  int arr2d[5][5]; 

  int findOne = 0;
  int saveRow = 0;
  int saveCol = 0;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> findOne;

      arr2d[i][j] = findOne;

      if (findOne == 1) {
        saveRow = i;
        saveCol = j;
      }
    }
  }
  
  int totalMove = 0;

  if (2 > saveRow) {
    totalMove = 2 - saveRow;
  } else {
    totalMove = saveRow - 2;
  }

  if (2 > saveCol) {
    totalMove += 2 - saveCol;
  } else {
    totalMove += saveCol - 2;
  }

  cout << totalMove << endl;

  return 0;
}
