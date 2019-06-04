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
#include <stack> 

string output = "";
int eval_var = 0;
int string_globals = 0;
int f_reg_c = 0;
int if_reg_c = 0;
int while_reg_c = 0;
int set_c = 0;
int set_p = 0;
int set_i = 0;
int compare_expression = 0;
stack<string> s;
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
   //probably where we traverse the block
   if(child->children.size() == 3){
      handle_func_blocks(child->children.at(2));
   }
   output += ".end\n";
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

void handle_func_blocks(astree* node){
    
    //iterate over the entire block
    for(astree* child: node->children){
      string value = *(child->lexinfo); 
      handle_instruction(child);
    }
    //reset values like regiseter number
}

void handle_instruction(astree* node){
     switch(node->symbol){
          //need to handle getting a string/globals
          case TYPE_ID:{
              handle_vars(node);
              break;
          }case TOK_IF:{
              //first child is the expression
              produce_if_output(node,if_reg_c);
              break;
          }case TOK_WHILE:{
              produce_while_output(node,while_reg_c);
              break;
          }case '=':{
              //append to accomidate for arrows etc
              produce_equals_output(node);
              break;
          }
          case CALL:{//call by itself
              //handling manually
              compare_expression = 0;
              string call = "call "+ *(node->children.at(0)->lexinfo) + " ";
            //   printf("%s\n",call.c_str());
              for(uint i = 1; i < node->children.size();i++){
                  produce_expression_output(node->children.at(i));
                  printf("%d\n",compare_expression);
                  if(compare_expression == 1){
                    string expression = "";
                    
                    string regName = "$t" + to_string(f_reg_c) + ":" + add_signals();
                    f_reg_c++;
                    // expression += regName + " ";
                    
                    string value2 = s.top().c_str();
                    s.pop();
                    string value1 = s.top().c_str();
                    s.pop();
                    expression += regName + " = " + value1 + " " + *(node->children.at(i)->lexinfo) 
                    + " " + value2 + "\n";
                    output += expression;
                    // output += regName + "\n";
                    s.push(regName);
                    compare_expression = 0;
                  }
                  
              }
              vector <string> things;
              for(int i = node->children.size()-2; i >= 0;i--){
                things.push_back(s.top());
                s.pop();
                // printf("hi\n");
              }
              for(int i = things.size() - 1;i >= 0;i--){
                call += things[i] + " ";
              }
            //   printf("%d\n",s.size());
              output += call + "\n";
          }
      }
}

void produce_equals_output(astree* node){
     //first child would be TOK_IDENT -- name of var
     //we need to look up its type -- then set the bit accordingly 
     produce_expression_output(node->children.at(1));
    //  string temp = *(node->children.at(1)->lexinfo);
    // printf("%s\n",temp.c_str());
     //now pop the thing off the stack
     string temp = *(node->children.at(0)->lexinfo);
     output += temp + " = " + s.top() + '\n';
     s.pop();
}

void produce_while_output(astree* node,int while_reg_c){
    //we know the top token is a TOK_WHILE
}


void produce_if_output(astree* node,int reg_val){
    if_reg_c++;
    set_i = 1;//we need to fix the setter
    produce_label_if(reg_val);
    //we must automatically look at what child 0 is
    //if is a not then we evaluate the next expression
    string expression = "";
    switch(node->children.at(0)->symbol){
        //checking if it has a not
        case NEG:{
            switch(node->children.at(0)->children.at(0)->symbol){
                case TOK_PARAM:{
                    //3rd into is the sign
                    produce_expression_output(node->children.at(0)->children.at(0)->children.at(0));
                    string regName = "$t" + to_string(f_reg_c) + ":" + add_signals();
                    f_reg_c++;
                    string value2 = s.top().c_str();
                    s.pop();
                    string value1 = s.top().c_str();
                    s.pop();
                    string temp = *(node->children.at(0)->children.at(0)->children.at(0)->lexinfo);
                    output += regName + " = " + value1 + " " + 
                    temp + " " + value2 + "\n";
                    expression += regName;
                    break;
                }
                case TOK_INTCON:
                case TOK_CHARCON:
                case TOK_NULLPTR:
                case TOK_IDENT:{
                    string temp = *(node->children.at(0)->children.at(0)->lexinfo);
                    expression =  temp;
                    break;
                }
            }
            break;
        }
        case TOK_INTCON:
        case TOK_CHARCON:
        case TOK_NULLPTR:
        case TOK_IDENT:{
            // produce_expression_output(node->children.at(0));
            string temp = *(node->children.at(0)->lexinfo);
            expression = "not " + temp;
            break;
        }
        default:{
            produce_expression_output(node->children.at(0));
            string regName = "$t" + to_string(f_reg_c) + ":" + add_signals();
                    f_reg_c++;
                    string value2 = s.top().c_str();
                    s.pop();
                    string value1 = s.top().c_str();
                    s.pop();
                    string temp = *(node->children.at(0)->lexinfo);
                    output += regName + " = " + value1 + " " + 
                    temp + " " + value2 + "\n";
                    expression += "not " + regName;
            break;
        }   


    }
    
   
    //second child will be block
    if(node->children.size() == 3){//there is an else statement
      output += "goto .el" + to_string(reg_val) + " if ";
      output += expression;
      //now run the block again -- two blocks here
      //handle block one
      output += "\n";
      //one block is all we need
      output += ".th" + to_string(reg_val) + ": ";
      //check if block or not
      switch(node->children.at(1)->symbol){
          //need to handle getting a string/globals
          case BLOCK:{
              handle_func_blocks(node->children.at(1));
              break;
          }
          default:{
              handle_instruction(node->children.at(1));
              break;
          }
      }
      output += "goto .fi" + to_string(reg_val) + "\n";
      //now for the else statement
      produce_label_else(reg_val);

      switch(node->children.at(2)->symbol){
          //need to handle getting a string/globals
          case BLOCK:{
              handle_func_blocks(node->children.at(2));
              break;
          }
          default:{
              handle_instruction(node->children.at(2));
              break;
          }
      }
    //   output += "goto .fi" + to_string(reg_val) + "\n";
      output += ".fi" + to_string(reg_val) + ":";

    }else{//no else
      output += "goto .fi" + to_string(reg_val) + " if ";
      output += expression;
      output += "\n";
      //one block is all we need
      output += ".th" + to_string(reg_val) + ": ";
      //check if block or not
      switch(node->children.at(1)->symbol){
          //need to handle getting a string/globals
          case BLOCK:{
              handle_func_blocks(node->children.at(1));
              break;
          }
          default:{
              string look = *(node->children.at(1)->lexinfo);
            //   printf("%s\n",look.c_str());
              handle_instruction(node->children.at(1));
              break;
          }
      }
      output += "goto .fi" + to_string(reg_val) + "\n";
      output += ".fi" + to_string(reg_val) + ":";
    }
    output += "\n";
}

