#include <iostream>
#include <string>

using namespace std;

int main() {
  string word1 = "abcd";
  string word2 = "pq";
  string out = "";

  while ((word1.length() != 0) && (word2.length() != 0)) {
    out.push_back(word1.at(0));
    out.push_back(word2.at(0));

    word1.erase(word1.begin());
    word2.erase(word2.begin());
  }

  if (word1.length() != 0) {
    out += word1;
  } else {
    out += word2;
  }

  cout << out << endl;

  return 0;
}
