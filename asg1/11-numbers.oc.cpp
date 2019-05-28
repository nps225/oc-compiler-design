# 1 "11-numbers.oc"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "11-numbers.oc"


# 1 "oclib.h" 1
# 15 "oclib.h"
void assert_fail (string expr, string file, int line);

void putchr (int c);
void putint (int i);
void putstr (string s);

int getchr();
string getstr();
string getln();

void exit (int status);
# 4 "11-numbers.oc" 2

int main() {
   int number = 1;
   int done = 0;
   while (not done) {
      putint (number);
      putchr ('\n');
      if (number <= 0) done = 1;
      number = number + number;
   }
   return 0;
}
