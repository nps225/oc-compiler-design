#include <assert.h>
#include <errno.h>
#include <iostream>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#include <utility>

#include "astree.h"
#include "string_set.h"
#include "lyutils.h"
#include "yyparse.h"
#include "symbol.h"
#include "emitter.h"


string output = "";

void emit_the_tree(astree* node){

    for(astree* child: node->children){
    //    string condition = parser::get_tname (child->symbol);
       switch(child->symbol){
           case FUNCTION:{
            //    produce_function_output(child);
               break;
           }
           case TOK_STRUCT:{
               produce_struct_output(child);
               break;
           }
           case TYPE_ID:{
            //    produce_type_id_output(child);
               break;
           }
       }

    }

    printf("%s\n",output.c_str());
}

void produce_function_output(astree* child){
    // fprintf(stdout,"",);
}

void produce_struct_output(astree* child){
    //print he head
    output += ".struct";
    printf("%s",child->children.at(0)->lexinfo.c_str());
    //we need to parse the body
    // fprintf(stdout,"",);
}

void produce_type_id_output(astree* child){
    // fprintf(stdout,"",);
}