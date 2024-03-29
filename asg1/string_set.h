// $Id: string_set.h,v 1.1 2019-04-15 14:56:06-07 - - $

#ifndef __STRING_SET__
#define __STRING_SET__

#include <string>
#include <unordered_set>

#include <stdio.h>

struct string_set {
   string_set();
   static std::unordered_set<std::string> set;
   static const std::string* intern (const char*);
   static void dump (FILE*);
};

#endif

