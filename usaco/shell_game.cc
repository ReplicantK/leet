#include <iostream>
#include <fstream>

int main() {
  std::ifstream fin("shell.in");
  int n = 0;
  fin >> n;

  int up1 = 1;
  int up2 = 2;
  int up3 = 3;

  int ut1 = 0;
  int ut2 = 0;
  int ut3 = 0;

  for (int i = 0; i < n; i++) {
    int a = 0;
    int b = 0;
    int g = 0;

    fin >> a;
    fin >> b;
    fin >> g;

    if (a == up1) {
      up1 = b;
    } else if (b == up1) {
      up1 = a;
    }

    if (a == up2) {
      up2 = b;
    } else if (b == up2) {
      up2 = a;
    }

    if (a == up3) {
      up3 = b;
    } else if (b == up3) {
      up3 = a;
    }

    if (up1 == g) {
      ut1++; 
    }
    if (up2 == g) {
      ut2++; 
    }
    if (up3 == g) {
      ut3++; 
    }
  }

  int max = 0;

  if (ut1 > ut2) {
    max = ut1;
  } else {
    max = ut2;
  }

  if (ut3 > max) {
    max = ut3;
  }

  std::ofstream fout("shell.out");
  fout << max << "\n";

  return 0;
}
