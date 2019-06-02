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
    produce_struct_output(node);
    handle_global_variables(node);
    for(astree* child: node->children){
    //    string condition = parser::get_tname (child->symbol);
       switch(child->symbol){
           case FUNCTION:{
               produce_function_output(child);
               break;
           }
           default:
               continue;
           break;
       }

    }
    printf("%s\n",output.c_str());
}

void produce_function_output(astree* child){
   // output = "";
   string name = string(*(child->children.at(0)->children.at(1)->lexinfo));
   output += name;
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
   output += SymbolTable::getGlobalTable()->dumpLVHelper(name);
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


void produce_struct_output(astree* node){
    //print he head
    // output += "";
    for(astree* child: node->children){
       switch(child->symbol){
          case TOK_STRUCT:
          output += ".struct ";
          // printf("%s\n",*(child->children.at(0)->lexinfo));
          output += *(child->children.at(0)->lexinfo) + '\n';
          //the second child is a block
          produce_struct_block_output(child->children.at(1));
          output += ".end \n";
          break;
          default:
          continue;
          break;
       }
    }
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

void handle_global_variables(astree* node){
    for(astree* child: node->children){
        switch(child->symbol){
           case TYPE_ID:
           produce_type_id_output(child);
           break;
           default:
           continue;
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
            output += ".s" + std::to_string(string_globals) + ": ";
            if(node->children.size() != 2)
               output += string(*(node->children.at(2)->lexinfo));
            output += "\n";
            string_globals++;
            break;
        }
        //globaldefs
        default:{//for the rest of the cases
            produce_label(node);
            output += ".global ";
            produce_type_size_output(node);
            if(node->children.size() != 2){
               switch(node->children.at(2)->symbol){
                  case TOK_INTCON:
                  case TOK_CHARCON:
                  output += string(*(node->children.at(2)->lexinfo));
                  output += "\n";
                  break;
                  case TOK_NULLPTR:
                  output += "nullptr\n";

               }
            }
            else {
               output += "\n";
            }
            break;
        }
    }
    //output += "\n";
}

void produce_label(astree* node){
     //always look at second child
     output += *(node->children.at(1)->lexinfo);
     output += ": ";
}

void produce_expression_output(astree* node){
     //do a post order tree op to get to the bottom
     for(astree* child: node->children){
         produce_expression_output(child);
     }
    //  string value = *(node->lexinfo);
    //  printf("%s\n",value.c_str());
     switch(node->symbol){
         case '/':
         case '-':
         case '*':
         case '+':{
             //there will be two children
             //pop last two elements off stack and push back onto the stack
             string val1 = s.top().c_str();
             s.pop();
             string val2 = s.top().c_str();
             s.pop();
             //two values here
             string regName = "$t" + to_string(f_reg_c);
             printf("%s = %s %s %s\n",regName.c_str(),val1.c_str(),node->lexinfo->c_str(),val2.c_str());
             
             f_reg_c++;
            //  printf("%s\n",regName.c_str());
             s.push(regName);
             break;
         }
         case TOK_NOT:
         case POS:
         case NEG:{
             string val1 = s.top().c_str();
             s.pop();
             string regName = "$t" + to_string(f_reg_c);
             printf("%s = %s %s \n",regName.c_str(),node->lexinfo->c_str(),val1.c_str());
             s.push(regName);
             break;
         }
         case TOK_IDENT:
         case TOK_INTCON:{
             //push int onto stack
             string value = *(node->lexinfo);
             s.push(value);
             break;
         }
         case TOK_CHARCON:{
             //push onto stack
             break;
         }
         case TOK_NULLPTR:{
             break;
         }
         case TOK_ALLOC:{
             break;
         }
         case TOK_INDEX:{
             break;
         }
         case TOK_ARROW:{
             break;
         }
     }
     
     
    //if two children -> binop
    //if 1 child -> must be unop
    //if 0 child -> either operand or selection -> must start with specific [ or ->
}
