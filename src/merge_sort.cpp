#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int>& vec) {
  if (vec.size() == 1) {
    return;
  }
  
  vector<int> left_vec(vec.size() / 2, 0);
  vector<int> right_vec(vec.size() - (vec.size() / 2), 0);

  vector<int>::iterator l_it;
  vector<int>::iterator r_it;
  int i = 0;

  for (l_it = left_vec.begin(); l_it != left_vec.end(); i++, l_it++) {
    *l_it = vec[i];
  }
  for (r_it = right_vec.begin(); r_it != right_vec.end(); i++, r_it++) {
    *r_it = vec[i];
  }

  merge_sort(left_vec);
  merge_sort(right_vec);

  i = 0;
  l_it = left_vec.begin();
  r_it = right_vec.begin();
  while (l_it != left_vec.end() && r_it != right_vec.end()) {
    if (*l_it < *r_it) {
      vec[i] = *l_it;
      l_it++;
    } else {
      vec[i] = *r_it;
      r_it++;
    }

    i++;
  }

  while (l_it != left_vec.end()) {
    vec[i] = *l_it;
    l_it++;
    i++;
  }

  while (r_it != right_vec.end()) {
    vec[i] = *r_it;
    r_it++;
    i++;
  }
}

int main() {
  vector<vector<int>> cases = {{123,12,2185,61,18384,0,-13,6582,9}, {38,27,43,3,9,10}, {234,2,235,5}, {9,3}, {1}};

  for (vector<int> i : cases) {
    cout << "[";
    for (int j = 0; j < i.size() - 1; j++) {
      cout << i[j] << ",";
    }
    cout << i[i.size() - 1];
    cout << "]";

    cout << " -> ";
    merge_sort(i);

    cout << "[";
    for (int j = 0; j < i.size() - 1; j++) {
      cout << i[j] << ",";
    }
    cout << i[i.size() - 1];
    cout << "]";
    cout << endl;
  }

  return 0;
}
