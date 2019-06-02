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
int string_globals = 0;
void emit_the_tree(astree* node){

    for(astree* child: node->children){
    //    string condition = parser::get_tname (child->symbol);
       switch(child->symbol){
           case FUNCTION:{
               produce_function_output(child);
               break;
           }
           case TOK_STRUCT:{
               produce_struct_output(child);
               break;
           }
           case TYPE_ID:{
               produce_type_id_output(child);
               break;
           }
       }

    }
    printf("%s\n",output.c_str());
}

void produce_function_output(astree* child){
   // output = "";
   output += string(*(child->children.at(0)->children.at(1)->lexinfo));
   output += ": ";
   output += ".function ";
   if(child->attributes.test(size_t(attr::INT)))
      output += "int \n";
   if(child->attributes.test(size_t(attr::STRING)))
      output += "string \n";
   if(child->attributes.test(size_t(attr::TYPEID)))
      output += "ptr \n";
   if(child->attributes.test(size_t(attr::ARRAY)))
      output += "array \n";
   handle_func_params(child->children.at(1));
}

void handle_func_params(astree* child){
   for(astree* it: child->children){
      output += ".param ";
      switch(it->children.at(0)->symbol){
         case TOK_INT:
         output += "int ";
         output += string(*(it->children.at(1)->lexinfo));
         output += "\n";
         break;
         case TOK_STRING:
         output += "string ";
         output += string(*(it->children.at(1)->lexinfo));
         output += "\n";
         break;
         case TOK_PTR:
         output += "ptr ";
         output += string(*(it->children.at(1)->lexinfo));
         output += "\n";
         break;
         case TOK_ARRAY:
         output += "array ";
         output += string(*(it->children.at(1)->lexinfo));
         output += "\n";
         break;
      }
   }
}


void produce_struct_output(astree* child){
    //print he head
    // output += "";
    output += ".struct ";
    // printf("%s\n",*(child->children.at(0)->lexinfo));
    output += *(child->children.at(0)->lexinfo) + '\n';
    //the second child is a block
    produce_struct_block_output(child->children.at(1));
    output += ".end \n";
}

void produce_struct_block_output(astree* node){
    for(astree* child: node->children){
        output += ".field ";
        produce_type_size_output(child);
        output +=*(child->children.at(1)->lexinfo);
        output += '\n';
    }
}

void produce_type_size_output(astree* node){
     switch(node->children.at(0)->symbol){
         case TOK_PTR:{
            output +="ptr ";
            break;
         }
         case TOK_INT:{
             output +="int ";
             break;
         }
         case TOK_CHAR:{
             output +="char ";
             break;
         }
         case TOK_STRING:{
             output +="string ";
             break;
         }

     }
}

void produce_type_id_output(astree* node){
    // fprintf(stdout,"",);
    //there are two types of global variables
    switch(node->children.at(0)->symbol){
        case TOK_STRING:{//will hande stringdef
            //assume always 3 children
            output = output + ".s" + std::to_string(string_globals) + ":";

            string_globals++;
            break;
        }
        //globaldefs
        default:{//for the rest of the cases
            produce_label(node);
            output += ".global ";
            produce_type_size_output(node);
            if(node->children.size() == 2){
                //no expression

            }else{
                //must have expression
            }
            break;
        }
    }
    output += "\n";
}

void produce_label(astree* node){
     //always look at second child
     output += *(node->children.at(1)->lexinfo);
     output += ":";
}
