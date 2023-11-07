#include <iostream>

using namespace std;

bool isBadVersion(int version) {
  if (version == 4) {
    return true;
  }

  return false;
}

int firstBadVersion(int n) {
  unsigned int start = 0;
  unsigned int end = n;
  unsigned int mid = 0;

  while (start < end) {
    mid = (start + end) / 2;

    if (isBadVersion(mid) == false) {
      start = mid + 1;
    } else {
      end = mid;
    }
  }

  return start;
}

int main() {
  cout << firstBadVersion(5) << endl;
  return 0;
}
