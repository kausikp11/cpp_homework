#include <string>
#include <vector>

#include <no_strings_attached/string_trim.h>

namespace no_strings_attached {
//namespace string_trim {
    //A function that allows trimming strings from a given direction:
    std::string Trim(const std::string& str, char char_to_trim, Side side){

        int next_start = 1; // since char type

        int start_index, end_index, count;

        std::string trim_str_init = str;

        if(trim_str_init.find(char_to_trim) != std::string::npos){

            switch(side){

                case Side::kLeft:
                    if((start_index = trim_str_init.find_first_of(char_to_trim)) == 0){

                        end_index = trim_str_init.find_first_not_of(char_to_trim,start_index);
                        count = end_index-start_index;
                        trim_str_init.replace(start_index, count, "");                 
                        return trim_str_init;

                    }else{
                        
                        return str;
                    }
                break;

                case Side::kRight:
                    if((start_index = trim_str_init.find_last_of(char_to_trim)) == trim_str_init.size()-1){

                        end_index = trim_str_init.find_last_not_of(char_to_trim); //find_last_not_of( const basic_string& str,size_type pos = npos )
                        count = start_index - end_index;
                        trim_str_init.replace(end_index+next_start, count, "");                 
                        return trim_str_init;

                    }else{
                        
                        return str;
                    }
                break;

                case Side::kBoth:
                    if((start_index = trim_str_init.find_first_of(char_to_trim)) == 0){

                        end_index = trim_str_init.find_first_not_of(char_to_trim,start_index);
                        count = end_index-start_index;
                        trim_str_init.replace(start_index, count, "");                 
                    }

                    if((start_index = trim_str_init.find_last_of(char_to_trim)) == trim_str_init.size()-1){

                        end_index = trim_str_init.find_last_not_of(char_to_trim); //find_last_not_of( const basic_string& str,size_type pos = npos )
                        count = start_index - end_index;
                        trim_str_init.replace(end_index+next_start, count, "");                 

                    }
                    return trim_str_init;
                break;            
            

            }

        }else{
            return str;
        }



    }





    // An overload of this function function that allows trimming spaces from both sides:
    std::string Trim(const std::string& str){

        int next_start = 1; // since space character

        int start_index, end_index, count;

        std::string trim_str_init = str;

        std::string char_to_trim = " "; // space character

        if(trim_str_init.find(char_to_trim) != std::string::npos){

                    if((start_index = trim_str_init.find_first_of(char_to_trim)) == 0){

                        end_index = trim_str_init.find_first_not_of(char_to_trim,start_index);
                        count = end_index-start_index;
                        trim_str_init.replace(start_index, count, "");                 
                    }

                    if((start_index = trim_str_init.find_last_of(char_to_trim)) == trim_str_init.size()-1){

                        end_index = trim_str_init.find_last_not_of(char_to_trim); //find_last_not_of( const basic_string& str,size_type pos = npos )
                        count = start_index - end_index;
                        trim_str_init.replace(end_index+next_start, count, "");                 

                    }
                    return trim_str_init;

        }else{
            return str;
        }
    }
::kBoth);
    }
//} // namespace string_trim
} // namespace no_strings_attached
