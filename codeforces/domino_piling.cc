#include <iostream>
#include <math.h>

using namespace std;

int main() {
  float domino = 2;   
  float m, n = 0;  
  float squareS = 0;

  cin >> m >> n;

  squareS = m * n;
  
  cout << floor(squareS / domino) << endl;

  return 0;
}
