#include <iostream>
#include <string>

int main() {
  std::string dna = "";
  std::cin >> dna;

  int max = 0;
  int current = 0;
  char last = dna[0];

  for (char i : dna) {
    if (last == i) {
      current++;
      continue;
    } 

    if (current > max) {
      max = current;
    }

    last = i;
    current = 1;
  }

  if (current > max) {
    max = current;
  }

  std::cout << max << std::endl;

  return 0;
}
