#include <iostream>
#include <vector>

using namespace std;

int main() {
  int lines = 0;
  vector<int> column1;
  vector<int> column2;
  vector<int> column3;

  cin >> lines;

  int temp1 = 0;
  int temp2 = 0;
  int temp3 = 0;
  for (int i = 0; i < lines; i++) {
    cin >> temp1 >> temp2 >> temp3;

    column1.push_back(temp1);
    column2.push_back(temp2);
    column3.push_back(temp3);
  }

  int x = 0; 
  int y = 0;
  int z = 0;

  for (int i = 0; i < column1.size(); i++) {
    x += column1[i];
  }
  for (int i = 0; i < column2.size(); i++) {
    y += column2[i];
  }
  for (int i = 0; i < column3.size(); i++) {
    z += column3[i];
  }

//  cout << x << " " << y << " " << z << endl;

  if ((x == 0) && (y == 0) && (z == 0)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