void handle_vars(astree* node){
    // printf("%s\n",parser::get_tname(node->symbol));
    //here I should set my signals for p,i,or c
    set_signals(node->children.at(0));
    eval_var = 1;
    if(node->children.size() == 3){
        produce_expression_output(node->children.at(2));
        //the final value is left on the stack here so pop it off the stack
        if(s.size() == 2){
            output += *(node->children.at(1)->lexinfo);
            output += " = ";
            string top = s.top().c_str();
            s.pop();
            output += top + " ";
            string operand = *(node->children.at(2)->lexinfo);
            output += operand + " ";
            top = s.top().c_str();
            s.pop();
            output += top + "\n";
        }else{
            output += *(node->children.at(1)->lexinfo);
            output += " = ";
            string top = s.top().c_str();
            s.pop();
            output += top + "\n";
        }
        
    }
    reset_signals();
}

void set_signals(astree* node){
    switch(node->symbol){
        case TOK_INT:{
            set_i = 1;
            break;
        }
        case TOK_CHAR:{
            set_i = 1;
            break;
        }
        case TOK_PTR:{
            set_p = 1;
            break;
        }
    }
}


string add_signals(){
    string september = "";
    if(set_c == 1){
       september = "c";
    }else if(set_i == 1){
        september =  "i";
    }else if(set_p == 1){
        september = "p";
    }
    return september;
}

void reset_signals(){
   set_c = 0;
   set_i = 0;
   set_p = 0;
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
          output += ".end\n";
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

void produce_label_if(int local){
     //always look at second child
     output += "if";
     output += to_string(local);
     output += ": ";
}

void produce_label_else(int local){
     //always look at second child
     output += "el";
     output += to_string(local);
     output += ": ";
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
     switch(node->symbol){
         case TOK_LE:
         case TOK_GE:
         case TOK_EQ:
         case TOK_NE:
         case TOK_GT:
         case TOK_LT:{
             if(s.size() == 2){
                compare_expression = 1;
                break;
             }
             break;
         }
         case '/':
         case '%':
         case '-':
         case '*':
         case '+':{
             //  printf("Here\n");
             //there will be two children
             //pop last two elements off stack and push back onto the stack
             //technically just assign a attribute we check for if top of tree
             string val2 = s.top().c_str();
             s.pop();
             string val1 = s.top().c_str();
             s.pop();
             //two values here
             string regName = "$t" + to_string(f_reg_c) + ":" + add_signals();
            //  printf("%s = %s %s %s\n",regName.c_str(),val1.c_str(),node->lexinfo->c_str(),val2.c_str());
             output = output + regName + " = " + val1.c_str() + " "  + node->lexinfo->c_str() + " " + val2.c_str() + "\n";
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
         //  printf("%s = %s %s \n",regName.c_str(),node->lexinfo->c_str(),val1.c_str());
             output = output + regName.c_str() + " = " + node->lexinfo->c_str() + " " + val1.c_str() + "\n";
             s.push(regName);
             f_reg_c++;

             break;
         }
         case TOK_IDENT:
         case TOK_INTCON:{
             //push int onto stack
             string value = *(node->lexinfo);
            //  printf("%s\n",value.c_str());
             s.push(value);
             break;
         }
         case TOK_CHARCON:{
             //push onto stack
             string value = *(node->lexinfo);
             s.push(value);
             break;
         }
         case TOK_NULLPTR:{
             s.push("nullptr");
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
         case TOK_PARAM:{
             break;
         }
         case CALL:{
            // printf("%d\n",node->children.size());
            // s.pop();
            // s.pop();
            // s.pop();
            //first pop all the preexisting children on the tree
            // for(int i = 0; i < node->children.size();i++){
            //     s.pop();
            // }
            vector <string> things;
            for(int i = node->children.size()-2; i >= 0;i--){
                things.push_back(s.top());
                s.pop();
            }
            //now create the string for call
            //first child should be the
            string regName = "$t" + to_string(f_reg_c) + ":" + add_signals();
            f_reg_c++;
            string call = "call ";
            call += *(node->children.at(0)->lexinfo);
            // string paramsOnStack = "";
            output += regName + " = " + call + " "; 
            for(int i = things.size() - 1;i >= 0;i--){
                output += things[i] + " ";
            }
            output += '\n';
            //printf("%s\n",s.top().c_str());
            s.pop();
            s.push(regName);
            //  printf("hi");
             break;
         }
     }
     
     
    //if two children -> binop
    //if 1 child -> must be unop
    //if 0 child -> either operand or selection -> must start with specific [ or ->
}
