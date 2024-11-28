#include <vector>
#include <iostream>
#include <unordered_set>

class Solution {
 public:
  void Dfs(std::vector<std::vector<int>>& heights,
            std::unordered_set<int>& st, int y, int x, int prev) {

    if (st.contains((y * heights.size() * heights[0].size()) + x) ||
      y < 0 || x < 0 || y == heights.size() || x == heights[0].size() ||
      heights[y][x] < prev) {
      return;
    }

    st.insert((y * heights.size() * heights[0].size()) + x);

    Dfs(heights, st, y + 1, x, heights[y][x]);
    Dfs(heights, st, y - 1, x, heights[y][x]);

    Dfs(heights, st, y, x + 1, heights[y][x]);
    Dfs(heights, st, y, x - 1, heights[y][x]);
  }

  std::vector<std::vector<int>> PacificAtlantic(std::vector<std::vector<int>> heights) {
    std::vector<std::vector<int>> ans;

    std::unordered_set<int> pac;
    std::unordered_set<int> atl;

    for (int i = 0; i < heights.size(); i++) {
      Dfs(heights, pac, i, 0, heights[i][0]);
      Dfs(heights, atl, i, heights[0].size() - 1, heights[i][heights[0].size() - 1]);
    }

    for (int i = 0; i < heights[0].size(); i++) {
      Dfs(heights, pac, 0, i, heights[0][i]);
      Dfs(heights, atl, heights.size() - 1, i, heights[heights.size() - 1][i]);
    }

    for (int i = 0; i < heights.size(); i++) {
      for (int j = 0; j < heights[0].size(); j++) {
        bool p = pac.contains((i * heights.size() * heights[0].size()) + j);
        bool a = atl.contains((i * heights.size() * heights[0].size()) + j);

        if (p && a) {
          ans.push_back({i, j});
        }
      }
    }

    return ans;
  }
};

int main() {
  Solution s;

  // case 1
  std::vector<std::vector<int>> a = s.PacificAtlantic({
    {1,2,2,3,5},{3,2,3,4,4},
    {2,4,5,3,1},{6,7,1,4,5},
    {5,1,1,2,4}
  });
  std::cout << "CASE1\nExpected: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]\n";
  std::cout << "Received: [";
  for (int i = 0; i < a.size(); i++) {
    if (i == 0) {
      std::cout << "[";
    } else {
      std::cout << ",[";
    }

    for (int j = 0; j < a[i].size(); j++) {
      if (j == 0) {
        std::cout << a[i][j];
      } else {
        std::cout << "," << a[i][j];
      }
    }

    std::cout << "]";
  }
  std::cout << "]\n\n";

  // case 2
  a = s.PacificAtlantic({{1}});
  std::cout << "CASE2\nExpected: [[0,0]]\n";
  std::cout << "Received: [";
  for (int i = 0; i < a.size(); i++) {
    if (i == 0) {
      std::cout << "[";
    } else {
      std::cout << ",[";
    }

    for (int j = 0; j < a[i].size(); j++) {
      if (j == 0) {
        std::cout << a[i][j];
      } else {
        std::cout << "," << a[i][j];
      }
    }

    std::cout << "]";
  }
  std::cout << "]\n\n";

  // case 3
  a = s.PacificAtlantic({{1,2},{4,3}});
  std::cout << "CASE3\nExpected: [[0,1],[1,0],[1,1]]\n";
  std::cout << "Received: [";
  for (int i = 0; i < a.size(); i++) {
    if (i == 0) {
      std::cout << "[";
    } else {
      std::cout << ",[";
    }

    for (int j = 0; j < a[i].size(); j++) {
      if (j == 0) {
        std::cout << a[i][j];
      } else {
        std::cout << "," << a[i][j];
      }
    }

    std::cout << "]";
  }
  std::cout << "]" << std::endl;

  return 0;
}
