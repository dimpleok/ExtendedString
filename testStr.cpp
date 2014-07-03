/*
  Test string operation
  g++ -std=c++11 -o test testStr.cpp enhancedStr.cpp
*/
#include <iostream>
#include <vector>
#include "enhancedStr.hpp"

namespace ES = enhancedStr;

int main()
{
   std::string s{"  aBcD xyz mmm"};
   ES::upper(s);
   std::cout << s << std::endl;
   ES::strip(s);
   std::cout << "[" << s << "]" <<  std::endl;

   // Split string with token
   std::vector<std::string> v;
   ES::split(s, v);
   for(std::string t : v )
      std::cout << t << "ok" << std::endl;

   std::cout << ES::isdigit("2234") << std::endl;
   std::cout << ES::endswith("hello,world", "world") << std::endl;
   std::cout << ES::iequals("hello", "Hello") << std::endl;
   return 0;
}
