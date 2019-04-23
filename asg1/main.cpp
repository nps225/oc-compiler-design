//Nikhil Sheth
//npsheth@ucsc.edu
//ID:1577698
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
#include <string.h>
#include <wait.h>

#include "auxlib.h"
#include "string_set.h"

int exit_status = EXIT_SUCCESS;
const string CPP = "/usr/bin/cpp -nostdinc";
string cpp_command;
string file_name = "";
string dOpt = "";

constexpr size_t LINESIZE = 1024;

// Chomp the last character from a buffer if it is delim.
void chomp (char* string, char delim) {
   size_t len = strlen (string);
   if (len == 0) return;
   char* nlpos = string + len - 1;
   if (*nlpos == delim) *nlpos = '\0';
}

// Run cpp against the lines of the file.
void cpplines (FILE* pipe, const char* filename) {
   int linenr = 1;
   char inputname[LINESIZE];
   strcpy (inputname, filename);
   for (;;) {
      char buffer[LINESIZE];
      char* fgets_rc = fgets (buffer, LINESIZE, pipe);
      if (fgets_rc == nullptr) break;
      chomp (buffer, '\n');
      //printf ("%s:line %d: [%s]\n", filename, linenr, buffer);
      // http://gcc.gnu.org/onlinedocs/cpp/Preprocessor-Output.html
      int sscanf_rc = sscanf (buffer, "# %d \"%[^\"]\"",
                              &linenr, inputname);
      if (sscanf_rc == 2) {
         //printf ("DIRECTIVE: line %d file \"%s\"\n", 
         //linenr, inputname);
         continue;
      }
      char* savepos = nullptr;
      char* bufptr = buffer;
      for (int tokenct = 1;; ++tokenct) {
         char* token = strtok_r (bufptr, " \t\n", &savepos);
         bufptr = nullptr;
         if (token == nullptr) break;
         string_set::intern (token);//places token inside string_set
      }
      ++linenr;
   }
   
}


void cpp_popen(const char* filename){
   string command = CPP + dOpt.c_str() + " " + filename;
   file_name += filename;
   //open pipe to the file
   FILE* pipe = popen (command.c_str(), "r");
   //now pass to preprocessor
   if (pipe == nullptr) {
         exit_status = EXIT_FAILURE;
         fprintf (stderr, "%s: %s: %s\n",
                  "oc", command.c_str(), strerror (errno));
   } else {
         cpplines (pipe, filename);
         int pclose_rc = pclose (pipe);
         eprint_status (command.c_str(), pclose_rc);
         if (pclose_rc != 0) exit_status = EXIT_FAILURE;
   }
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
         case '@': set_debugflags (optarg); break;
         case 'D': dOpt = dOpt + string(" -D ") 
                 + optarg; break;   //pass to precompiler
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
      //exit (exec::Exit_);
      exit(1);
   }
   //check if the file exists
   if(FILE *file = fopen(argv[optind],"r")){
      fclose(file);
   }else{
      perror("file does not exist\n");
      exit(1);//if not exit
   }
   cpp_popen(optind == argc ? "-" : argv[optind]);
}


int main (int argc, char** argv) {
   scan_opts ( argc, argv);
   file_name = file_name.substr(0, file_name.length() - 3);
   //printf("%s\n",file_name.c_str());
   file_name += ".str";
   FILE* pipe = fopen (file_name.c_str(), "w");
   string_set::dump (pipe);
   fclose(pipe);
   return exit_status;
}

