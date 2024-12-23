#include <iostream>
#include <vector>

int PeakIndexInMountainArray(std::vector<int> arr) {
  int l = 0, r = arr.size() - 1, mid = 0;

  while (l <= r) {
    mid = l + (r - l) / 2;

    if (arr[mid] >= arr[l] && arr[mid] >= arr[r]) {
      l++;
      r--;
    } else if (arr[mid] < arr[l]) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  return mid;
}

int main() {
  std::cout << "CASE1\nExpected: 1\nReceived: " << PeakIndexInMountainArray({0, 1, 0});
  std::cout << "\n\nCASE2\nExpected: 1\nReceived: " << PeakIndexInMountainArray({0, 2, 1, 0});
  std::cout << "\n\nCASE3\nExpected: 1\nReceived: " << PeakIndexInMountainArray({0, 10, 5, 2});
  std::cout << "\n\nCASE4\nExpected: 1\nReceived: " << PeakIndexInMountainArray({3, 5, 3, 2, 0});
  std::cout << "\n";

  return 0;
}
