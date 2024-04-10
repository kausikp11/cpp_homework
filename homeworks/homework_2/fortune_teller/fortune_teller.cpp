#include <array>
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>

int main() {
  using std::cin;
  using std::cout;
  using std::string_literals::operator""s;

  std::map<std::string, std::string> noun_info{};
  noun_info.emplace("spring"s, "STL guru");
  noun_info.emplace("summer"s, "C++ expert");
  noun_info.emplace("autumn"s, "coding beast");
  noun_info.emplace("winter"s, "software design hero");

  const std::array<std::string, 3UL> ending{
      "finds errors quicker than the compiler"s,
      "eats UB for breakfast"s,
      "is not afraid of C++ error messages"s};

  cout << "Welcome to the fortune teller program!\n";
  cout << "Please enter your name:\n";
  std::string name{};
  cin >> name;
  std::string noun{};
  cout << "Please enter the time of year when you were born:\n(pick from "
          "'spring', 'summer', 'autumn', 'winter')\n";
  cin >> noun;
  std::array<std::string, 2UL> adjective{" "s, " "s};
  cout << "Please enter an adjective:\n";
  cin >> adjective[0];
  cout << "Please enter another adjective:\n";
  cin >> adjective[1];
  const int adjective_size = adjective.size();
  const int name_size = name.size();
  const int adjective_index = name_size % adjective_size;
  const int ending_size = ending.size();
  const int ending_index = ending_size % adjective_size;
  // cout<<adjective.size()<<std::endl;
  // cout<<typeid(index1).name()<<std::endl;
  // cout<<name.size()<<std::endl;
  // cout<<typeid(name.size()).name()<<std::endl;
  // cout<<ending.size()<<std::endl;
  // cout<<typeid(ending.size()).name()<<std::endl;
  // cout<<adjective_index<<std::endl;
  // cout<<adjective.size()%ending.size()<<std::endl;

  // cout<<adjective_index<<ending_index<<std::endl;
  cout<<std::endl<<"Here is your description:"<<std::endl;

  cout << name + ", the "s + adjective[adjective_index] + " "s +
              noun_info[noun] + " that " + ending[ending_index]
       << std::endl;

  return 0;
}