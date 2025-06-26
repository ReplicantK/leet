#include <fstream>
#include <string>
#include <vector>

int main() {
  std::ifstream in("shuffle.in");

  int num_cows = 0;
  in >> num_cows;

  std::vector<int> shuf;
  shuf.reserve(num_cows);

  for (int i = 0; i < num_cows; i++) {
    int temp = 0;
    in >> temp;
    shuf.emplace_back(temp);
  }

  std::vector<std::string> ids;
  ids.reserve(num_cows);

  for (int i = 0; i < num_cows; i++) {
    std::string temp;
    in >> temp;
    ids.emplace_back(temp);
  }

  std::vector<std::vector<std::string>> new_pos;
  new_pos.reserve(3);

  std::vector<std::string> first(num_cows);

  for (int i = 0; i < ids.size(); i++) {
    int pos = shuf[i] - 1;
    first[i] = ids[pos];
  }

  new_pos.emplace_back(first);

  for (int i = 1; i < 3; i++) {
    std::vector<std::string> temp(num_cows);

    for (int j = 0; j < ids.size(); j++) {
      int pos = shuf[j] - 1;
      temp[j] = new_pos[i - 1][pos];
    }

    new_pos.emplace_back(temp);
  }

  std::ofstream out("shuffle.out");
  for (std::string i : new_pos.back()) {
    out << i << '\n';
  }

  return 0;
}
