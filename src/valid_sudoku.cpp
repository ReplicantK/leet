#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
  // rows
  for (vector<char> i : board) {
    unordered_map<char, int> mp;

    for (char j : i) {
      if (j == '.') {
        continue;
      } else if (mp[j] == 1) {
        return false;
      }
        
      mp[j]++;
    }
  }

  // columns
  for (int i = 0; i < 9; i++) {
    unordered_map<char, int> mp;

    for (int j = 0; j < 9; j++) {
      if (board[j][i] == '.') {
        continue;
      } else if (mp[board[j][i]] == 1) {
        return false;
      }

      mp[board[j][i]]++;
    }
  }

  // each square
  for (int leftOffset = 0; leftOffset < 9; leftOffset += 3) {
    for (int topOffset = 0; topOffset < 9; topOffset += 3) {
      unordered_map<char, int> mp;

      for (int topCounter = 0; topCounter < 3; topCounter++) {
        for (int leftCounter = 0; leftCounter < 3; leftCounter++) {
          if (board[topOffset + topCounter][leftOffset + leftCounter] == '.') {
            continue;
          } else if (mp[board[topOffset + topCounter][leftOffset + leftCounter]] == 1) {
            return false;
          }

          mp[board[topOffset + topCounter][leftOffset + leftCounter]]++;
        }
      }
    }
  }

  return true;
}

int main() {
  // test cases boards 1-3
  vector<vector<char>> board1 = {{'5','3','.','.','7','.','.','.','.'},
                                {'6','.','.','1','9','5','.','.','.'},
                                {'.','9','8','.','.','.','.','6','.'},
                                {'8','.','.','.','6','.','.','.','3'},
                                {'4','.','.','8','.','3','.','.','1'},
                                {'7','.','.','.','2','.','.','.','6'},
                                {'.','6','.','.','.','.','2','8','.'},
                                {'.','.','.','4','1','9','.','.','5'},
                                {'.','.','.','.','8','.','.','7','9'}};

  vector<vector<char>> board2 = {{'8','3','.','.','7','.','.','.','.'},
                                 {'6','.','.','1','9','5','.','.','.'},
                                 {'.','9','8','.','.','.','.','6','.'},
                                 {'8','.','.','.','6','.','.','.','3'},
                                 {'4','.','.','8','.','3','.','.','1'},
                                 {'7','.','.','.','2','.','.','.','6'},
                                 {'.','6','.','.','.','.','2','8','.'},
                                 {'.','.','.','4','1','9','.','.','5'},
                                 {'.','.','.','.','8','.','.','7','9'}};
  
  vector<vector<char>> board3 = {{'.','.','4','.','.','.','6','3','.'},
                                 {'.','.','.','.','.','.','.','.','.'},
                                 {'5','.','.','.','.','.','.','9','.'},
                                 {'.','.','.','5','6','.','.','.','.'},
                                 {'4','.','3','.','.','.','.','.','1'},
                                 {'.','.','.','7','.','.','.','.','.'},
                                 {'.','.','.','5','.','.','.','.','.'},
                                 {'.','.','.','.','.','.','.','.','.'},
                                 {'.','.','.','.','.','.','.','.','.'}};

  cout << "Expected: 1 Got: " << isValidSudoku(board1) << endl;
  cout << "Expected: 0 Got: " << isValidSudoku(board2) << endl;
  cout << "Expected: 0 Got: " << isValidSudoku(board3) << endl;

  return 0;
}
