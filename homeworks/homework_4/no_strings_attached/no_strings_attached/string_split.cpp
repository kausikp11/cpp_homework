#include <string>
#include <vector>

#include <no_strings_attached/string_split.h>

namespace no_strings_attached {
namespace string_split {
std::vector<std::string> Split(const std::string &str,
                               const std::string &delimiter) {
  std::string str_original = str;
  std::string given_delimiter = delimiter;
  std::vector<std::string> splited_string{};
  bool is_done = false;
  while (!is_done) {
    auto split_location = str_original.find(given_delimiter);
    if (split_location < str_original.length()) {
      //auto string_length = given_delimiter.size()
      splited_string.push_back(str_original.substr(0, split_location));
      str_original.erase(0, split_location + 1);
    } else {
      splited_string.push_back(str_original.substr(0, split_location));
      is_done = true;
    }
  }
  return splited_string;
}
std::vector<std::string> Split(const std::string &str,
                               const std::string &delimiter,
                               int number_of_chunks_to_keep){
auto splited_string_vector = Split(str,delimiter);
splited_string_vector.resize(number_of_chunks_to_keep);
return splited_string_vector;
                               }
} // namespace string_split
} // namespace no_strings_attached
