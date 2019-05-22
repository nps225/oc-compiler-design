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


void post_order(astree* tree){

    for (astree* child: tree->children) {
      post_order(child);
    }

    fprintf(stdout, "  %1zd    %2zd.%.3zd    %3d    %-13s   %s\n", 
               tree->lloc.filenr, tree->lloc.linenr, tree->lloc.offset,
               tree->symbol,parser::get_tname (tree->symbol), 
                  tree->lexinfo->c_str());
}
