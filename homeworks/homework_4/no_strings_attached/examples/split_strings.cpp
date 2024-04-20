#include <iostream>
#include <string>
#include <vector>

#include <no_strings_attached/string_split.h>

int main() {
    using std::string_literals::operator""s;
  std::string str{};
  std::string ouput_string{};
  std::vector<std::string> output;
  std::cout << "Example program that splits strings.\nPlease enter a string:\n";
  std::getline(std::cin, str);
  output = no_strings_attached::Split(str, " ");
  ouput_string = "Your split string:"s;
  auto i = output.size();
  for(i=0; i<=output.size()-1;i++){
    ouput_string+=" "s+"'"s+output[i]+"'"s;
  }
  std::cout<<ouput_string;
}