#include <iostream>
#include <string>
#include <vector>

#include <no_strings_attached/string_trim.h>

int main() {
    using std::string_literals::operator""s;
  std::string string_to_be_trimmed{};
  std::cout << "Example program that trims strings.\nPlease enter a string:\n";

  std::getline(std::cin, str);
  output = no_strings_attached::Trim(str);
  ouput_string = "Your trimmed string: '"s + output+"'"s;
  std::cout<<ouput_string;
}

