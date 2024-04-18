#ifndef NO_STRINGS_ATTACHED_STRING_TRIM_H
#define NO_STRINGS_ATTACHED_STRING_TRIM_H

#include <string>
#include <vector>


namespace no_strings_attached{
    namespace string_trim{
        enum class Side { kLeft, kRight, kBoth};
        std::string Trim(const std::string& str, char char_to_trim, Side side);
        std::string Trim(const std::string& str);
    }
}

#endif /* NO_STRINGS_ATTACHED_STRING_TRIM_H */