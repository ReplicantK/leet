#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
  // test case 1
  vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

  // test case 2
  //vector<string> strs = {};

  // test case 3
  //vector<string> strs = {"a"};

  // solution
  unordered_map<string, vector<string>> mp;
  vector<vector<string>> results;
  string temp = "";

  for (int i = 0; i < strs.size(); i++) {
    temp = strs.at(i);
    sort(strs.at(i).begin(), strs.at(i).end());

    mp[strs.at(i)].push_back(temp);
  }

  for (unordered_map<string, vector<string>>::iterator i = mp.begin(); i != mp.end(); i++) {
    results.push_back(i->second);
  }

  // check if solution is correct
  for (int i = 0; i < results.size(); i++) {
    for (int j = 0; j < results.at(i).size(); j++) {
      cout << results.at(i).at(j) << " ";
    }

    cout << endl;
  }

  return 0;
}
