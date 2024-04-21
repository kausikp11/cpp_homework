#include <string>
#include <vector>
#include <iostream>

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
                if(found==0){
                str_original.replace(found,1,"");
                }
                else{
                    str_original.replace(found-1,1,"");
                }
                found++;
            }
            else{
                break;
            }
        }
        if(str_original[0]==char_to_trim_original){
            str_original.replace(0,1,"");
        }
            break;
        case Side::kRight:
        found = str_original.size()-1;
            while(true){
            if(str_original[found]==char_to_trim_original){
                str_original.replace(found,1,"");
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
                if(found==0){
                str_original.replace(found,1,"");
                }
                else{
                    str_original.replace(found-1,1,"");
                }
                found++;
            }
            else{
                break;
            }
            if(str_original[0]==char_to_trim_original){
            str_original.replace(0,1,"");
        }
        }
        found = str_original.size()-1;
            while(true){
            if(str_original[found]==char_to_trim_original){
                str_original.replace(found,1,"");
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
