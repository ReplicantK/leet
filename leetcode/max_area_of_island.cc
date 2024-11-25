#include <iostream>
#include <vector>

int dfs(std::vector<std::vector<int>>& grid, int x, int y) {
  if (y < 0 || x < 0 || y == grid.size() || x == grid[y].size() || grid[y][x] == 0) {
    return 0;
  }

  grid[y][x] = 0;

  int right = dfs(grid, x + 1, y);
  int down = dfs(grid, x, y + 1);
  int left = dfs(grid, x - 1, y);
  int up = dfs(grid, x, y - 1);

  return 1 + right + down + left + up;
}

int maxAreaOfIsland(std::vector<std::vector<int>> grid) {
  int max = 0;

  for (int y = 0; y < grid.size(); y++) {
    for (int x = 0; x < grid[y].size(); x++) {
      if (grid[y][x] == 1) {
        int current = dfs(grid, x,  y);

        if (current > max) {
          max = current;
        }
      }
    }
  }  

  return max;
}

int main() {
  // case 1
  std::cout << "CASE1\nExpected: 6\nReceived: " << maxAreaOfIsland({
    {0,0,1,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,1,1,0,1,0,0,0,0,0,0,0,0},
    {0,1,0,0,1,1,0,0,1,0,1,0,0},
    {0,1,0,0,1,1,0,0,1,1,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,0,0,0,0,0,0,1,1,0,0,0,0}
  });

  // case 2
  std::cout << "\n\nCASE2\nExpected: 0\nReceived: " << maxAreaOfIsland({
    {0,0,0,0,0,0,0,0}
  });
  std::cout << std::endl;

  return 0;
}
