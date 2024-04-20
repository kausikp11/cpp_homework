#include <string>
#include <vector>

#include <no_strings_attached/string_trim.h>

namespace no_strings_attached {
//namespace string_trim {
    std::string Trim(const std::string& str, char char_to_trim, Side side){
        std::string str_original = str;
        int found = 0;
        char char_to_trim_original = char_to_trim;
        switch (side)
        {
        case Side::kLeft:
        while(true){
            if(str_original[found]==char_to_trim_original){
                str_original[found] = '\0';
                found++;
            }
            else{
                break;
            }
        }
            break;
        case Side::kRight:
        found = str_original.size()-1;
            while(true){
            if(str_original[found]==char_to_trim_original){
                str_original[found] = '\0';
                found--;
            }
            else{
                break;
            }
        }
        break;
        case Side::kBoth:
            while(true){
            if(str_original[found]==char_to_trim_original){
                str_original[found] = '\0';
                found++;
            }
            else{
                break;
            }
        }
        found = str_original.size()-1;
            while(true){
            if(str_original[found]==char_to_trim_original){
                str_original[found] = '\0';
                found--;
            }
            else{
                break;
            }
        }
            break;
        }
        return str_original;
    }
    std::string Trim(const std::string& str){
        return Trim(str,' ',Side::kBoth);
    }
//} // namespace string_trim
} // namespace no_strings_attached
