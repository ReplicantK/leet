#include <vector>
#include <fstream>
#include <algorithm>

struct CowInfo {
  int s;
  int e;
  int b;
};

int main() {
  std::ifstream in("blist.in");

  int cows = 0;
  in >> cows;

  std::vector<CowInfo> v;
  v.reserve(cows);

  for (int i = 0; i < cows; i++) {
    CowInfo n;

    in >> n.s;
    in >> n.e;
    in >> n.b;

    v.emplace_back(n);
  }

  std::sort(v.begin(), v.end(), [](const CowInfo& a, const CowInfo& b) {
    return a.s < b.s;
  });

  int max = v[0].b;

  for (int i = 1; i < v.size(); i++) {
    int it_max = 0;

    for (int j = 0; j < i; j++) {
      if (v[j].e > v[i].s) {
        it_max += v[j].b;
      }
    }

    it_max += v[i].b;

    if (it_max > max) {
      max = it_max;
    }
  }

  std::ofstream out("blist.out");
  out << max << "\n";

  return 0;
}
