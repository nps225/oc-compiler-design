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

const string CPP = "/usr/bin/cpp -nostdinc";
string cpp_command;
string dOpt = "";

void cpp_popen(const char* filename){
   string command = CPP + dOpt.c_str() + " " + filename;
   //printf("%s\n",command.c_str());
}


void scan_opts (int argc, char** argv) {
   opterr = 0;
   //atm do not need these
   // yy_flex_debug = 0;
   // yydebug = 0;
   // lexer::interactive = isatty (fileno (stdin))
   //                  and isatty (fileno (stdout));
   for(;;) {
      int opt = getopt (argc, argv, "@:lyD:");
      if (opt == EOF) break;
      switch (opt) {
         case '@': set_debugflags (optarg);   break;
         case 'D': dOpt = dOpt + string(" -D ") + optarg; break;   //pass to precompiler
         // case 'l': yy_flex_debug = 1;         break;
         // case 'y': yydebug = 1;               break;
         case 'l': printf("l");               break;
         case 'y': printf("y");               break;
         default:  errprintf ("bad option (%c)\n", optopt); break;
      }
   }
   if (optind > argc) {
      errprintf ("Usage: %s [-ly] [filename]\n",
                 exec::execname.c_str());
      exit (exec::exit_status);
   }
   cpp_popen(optind == argc ? "-" : argv[optind]);
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

