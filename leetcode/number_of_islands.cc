#include <iostream>
#include <vector>

class Solution {
 public:
  void dfs(std::vector<std::vector<char>>& grid, int y, int x) {
    if (y < 0 || x < 0 || y > grid.size()-1 || x > grid[0].size()-1 || grid[y][x] == '0') {
      return;
    }

    // mark as visited and clockwise recursion: right, down, left, up
    grid[y][x] = '0';
    dfs(grid, y, x + 1);
    dfs(grid, y + 1, x);
    dfs(grid, y, x - 1);
    dfs(grid, y - 1, x);
  }

  int numIslands(std::vector<std::vector<char>> grid) {
    int islands = 0;
    
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] == '1') {
          islands++;
          dfs(grid, i, j);
        }
      }
    }

    return islands;
  }
};

int main() {
  Solution s;
  std::cout << "CASE1\nExpected: 1\nReceived: ";
  std::cout << s.numIslands(
    {{'1','1','1','1','0'},
    {'1','1','0','1','0'},
    {'1','1','0','0','0'},
    {'0','0','0','0','0'}}
  );
  std::cout << "\n\n";
  
  std::cout << "CASE2\nExpected: 3\nReceived: ";
  std::cout << s.numIslands(
    {{'1','1','0','0','0'},
    {'1','1','0','0','0'},
    {'0','0','1','0','0'},
    {'0','0','0','1','1'}}
  );

  std::cout << std::endl;

  return 0;
}
