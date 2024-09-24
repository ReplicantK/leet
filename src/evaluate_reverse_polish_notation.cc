#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  // test cases
  //vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
  vector<string> tokens = {"4","13","5","/","+"};
  
  // solution
  int i = 0;

  while (tokens.size() != 1) {
    if (tokens.at(i) == "/") {
      tokens.at(i - 2) = to_string(stoi(tokens.at(i - 2)) / stoi(tokens.at(i - 1)));

      tokens.erase(tokens.begin() + (i));
      tokens.erase(tokens.begin() + (i - 1));

      i -= 2;

    } else if (tokens.at(i) == "+") {
      tokens.at(i - 2) = to_string(stoi(tokens.at(i - 2)) + stoi(tokens.at(i - 1)));

      tokens.erase(tokens.begin() + (i));
      tokens.erase(tokens.begin() + (i - 1));

      i -= 2;

    } else if (tokens.at(i) == "-") {
      tokens.at(i - 2) = to_string(stoi(tokens.at(i - 2)) - stoi(tokens.at(i - 1)));

      tokens.erase(tokens.begin() + (i));
      tokens.erase(tokens.begin() + (i - 1));

      i -= 2;

    } else if (tokens.at(i) == "*") {
      tokens.at(i - 2) = to_string(stoi(tokens.at(i - 2)) * stoi(tokens.at(i - 1)));

      tokens.erase(tokens.begin() + (i));
      tokens.erase(tokens.begin() + (i - 1));

      i -= 2;

    } else {
      i++;
    }
  }

  cout << stoi(tokens.at(0)) << endl;

  return 0;
}
