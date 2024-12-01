#include <iostream>
#include <fstream>

int main() {
  std::ifstream in("mixmilk.in");

  int c1 = 0;
  int c2 = 0;
  int c3 = 0;

  int m1 = 0;
  int m2 = 0;
  int m3 = 0;

  in >> c1 >> m1;
  in >> c2 >> m2;
  in >> c3 >> m3;

  int pour = 0;

  for (int i = 0; i < 100; i++) {
    if (pour == 0 && m2 + m1 <= c2) {
      m2 += m1;
      m1 = 0;
    } else if (pour == 0 && m2 + m1 > c2) {
      int temp = m1 + m2;
      m2 = c2;
      m1 = temp - c2;
    } else if (pour == 1 && m3 + m2 <= c3) {
      m3 += m2;
      m2 = 0;
    } else if (pour == 1 && m3 + m2 > c3) {
      int temp = m2 + m3;
      m3 = c3;
      m2 = temp - c3;
    } else if (pour == 2 && m1 + m3 <= c1) {
      m1 += m3;
      m3 = 0;
    } else {
      int temp = m3 + m1;
      m1 = c1;
      m3 = temp - c1;
    }

    if (pour == 2) {
      pour = 0;
    } else {
      pour++;
    }
  }

  std::ofstream out("mixmilk.out");

  out << m1 << "\n";
  out << m2 << "\n";
  out << m3 << "\n";

  return 0;
}
