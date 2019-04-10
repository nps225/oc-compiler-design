#include <string>
#include <vector>
using namespace std;

#include <assert.h>
#include <errno.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "auxlib.h"
#include "string_set.h"

const string cpp_name = "/usr/bin/cpp";
string cpp_command;

// Open a pipe from the C preprocessor.
// Exit failure if can't.
// Assigns opened pipe to FILE* yyin.
void cpp_popen (const char* filename) {
   cpp_command = cpp_name + " " + filename;
   yyin = popen (cpp_command.c_str(), "r");
   if (yyin == nullptr) {
      syserrprintf (cpp_command.c_str());
      exit (exec::exit_status);
   }else {
      if (yy_flex_debug) {
         fprintf (stderr, "-- popen (%s), fileno(yyin) = %d\n",
                  cpp_command.c_str(), fileno (yyin));
      }
      lexer::newfilename (cpp_command);
   }
}

void scan_opts (int argc, char** argv) {
   opterr = 0;
   // yy_flex_debug = 0;
   // yydebug = 0;
   // lexer::interactive = isatty (fileno (stdin))
   //                  and isatty (fileno (stdout));
   for(;;) {
      int opt = getopt (argc, argv, "@:lyD");
      if (opt == EOF) break;
      switch (opt) {
         case '@': set_debugflags (optarg);   break;
         case 'D': printf("hi"); break;   //pass to precompiler
         // case 'l': yy_flex_debug = 1;         break;
         // case 'y': yydebug = 1;               break;
         default:  errprintf ("bad option (%c)\n", optopt); break;
      }
   }
   if (optind > argc) {
      errprintf ("Usage: %s [-ly] [filename]\n",
                 exec::execname.c_str());
      exit (exec::exit_status);
   }
   const char* filename = optind == argc ? "-" : argv[optind];
   //cpp_popen (filename);
}


int main (int argc, char** argv) {
   //handle arguments here
   scan_opts (argc, argv);
   // for (int i = 1; i < argc; ++i) {
   //    const string* str = string_set::intern (argv[i]);
   //    printf ("intern (\"%s\") returned %p->\"%s\"\n",
   //            argv[i], str, str->c_str());
   // }
   // string_set::dump (stdout);
   return EXIT_SUCCESS;
}

