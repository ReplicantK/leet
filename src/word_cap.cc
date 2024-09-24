#include <iostream>
#include <string>

using namespace std;

int main() {
  string input;

  cin >> input;

  input.at(0) = toupper(input.at(0));

  cout << input << endl;
  
  return 0;
}
