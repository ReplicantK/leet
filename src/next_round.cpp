#include <iostream>

using namespace std;

int main() {
  int n, k = 0;

  cin >> n;
  cin >> k;
  
  int arr[n];

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  
  int totalPassed = 0;

  for (int i = 0; i < n; i++) {
    if (arr[i] >= arr[k-1] && arr[i] > 0) {
      totalPassed++;
    }
  }

  cout << totalPassed << endl;

  return 0;
}
