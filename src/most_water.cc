#include <iostream>
#include <vector>

int maxArea(std::vector<int>& height) {
  int lp = 0;
  int rp = height.size() - 1;
  int max = 0;

  while (lp <= rp) {
    int yaxis = 0;
    int xaxis = rp - lp;

    if (height[lp] < height[rp]) {
      yaxis = height[lp];
      lp++;
    } else {
      yaxis = height[rp];
      rp--;
    }


    if ((yaxis * xaxis) > max) {
      max = yaxis * xaxis;
    }
  }

  return max;
}

int main() {
  std::vector<int> case1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  int case1a = 49;
  std::cout << "Case1 expected - " << case1a << "\n";
  std::cout << "Case1 got - " << maxArea(case1) << "\n\n";

  std::vector<int> case2 = {1, 1};
  int case2a = 1;
  std::cout << "Case2 expected - " << case2a << "\n";
  std::cout << "Case2 got - " << maxArea(case2) << "\n\n";

  std::vector<int> case3 = {1, 2, 1};
  int case3a = 2;
  std::cout << "Case3 expected - " << case3a << "\n";
  std::cout << "Case3 got - " << maxArea(case3) << std::endl;

  return 0;
}
