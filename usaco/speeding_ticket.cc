#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>

int main() {
  std::ifstream in("speeding.in");

  int rsize = 0, csize = 0;
  in >> rsize >> csize;

  std::vector<int> road(rsize), cow(csize);
  std::unordered_map<int, int> rspeed, cspeed;

  for (int i = 0; i < rsize; i++) {
    int l = 0;
    int s = 0;
    in >> l >> s;

    road[i] = l;
    rspeed[i] = s;
  }

  for (int i = 0; i < csize; i++) {
    int l = 0;
    int s = 0;
    in >> l >> s;

    cow[i] = l;
    cspeed[i] = s;
  }

  int roadp = 0, cowp = 0;
  int max = 0;

  while (roadp < rsize || cowp < csize) {
    int over = cspeed[cowp] - rspeed[roadp];
    if (over > 0 && over > max) {
      max = over;
    }

    int diff = road[roadp] - cow[cowp];

    if (diff == 0) {
      roadp++;
      cowp++;
    } else if (diff > 0) {
      road[roadp] = diff;
      cowp++;
    } else {
      roadp++;
      cow[cowp] = diff * -1;
    }
  }

  std::ofstream out("speeding.out");
  out << max << "\n";

  return 0;
}
