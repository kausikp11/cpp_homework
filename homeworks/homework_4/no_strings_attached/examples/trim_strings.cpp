#include <iostream>
#include <string>
#include <vector>

#include <no_strings_attached/string_trim.h>

int main() {
    using std::string_literals::operator""s;
  std::string string_to_be_trimmed{};
  std::cout << "Example program that trims strings.\nPlease enter a string:\n";
  std::getline(std::cin, string_to_be_trimmed);
  std::string Trimmed_string = no_strings_attached::Trim(string_to_be_trimmed);
std::cout << "Your trimmed string: ";
std::cout <<"'"<< Trimmed_string <<"'";
std::cout <<std::endl;
}
