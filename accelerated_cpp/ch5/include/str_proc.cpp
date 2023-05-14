#include "str_proc.h"
#include <cctype>


std::vector<std::string> split(const std::string& s) {
    std::vector<std::string> ret;
    typedef std::string::size_type string_size;
    string_size i = 0;

    while (i != s.size())
    {
        while (i != s.size() && isspace(s[i]))
        {
            ++i;
        }

        string_size j = i;

        while (j != s.size() && !isspace(s[j]))
        {
            ++j;
        }
        
        if (i != j)
        {
            ret.push_back(s.substr(i, j-i));
        }
        
    }
    return ret;
}