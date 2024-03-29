// $Id: oclib.h,v 1.11 2018-04-05 17:31:37-07 - - $

#ifndef __OCLIB_H__
#define __OCLIB_H__

#ifdef __OCLIB_C__

void* xcalloc (int nelem, int size);
void putint (int i);
char* getword (void);
char* getln (void);

#else

#define EOF (-1)
#define char int
#define bool int
#define true 1
#define false 0
#define assert(expr) { \
           if (not (expr)) { \
              __assert_fail (#expr, __FILE__, __LINE__, __FUNC__); \
           } \
        }
void __assert_fail (string expr, string file, int line, string func);
void putchar (char c);
void putint (int i);
void putstr (string s);
int getchar();
string getword();
string getln();
void exit (int status);

#endif

#endif

