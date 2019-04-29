// $Id: string_set.h,v 1.2 2016-08-18 15:12:57-07 - - $
/*
 *  *  oc-compiler main.cpp
 *   *  CMPS 104A Assignment 1: StringSet generator
 *    *  Author: 
 *     *  Nikhil Punathil <npunathi@ucsc.edu> [SID:1584204]
 *      *  Nikhil Sheth <npsheth@ucsc.edu> [SID:1584204]
 *       *  Date: 2019.04.29
 *        */

#ifndef __STRING_SET__
#define __STRING_SET__

#include <string>
#include <unordered_set>
using namespace std;

#include <stdio.h>

struct string_set {
   string_set();
   static unordered_set<string> set;
   static const string* intern (const char*);
   static void dump (FILE*);
};

#endif

