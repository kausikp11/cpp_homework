#include <iostream>
#include <string>
#include <vector>

#include <no_strings_attached/string_trim.h>

int main() {
    using std::string_literals::operator""s;
    std::string str{};
  std::string string_to_be_trimmed{};
  std::cout << "Example program that trims strings.\nPlease enter a string:\n";

  std::getline(std::cin, str);
  auto output = no_strings_attached::Trim(str);
  auto output_string = "Your trimmed string: '"s + output+"'"s;
  std::cout<<output_string;
}

