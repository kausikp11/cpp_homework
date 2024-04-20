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
  output = no_strings_attached::Trim(str,' ',no_strings_attached::Side::kBoth);
    //std::cerr<<output<<std::endl;
  std::cout<<"Your trimmed string: ";
  std::cout<<"'"<<output<<"'"<<std::endl;
    return 0;
}
