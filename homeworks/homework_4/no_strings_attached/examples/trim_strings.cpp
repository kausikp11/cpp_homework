#include <iostream>
#include <string>
#include <vector>

#include <no_strings_attached/string_trim.h>

int main() {
    using std::string_literals::operator""s;
  std::string str{};
  std::string ouput_string{};
  std::string output;
  std::cout << "Example program that trims strings.\nPlease enter a string:\n";
  std::getline(std::cin, str);
  output = no_strings_attached::string_trim::Trim(str,' ',no_strings_attached::string_trim::Side::kBoth);
  ouput_string = " Your trimmed string: '"s + output+"'"s;
  std::cout<<ouput_string;
}
