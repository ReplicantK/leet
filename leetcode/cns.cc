#include <string>
#include <iostream>

std::string CountAndSay(int n) {
  std::string num = "1";
  std::string new_string = num;

  for (int i = 1; i < n; i++) {
    new_string = "";

    std::string::iterator it_next = num.begin();
    std::string::iterator it_back = num.begin();

    int current_counter = 0;

    while (it_next != num.end()) {
      if (*it_next == *it_back) {
        current_counter++;
        it_next++;
      } else {
        new_string += std::to_string(current_counter);
        new_string += *it_back;

        it_back = it_next;
        current_counter = 0;
      }
    }

    new_string += std::to_string(current_counter);
    new_string += *it_back;

    num = new_string;
  }

  return new_string;
}

int main() {
  std::cout << "CASE 1 - Expected: 1        Got: " << CountAndSay(1) << "\n";
  std::cout << "CASE 1 - Expected: 11       Got: " << CountAndSay(2) << "\n";
  std::cout << "CASE 1 - Expected: 21       Got: " << CountAndSay(3) << "\n";
  std::cout << "CASE 1 - Expected: 1211     Got: " << CountAndSay(4) << "\n";
  std::cout << "CASE 1 - Expected: 111221   Got: " << CountAndSay(5) << "\n";
  std::cout << "CASE 1 - Expected: 312211   Got: " << CountAndSay(6) << "\n";
  std::cout << "CASE 1 - Expected: 13112221 Got: " << CountAndSay(7) << std::endl;

  return 0;
}
