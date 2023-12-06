#ifndef __ENHANCED_STR_HPP__
#define __ENHANCED_STR_HPP__

#include <string>

namespace enhancedStr
{
    void swapcase(std::string &s);

    void lower(std::string &s);

    void upper(std::string &s);

    void lstrip(std::string &s);

    void rstrip(std::string &s);

    void strip(std::string &s);

    void split(const std::string &s, 
               std::vector<std::string>& v, 
               char delim = ' ');

    bool islower(const std::string& s);
    
    bool isupper(const std::string& s);
    
    bool isalpha(const std::string& s);
    
    bool isdigit(const std::string& s);
    
    bool isalnum (const std::string& s);
    
    bool startswith(const std::string& s, const std::string subs);

    bool endswith(const std::string& s, const std::string subs);  
    
    bool iequals(const std::string& a, const std::string& b);

    extern const std::string emptyString;
}
#endif
