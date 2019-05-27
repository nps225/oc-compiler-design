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
#include "astree.h"


symbol_table* global;
symbol_table* local;
void traverse_struct(astree* node);
void traverse_function(astree* node);
void traverse_params(astree* node);
void traverse_block(astree* node);

void post_order(astree* tree){
  for (astree* child: tree->children) {
      // fprintf(stdout, "  %1zd    %2zd.%.3zd    %3d    %-13s   %s\n", 
      //          child->lloc.filenr, child->lloc.linenr, child->lloc.offset,
      //          child->symbol,parser::get_tname (child->symbol), 
      //             child->lexinfo->c_str());
      switch(child->symbol){
        case FUNCTION://handles functions
             traverse_function(child);
        break;
        case TOK_STRUCT://handles structs
             traverse_struct(child);
        break;
        case TYPE_ID://handles vars
             fprintf(stdout,"hello\n");
        break;
      }
  }
    
}

void traverse_struct(astree* node){
  fprintf(stdout,"%s\n",parser::get_tname(node->symbol));
  node->attributes.set(size_t(attr:: STRUCT));
  //you have two children -- the name and the block
  int i = 0;
      for(astree* child: node->children){
        switch (i){
          case 0://TYPEID
          fprintf(stdout,"%s\n",parser::get_tname (child->symbol));
          i++;
          break;
          case 1://TOK_PARAM
          //traverse_block(child);
          i++;
          break;
      }

}
}

//traverses functions and prototypes
void traverse_function(astree* node){
    fprintf(stdout,"%s\n",parser::get_tname(node->symbol));
    // fprintf(stdout,"%d\n",node->children.size()); 
    //prototype = 2 children; functions = 3 children
    if(node->children.size() == 3){
      int i = 0;
      for(astree* child: node->children){
        switch (i){
          case 0://TYPEID
          fprintf(stdout,"%s\n",parser::get_tname (child->symbol));
          i++;
          break;
          case 1://TOK_PARAM
          traverse_params(child);
          i++;
          break;
          case 2://TOK_BLOCK
          fprintf(stdout,"%s\n",parser::get_tname (child->symbol));
          i++;
          break;
        }
      }
    }else{
      //prototypes
      int i = 0;
      for(astree* child: node->children){
        switch (i){
          case 0://TYPEID
          fprintf(stdout,"%s\n",parser::get_tname (child->symbol));
          i++;
          break;
          case 1://TOK_PARAM
          traverse_params(child);
          i++;
          break;
        }
      }
    }
}

void traverse_params(astree* node){
     fprintf(stdout,"%s\n",parser::get_tname (node->symbol));
     for(astree* child: node->children){
       fprintf(stdout,"%s\n",parser::get_tname (child->symbol));
     }
}



