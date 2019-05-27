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
#include "asg3.h"
#include "symbol.h"


symbol_table* global;
symbol_table* local;

void post_order(astree* tree){
  for (astree* child: tree->children) {
      fprintf(stdout, "  %1zd    %2zd.%.3zd    %3d    %-13s   %s\n", 
               child->lloc.filenr, child->lloc.linenr, child->lloc.offset,
               child->symbol,parser::get_tname (child->symbol), 
                  child->lexinfo->c_str());
      switch(child->symbol){
        case FUNCTION://handles functions
             fprintf(stdout,"hello\n");
        break;
        case TOK_STRUCT://handles structs
             fprintf(stdout,"hello\n");
        break;
        case TYPE_ID://handles vars
             fprintf(stdout,"hello\n");
        break;
        default:
        post_order(child);
        break;
      }
  }
    
}


