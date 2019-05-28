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
void traverse_typeid(astree* node);
void traverse_expr(astree* node);

void post_order(astree* tree){
     for(size_t i = 0; i < tree->children.size();i++){
       switch (tree->children.at(i)->symbol){
          case TYPE_ID://TYPEID
               traverse_typeid(tree->children.at(i));
          break;
          case TOK_STRUCT://TOK_STRUCT
               traverse_struct(tree->children.at(i));
          break;
          case FUNCTION://FUNCTIONS
              traverse_function(tree->children.at(i));
          break;
      }
     }

}

void traverse_struct(astree* node){
  node->attributes.set(size_t(attr::STRUCT));
  traverse_block(node->children.at(1));
}

void traverse_function(astree* node){
  node->attributes.set(size_t(attr::FUNCTION));
  //handle 0
  astree* child = node->children.at(0);
  switch(child->children.at(0)->symbol){
     case TOK_INT:
     break;
     case TOK_STRING:
     break;
     case TOK_PTR:
     break;
  }
}



void traverse_typeid(astree* node){
  //if it is size == 3 or 2
  if(node->children.size() == 3){//size = 3
    switch(node->children.at(0)->symbol){
      case TOK_INDEX://function to handle this

      break;
      case TOK_INT:
           node->attributes.set(size_t(attr::TYPEID));
           node->children.at(0)->attributes.set(size_t(attr::INT));
           node->children.at(1)->attributes.set(size_t(attr::LVAL));
           node->children.at(1)->attributes.set
                                (size_t(attr::VARIABLE));
           traverse_expr(node->children.at(2));
      break;
      case TOK_STRING:
           node->attributes.set(size_t(attr::TYPEID));
           node->children.at(0)->attributes.set(size_t(attr::STRING));
           node->children.at(1)->attributes.set(size_t(attr::LVAL));
           node->children.at(1)->attributes.set
                                (size_t(attr::VARIABLE));
           traverse_expr(node->children.at(2));
      break;
    }
  }else{//size = 2
    switch(node->children.at(0)->symbol){
      case TOK_INT:
           node->attributes.set(size_t(attr::TYPEID));
           node->children.at(0)->attributes.set(size_t(attr::INT));
           node->children.at(1)->attributes.set(size_t(attr::LVAL));
           node->children.at(1)->attributes.set
                                (size_t(attr::VARIABLE));
      break;
      case TOK_STRING:
           node->attributes.set(size_t(attr::TYPEID));
           node->children.at(0)->attributes.set(size_t(attr::STRING));
           node->children.at(1)->attributes.set(size_t(attr::LVAL));
           node->children.at(1)->attributes.set
                                (size_t(attr::VARIABLE));
      break;
    }
  }
}

void traverse_expr(astree* node){//has more conditions to handle
     for(astree* child: node->children){
       traverse_expr(child);
     }
     switch(node->symbol){
      case TOK_INTCON:
           node->attributes.set(size_t(attr::CONST));
           node->attributes.set(size_t(attr::INT));
      break;
      case TOK_STRINGCON:
           node->attributes.set(size_t(attr::CONST));
           node->attributes.set(size_t(attr::STRING));
      break;
      case '+':
           node->attributes.set(size_t(attr::VREG));
          //  printf("%s\n",print_attrib(node).c_str());
      break;
      case '-':
           node->attributes.set(size_t(attr::VREG));
      break;
      case '*':
           node->attributes.set(size_t(attr::VREG));
      break;
      case '/':
           node->attributes.set(size_t(attr::VREG));
      break;
      case '^':
           node->attributes.set(size_t(attr::VREG));
      break;
      case '%':
           node->attributes.set(size_t(attr::VREG));
      break;
      case CALL://helper function to handle this
      break;
      case TOK_INDEX://helper function to handle this
      break;
      case TOK_IDENT:
      //look up in the symbol table
      break;
    }
    // printf("%s\n",parser::get_tname(node->attributes);
}

void traverse_block(astree* node){
  return;
}


// void traverse_struct(astree* node){
//   fprintf(stdout,"%s\n",parser::get_tname(node->symbol));
//   node->attributes.set(size_t(attr:: STRUCT));
//   //you have two children -- the name and the block
//   int i = 0;
//       for(astree* child: node->children){
//         switch (i){
//           case 0://TYPEID
//           fprintf(stdout,"%s\n",parser::get_tname (child->symbol));
//           i++;
//           break;
//           case 1://TOK_PARAM
//           //traverse_block(child);
//           i++;
//           break;
//       }

// }
// }

// //traverses functions and prototypes
// void traverse_function(astree* node){
//     fprintf(stdout,"%s\n",parser::get_tname(node->symbol));
//     // fprintf(stdout,"%d\n",node->children.size());
//     //prototype = 2 children; functions = 3 children
//     if(node->children.size() == 3){
//       int i = 0;
//       for(astree* child: node->children){
//         switch (i){
//           case 0://TYPEID
//           fprintf(stdout,"%s\n",parser::get_tname (child->symbol));
//           i++;
//           break;
//           case 1://TOK_PARAM
//           traverse_params(child);
//           i++;
//           break;
//           case 2://TOK_BLOCK
//           fprintf(stdout,"%s\n",parser::get_tname (child->symbol));
//           i++;
//           break;
//         }
//       }
//     }else{
//       //prototypes
//       int i = 0;
//       for(astree* child: node->children){
//         switch (i){
//           case 0://TYPEID
//           fprintf(stdout,"%s\n",parser::get_tname (child->symbol));
//           i++;
//           break;
//           case 1://TOK_PARAM
//           traverse_params(child);
//           i++;
//           break;
//         }
//       }
//     }
// }

// void traverse_params(astree* node){
//      fprintf(stdout,"%s\n",parser::get_tname (node->symbol));
//      for(astree* child: node->children){
//        fprintf(stdout,"%s\n",parser::get_tname (child->symbol));
//      }
// }
