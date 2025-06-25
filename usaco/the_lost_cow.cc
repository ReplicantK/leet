#include <fstream>

int main() {
  std::ifstream in("lostcow.in");

  int x = 0;
  int y = 0;
  
  in >> x;
  in >> y;
  
  int total = 0;
  int counter = 1;

  int i = 1;

  while (true) {
    int it_loc = x;

    for (int j = 0; j < counter; j++) {
      total++;

      if (i % 2 == 0) {
        it_loc--;
      } else {
        it_loc++;
      }

      if (it_loc == y) {
        break;
      }
    }

    if (it_loc == y) {
      break;
    }

    for (int j = 0; j < counter; j++) {
      total++;

      if (i % 2 == 0) {
        it_loc++;
      } else {
        it_loc--;
      }

      if (it_loc == y) {
        break;
      }
    }

    if (it_loc == y) {
      break;
    }

    counter *= 2;
    i++;
  }

  std::ofstream out("lostcow.out");
  out << total << '\n';

  return 0;
}
