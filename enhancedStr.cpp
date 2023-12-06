#include <algorithm>
#include <iterator>
#include <iostream>
#include <sstream>
#include <vector>

#include "enhancedStr.hpp"

namespace enhancedStr
{
    void swapcase(std::string &s)
    {
        std::transform(std::begin(s),
                       std::end(s),
                       std::begin(s),
                       [](char c){ return c^32; }
                      );
    }

    void lower(std::string &s)
    {
        std::transform(std::begin(s),
                       std::end(s),
                       std::begin(s),
                       ::tolower
                      );
    }

    void upper(std::string &s)
    {
        std::transform(std::begin(s),
                       std::end(s),
                       std::begin(s),
                       ::toupper
                      );
    }

    void lstrip(std::string &s)
    {
        std::string whitespaces (" \t\f\v\n\r");
        size_t pos = s.find_first_not_of(whitespaces);
        if (pos != std::string::npos) {
            s.erase(0, pos);
        } else {
            s.clear();
        }
    }

    void rstrip(std::string &s)
    {
        std::string whitespaces (" \t\f\v\n\r");
        size_t pos = s.find_last_not_of(whitespaces);
        if (pos != std::string::npos ) {
            s.erase(pos + 1);        
        } else {
            s.clear();
        }
    }

    void strip(std::string &s)
    {
       lstrip(s);
       rstrip(s);
    }

    void split(const std::string &s, 
               std::vector<std::string>& v, 
               char delim)
    {
        std::stringstream ss(s);
        std::string item;
        v.clear();
        while (std::getline(ss, item, delim)) {
            v.push_back(item);
        }
    }

    bool islower(const std::string& s)
    {
      return std::all_of(std::begin(s), std::end(s),
                 [] (char c) { return ::islower(c); });
    }
    
    bool isupper(const std::string& s)
    {
      return std::all_of(std::begin(s), std::end(s),
                 [] (char c) { return ::isupper(c); });
    }
    
    bool isalpha(const std::string& s)
    {
      return std::all_of(std::begin(s), std::end(s),
                 [] (char c) { return ::isalpha(c); });
    }
    
    bool isdigit(const std::string& s)
    {
      return std::all_of(std::begin(s), std::end(s),
                 [] (char c) { return ::isdigit(c); });
    }
    
    bool isalnum (const std::string& s)
    {
      return std::all_of(std::begin(s), std::end(s),
                 [] (char c) { return ::isalnum(c); });
    }
    
    bool startswith(const std::string& s, const std::string subs)
    {
       return s.find(subs) == 0;
    }

    bool endswith(const std::string& s, const std::string subs)
    {
       size_t pos = s.rfind(subs);
       return pos != std::string::npos &&
              pos == s.length() - subs.length();
    }    
    
    bool iequals(const std::string& a, const std::string& b)
    {
        size_t sz = a.length();
        if (b.length() != sz)
            return false;
        for (size_t i = 0; i < sz; ++i)
            if (tolower(a[i]) != tolower(b[i]))
                return false;
        return true;
    }

    const std::string emptyString;
}
