#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
 public:
  std::unordered_set<int> s_;

  void Dfs(std::vector<std::vector<char>>& board, int y, int x) {
    int key = (board.size() * board[0].size() * y) + x;

    if (x < 0 || y < 0 || x == board[0].size() || y == board.size() ||
        s_.contains(key) || board[y][x] == 'X') {
      return; 
    }

    s_.insert(key);

    Dfs(board, y + 1, x); 
    Dfs(board, y - 1, x); 
    
    Dfs(board, y, x + 1); 
    Dfs(board, y, x - 1); 
  }

  void Solve(std::vector<std::vector<char>>& board) {
    for (int i = 0; i < board.size(); i++) {
      Dfs(board, i, 0);
      Dfs(board, i, board[0].size() - 1);
    }

    for (int i = 1; i < board[0].size() - 1; i++) {
      Dfs(board, 0, i);
      Dfs(board, board.size() - 1, i);
    }

    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        int key = (board.size() * board[0].size() * i) + j;

        if (board[i][j] != 'X' && !s_.contains(key)) {
          board[i][j] = 'X';
        }
      }
    }
  }
};

int main() {
  Solution s;

  // case 1;
  std::vector<std::vector<char>> board = {
    {'X','X','X','X'},
    {'X','O','O','X'},
    {'X','X','O','X'},
    {'X','O','X','X'}
  };
  
  s.Solve(board);
  std::cout << "CASE1\nExpected: [['X','X','X','X'],['X','X','X','X'],";
  std::cout << "['X','X','X','X'],['X','O','X','X']]\nReceived: [";

  for (int i = 0; i < board.size(); i++) {
    if (i == 0) {
      std::cout << "[";
    } else {
      std::cout << ",[";
    }

    for (int j = 0; j < board[i].size(); j++) {
      if (j == 0) {
        std::cout << "'" << board[i][j] << "'";
      } else {
        std::cout << ",'" << board[i][j] << "'";
      }
    }

    std::cout << "]";
  }

  std::cout << "]\n\n";
  
  // case 2;
  board = {{'X'}};
  
  s.Solve(board);
  std::cout << "CASE2\nExpected: [['X']]\nReceived: [";

  for (int i = 0; i < board.size(); i++) {
    if (i == 0) {
      std::cout << "[";
    } else {
      std::cout << ",[";
    }

    for (int j = 0; j < board[i].size(); j++) {
      if (j == 0) {
        std::cout << "'" << board[i][j] << "'";
      } else {
        std::cout << ",'" << board[i][j] << "'";
      }
    }

    std::cout << "]";
  }

  std::cout << "]" << std::endl;

  return 0;
}
