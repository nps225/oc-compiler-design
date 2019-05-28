/*
 *  *  oc-compiler main.cpp
 *   *  CMPS 104A Assignment 2: Scanner
 *    *  Author: 
 *     *  Nikhil Punathil <npunathi@ucsc.edu> [SID:1584204]
 *      *  Nikhil Sheth <npsheth@ucsc.edu> [SID:1584204]
 *      Date: 2019.04.29
 */

// Standard C[++] libraries
#include <string>
#include <vector>
#include <assert.h>
#include <errno.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>
// Include our own libraries
#include "string_set.h"
#include "auxlib.h"
#include "lyutils.h"
#include "asg2.h"

using namespace std;

// Global constants
const string CPP = "/usr/bin/cpp -nostdinc";
constexpr size_t LINESIZE = 1024;

// Global variables
string dArg = "";
string outfile = "";
string cpp_command;

/*
 *  Function prototypes
*/

void chomp (char* string, char delim);
void eprint_status (const char* command, int status);
void cpplines (FILE* pipe);
void scan_opts (int argc, char** argv);
void cpp_popen (const char* filename);
void cpp_pclose(FILE* pipe, string cpp_command);
void scanToFile(string outfile);



/* Main() */
int main(int argc, char** argv) {
   exec::execname = basename (argv[0]);
   // Make sure program exits correctly if incorrectly used
   if (argc < 2) {
      errprintf ("Usage: %s [-ly] [filename]\n",
                 exec::execname.c_str());
      exit (exec::exit_status);
   }
   scan_opts (argc, argv);
   if (yydebug == 1 or yy_flex_debug == 1) {
      fprintf (stderr, "Command:");
      for (char** arg = &argv[0]; arg < &argv[argc]; ++arg) {
            fprintf (stderr, " %s", *arg);
      }
      fprintf (stderr, "\n");
   }
   //scans the file + parses it -> generates output
   scanToFile(outfile);
//   outfile += ".str";
//   FILE* out = fopen (outfile.c_str(), "w");
//   string_set::dump (out);
  return exec::exit_status;
}

/*
* Function to analyze the command line arguments and 
* do what's necessary.
* Based on 
* Assignments/expr-smc/main.cpp
*
*/

void scan_opts (int argc, char** argv) {
   opterr = 0;
   yy_flex_debug = 0;
   yydebug = 0;
   lexer::interactive = isatty (fileno (stdin))
                  and isatty (fileno (stdout));

   for(;;) {
      int opt = getopt (argc, argv, "@:lyD:");
      if (opt == EOF) break;
      switch (opt) {
         case '@': set_debugflags (optarg);
         break;
         case 'l': yy_flex_debug = 1;
         break;
         case 'y': yydebug = 1;
         break;
         case 'D': dArg += string(" -D") + optarg;
         break;
         default:  errprintf ("bad option (%c)\n", optopt);
         break;
      }
   }
   if (optind > argc) {
      errprintf ("Usage: %s [-ly] [filename]\n",
                 exec::execname.c_str());
      exit (exec::exit_status);
   }
   const char* filename = optind == argc ? "-" : argv[optind];
   string fn = filename;
   string f(basename(const_cast<char*> (fn.c_str())));
   // extract the filename without .oc using substr()
   outfile = f.substr(0, f.length()-3);
   cpp_popen (filename);
}

/*
* Function to open the pipe and call cpplines().
* Based on Assignments/expr-smc/main.cpp
*
*/

// Open a pipe from the C preprocessor.
// Exit failure if can't.
// Assigns opened pipe to FILE* pipe.
void cpp_popen (const char* filename) {
   cpp_command = CPP + " " + dArg + " " + filename;
   yyin = popen (cpp_command.c_str(), "r");
   if (yyin == nullptr) {
      syserrprintf (cpp_command.c_str());
      exit (exec::exit_status);
   } else {
      if (yy_flex_debug) {
         fprintf (stderr, "-- popen (%s), fileno(yyin) = %d\n",
                  cpp_command.c_str(), fileno (yyin));
      }
      //cpplines (yyin);
      //int pclose_rc = pclose (yyin);
      //eprint_status (cpp_command.c_str(), pclose_rc);
      //    if (pclose_rc != 0) exec::exit_status = EXIT_FAILURE;
   }
}


/*
 *  Functions kanged from Prof. Mackey's cppstrtok.cpp
 *  Slightly modified to meet the requirements of the assignment.
*/

// Chomp the last character from a buffer if it is delim.
void chomp (char* string, char delim) {
   size_t len = strlen (string);
   if (len == 0) return;
   char* nlpos = string + len - 1;
   if (*nlpos == delim) *nlpos = '\0';
}

// Run cpp against the lines of the file.
void cpplines (FILE* pipe) {
   int linenr = 1;
   for (;;) {
      char buffer[LINESIZE];
      const char* fgets_rc = fgets (buffer, LINESIZE, pipe);
      if (fgets_rc == nullptr) break;
      chomp (buffer, '\n');
      //printf ("%s:line %d: [%s]\n", filename, linenr, buffer);
      // http://gcc.gnu.org/onlinedocs/cpp/Preprocessor-Output.html
      char inputname[LINESIZE];
      int sscanf_rc = sscanf (buffer, "# %d \"%[^\"]\"",
                              &linenr, inputname);
      if (sscanf_rc == 2) {
         continue;
      }
      char* savepos = nullptr;
      char* bufptr = buffer;
      for (int tokenct = 1;; ++tokenct) {
         char* token = strtok_r (bufptr, " \t\n", &savepos);
         bufptr = nullptr;
         if (token == nullptr) break;
         // printf ("token %d.%d: [%s]\n",
         //        linenr, tokenct, token);
         string_set::intern(token);
      }
      ++linenr;
   }
}
