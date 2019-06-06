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

int NOT = 0;
string output = "";
string line = "";
int eval_var = 0;
int string_globals = 0;
int f_reg_c = 0;
int if_reg_c = 0;
int while_reg_c = 0;
int set_c = 0;
int set_p = 0;
int set_i = 0;
int func_def = 0;
int compare_expression = 0;
stack<string> s;

static unordered_map <string, string> globalStrings;

void emit_the_tree(astree* node, FILE* destination){
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

    fprintf(destination, "%s\n",output.c_str());
    // for(int i = 0; i < output.length();i++){
    //     printf("hi\n");
    // }

}
// fprintf ("%-10s%-10s%");
void produce_function_output(astree* child){
   // output = "";
   string name = string(*(child->children.at(0)->children.at(1)->lexinfo));
   //create label
   produce_label(child->children.at(0));
   //output += name;
   //output += ": ";
   //rest information
   output += ".function ";
   if(child->attributes.test(size_t(attr::INT)))
      output += "int ";
   if(child->attributes.test(size_t(attr::STRING)))
      output += "ptr ";
   if(child->attributes.test(size_t(attr::TYPEID)))
      output += "ptr ";
   if(child->attributes.test(size_t(attr::ARRAY)))
      output += "ptr ";

    output += "\n";
   handle_func_params(child->children.at(1));
   output += SymbolTable::getGlobalTable()->dumpLVHelper(name);
   //probably where we traverse the block
   if(child->children.size() == 3){
      func_def = 1;
      handle_func_blocks(child->children.at(2));
   }
   if((output.at(output.length()-3) != ' ') ||
    (output.at(output.length()-1) == '\n'))
      output += print_leading_spaces(10);
   if(func_def == 1){
      if((output.at(output.length()-3) != ' ') ||
       (output.at(output.length()-1) == '\n'))
         output += print_leading_spaces(10);
      output += "return\n";
      func_def = 0;
   }
     f_reg_c = 0;
     while_reg_c = 0;
     set_c = 0;
     set_p = 0;
     set_i = 0;
     compare_expression = 0;
   if((output.at(output.length()-3) != ' ') ||
    (output.at(output.length()-1) == '\n'))
      output += print_leading_spaces(10);
   output += ".end\n";

}

void handle_func_params(astree* child){
    //always spaced 10 spaces away
   for(astree* it: child->children){
      output += print_leading_spaces(10);
      output += ".param ";
      switch(it->children.at(0)->symbol){
         case TOK_INT:
         output += "int ";
         output += string(*(it->children.at(1)->lexinfo));
         output += "\n";
         break;
         case TOK_ARRAY:
         case TOK_STRING:
         case TOK_PTR:
         output += "ptr ";
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
    // printf("%d\n",s.size());

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
          case TOK_RETURN:{
              if(node->children.size() == 0){
                 if((output.at(output.length()-3) != ' ') ||
                  (output.at(output.length()-1) == '\n'))
                    output += print_leading_spaces(10);
                  output += "return";
              }else if(node->children.size() == 1){
                 if((output.at(output.length()-3) != ' ') ||
                  (output.at(output.length()-1) == '\n'))
                    output += print_leading_spaces(10);
                  output += "return " + *(node->children.at(0)->lexinfo) +"\n";
              }else{
                  //run eval on the child
                  produce_expression_output(node->children.at(0));
                  if((output.at(output.length()-3) != ' ') ||
                  (output.at(output.length()-1) == '\n'))
                     output += print_leading_spaces(10);
                  if(s.size() == 1){
                     if((output.at(output.length()-3) != ' ') ||
                      (output.at(output.length()-1) == '\n'))
                        output += print_leading_spaces(10);
                    output += "return " + s.top() + "\n";
                    s.pop();
                  }else{
                    string val2 = s.top();
                    s.pop();
                    string val1 = s.top();
                    s.pop();
                    if((output.at(output.length()-3) != ' ') ||
                    (output.at(output.length()-1) == '\n'))
                        output += "return " + val1 + " ";
                    output += *(node->children.at(0)->lexinfo) + " ";
                    output += val2 + "\n";
                  }

              }
              break;
          }
          case CALL:{//call by itself
              //handling manually
              compare_expression = 0;
              string call = "call "+ *(node->children.at(0)->lexinfo) + " ";
            //   printf("%s\n",call.c_str());
              for(uint i = 1; i < node->children.size();i++){
                  produce_expression_output(node->children.at(i));
                //   printf("%d\n",compare_expression);
                  if(compare_expression == 1){
                    string expression = "";

                    string regName = "$t" +
                    to_string(f_reg_c) + ":" + add_signals();
                    f_reg_c++;
                    // expression += regName + " ";

                    string value2 = s.top().c_str();
                    s.pop();
                    string value1 = s.top().c_str();
                    s.pop();
                    expression += regName + " = " + value1 + " " +
                    *(node->children.at(i)->lexinfo)
                    + " " + value2 + "\n";
                    if((output.at(output.length()-3) != ' ') ||
                     (output.at(output.length()-1) == '\n'))
                        output += print_leading_spaces(10);
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
              if((output.at(output.length()-3) != ' ') ||
              (output.at(output.length()-1) == '\n'))
                  output += print_leading_spaces(10);
              output += call + "\n";
              break;
          }
          case BLOCK:{
              handle_func_blocks(node);
              break;
          }
      }
      reset_signals();
}

void produce_equals_output(astree* node){
     //first child would be TOK_IDENT -- name of var
     //we need to look up its type -- then set the bit accordingly
     produce_expression_output(node->children.at(1));
    //  string temp = *(node->children.at(1)->lexinfo);
    // printf("%s\n",temp.c_str());
     //now pop the thing off the stack
     switch(node->children.at(0)->symbol){
         case TOK_INDEX:{
             //first child will be index
             string temp = *(node->children.at(0)->children.at(0)->lexinfo);
             produce_expression_output(node->children.at(0)->children.at(1));
             //pop first child off the stack to get returned val
             if((output.at(output.length()-3) != ' ') ||
             (output.at(output.length()-1) == '\n'))
                  output += print_leading_spaces(10);
             output += temp + "[" + s.top() + " * :" + add_signals() + "] = ";
             s.pop();
             output += s.top() + "\n";
             s.pop();
             break;
         }
         case TOK_ARROW:{
             string str = *(node->children.at(0)->children.at(0)->lexinfo);
             string val = *(node->children.at(0)->children.at(1)->lexinfo);
             //handle another look up for the struct name here
             if((output.at(output.length()-3) != ' ') ||
             (output.at(output.length()-1) == '\n'))
                  output+= print_leading_spaces(10);
             string sname = SymbolTable::getGlobalTable()->getStructName(str);
             output += str + "->" + sname + "." + val;

             output += " = " + s.top();
             s.pop();
             output += '\n';
             break;
         }
         default:{
             if((output.at(output.length()-3) != ' ') ||
             (output.at(output.length()-1) == '\n'))
                  output += print_leading_spaces(10);
             string temp = *(node->children.at(0)->lexinfo);
             output += temp + " = " + s.top() + '\n';
             s.pop();
             break;
         }
     }

}

void produce_while_output(astree* node,int reg_val){
    //we know the top token is a TOK_WHILE
    set_i = 1;//we need to fix the setter
    produce_label_while(reg_val);
    //we must automatically look at what child 0 is
    //if is a not then we evaluate the next expression
    string expression = "";
    //first child will be our expressionS
    produce_expression_output(node->children.at(0));
    // printf("%s\n",s.top().c_str());
    expression = "not " + s.top();
    s.pop();

    //now insert the conditional line
    if((output.at(output.length()-3) != ' ') ||
    (output.at(output.length()-1) == '\n'))
         output += print_leading_spaces(10);
    output += "goto .od" + to_string(reg_val) + " if " + expression + "\n";
    output += ".do" + to_string(reg_val) + ": ";
    output += print_leading_spaces(5 - (to_string(reg_val).length()));
    while_reg_c++;
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
    output += print_leading_spaces(10);
    output += "goto .wh" + to_string(reg_val) + "\n";
    output += ".od" + to_string(reg_val) + ": ";
    output += print_leading_spaces(5 - (to_string(reg_val).length()));

    // // output += "goto .fi" + to_string(reg_val) + " if ";
    // //   output += expression;
    //   //one block is all we need
    //   output += ".do" + to_string(reg_val) + ": ";
    //   //check if block or not
    //   switch(node->children.at(1)->symbol){
    //       //need to handle getting a string/globals
    //       case BLOCK:{
    //           handle_func_blocks(node->children.at(1));
    //           break;
    //       }
    //       default:{
    //           string look = *(node->children.at(1)->lexinfo);
    //           printf("%s\n",look.c_str());
    //         //   handle_instruction(node->children.at(1));
    //           break;
    //       }
    //   }
    // //   output += "goto .fi" + to_string(reg_val) + "\n";
    // //   output += ".fi" + to_string(reg_val) + ":";
    // }
    // output += "\n";

}


void produce_if_output(astree* node,int reg_val){
    if_reg_c++;
    // set_i = 1;//we need to fix the setter
    produce_label_if(reg_val);
    //we must automatically look at what child 0 is
    //if is a not then we evaluate the next expression
    string expression = "";
    //first child will be our expressionS
    produce_expression_output(node->children.at(0));
    // printf("%s\n",s.top().c_str());
    expression = "not " + s.top();
    s.pop();

    // second child will be block
    if(node->children.size() == 3){//there is an else statement
      if((output.at(output.length()-3) != ' ') ||
      (output.at(output.length()-1) == '\n'))
         output += print_leading_spaces(10);
      output += "goto .el" + to_string(reg_val) + " if ";
      output += expression;
      //now run the block again -- two blocks here
      //handle block one
      output += "\n";
      //one block is all we need
      output += ".th" + to_string(reg_val) + ": \n";
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
      if((output.at(output.length()-3) != ' ') ||
      (output.at(output.length()-1) == '\n'))
         output += print_leading_spaces(10);
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
      if(output.at(output.length()-1) != '\n')
         output += '\n';
      output += ".fi" + to_string(reg_val) + ":";

    }else{//no else
      if((output.at(output.length()-3) != ' ') ||
      (output.at(output.length()-1) == '\n'))
            output += print_leading_spaces(10);
      output += "goto .fi" + to_string(reg_val) + " if ";
      output += expression;
      output += "\n";
      //one block is all we need
      output += ".th" + to_string(reg_val) + ": ";
      output += print_leading_spaces(5 - to_string(reg_val).length());
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
      if((output.at(output.length()-3) != ' ') ||
      (output.at(output.length()-1) == '\n'))
            output += print_leading_spaces(10);
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
           if((output.at(output.length()-3) != ' ') ||
           (output.at(output.length()-1) == '\n'))
               output += print_leading_spaces(10);
           if(globalStrings.count(string
             (*(node->children.at(1)->lexinfo))) != 0)
               output += globalStrings[string
               (*(node->children.at(1)->lexinfo))];
            else
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
           if((output.at(output.length()-3) != ' ') ||
            (output.at(output.length()-1) == '\n'))
               output += print_leading_spaces(10);
           if(globalStrings.count(string(
             *(node->children.at(1)->lexinfo))) != 0)
               output += globalStrings[string(
                  *(node->children.at(1)->lexinfo))];
           else
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
          output += print_leading_spaces(10);
          output += ".struct ";
          // printf("%s\n",*(child->children.at(0)->lexinfo));
          output += *(child->children.at(0)->lexinfo) + '\n';
          //the second child is a block
          produce_struct_block_output(child->children.at(1));
          output += print_leading_spaces(10);
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
        output += print_leading_spaces(10);
        output += ".field ";
        produce_type_size_output(child);
        output +=*(child->children.at(1)->lexinfo);
        output += '\n';
    }
}

void produce_type_size_output(astree* node){
     switch(node->children.at(0)->symbol){
         case TOK_STRING:
         case TOK_PTR:{
            output +="ptr ";
            break;
         }
         case TOK_CHAR:
         case TOK_INT:{
             output +="int ";
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
            string sx = "s" + std::to_string(string_globals);
            output += "." + sx + ": ";
            output += print_leading_spaces(7-(sx.length()));
            string key = string(*(node->children.at(1)->lexinfo));
            globalStrings[key] = sx;
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

void produce_label_while(int local){
     //always look at second child
     if(output.at(output.length()-1) != '\n')
        output += '\n';
     output += ".wh";
     output += to_string(local);
     int x = to_string(local).length();
     x += 3;
     output += ": ";
     output += print_leading_spaces(8-x);
}

void produce_label_if(int local){
     //always look at second child
     if(output.at(output.length()-1) != '\n')
         output += '\n';
     output += ".if";
     output += to_string(local);
     int x = to_string(local).length();
     x += 3;
     output += ": ";
     output += print_leading_spaces(8-x);
}

void produce_label_else(int local){
     //always look at second child
     if(output.at(output.length()-1) != '\n')
        output += '\n';
     output += ".el";
     output += to_string(local);
     int x = to_string(local).length();
     x += 3;
     output += ": ";
     output += print_leading_spaces(8-x);
}

void produce_label(astree* node){
     //always look at second child
     string y = string(*(node->children.at(1)->lexinfo));
     int x = y.length();
     output += *(node->children.at(1)->lexinfo);
     output += ": ";
     output += print_leading_spaces(8-x);
}

string print_leading_spaces(int count){
    string x = "";
    for(int i = 0; i < count; i++)
       x += " ";
    return x;
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
             //this should be only occuring when there are two elements on
             // the stack
             string val2 = s.top();
             s.pop();
             string val1 = s.top();
             s.pop();
             string regName = "$t" + to_string(f_reg_c) + ":" + add_signals();
             f_reg_c++;
             if((output.at(output.length()-3) != ' ') ||
             (output.at(output.length()-1) == '\n'))
                output += print_leading_spaces(10);
             output += regName + " = " + val1 + " " +
             *(node->lexinfo) + " " + val2 + "\n";
             s.push(regName);
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
            //  printf("%s = %s %s %s\n",regName.c_str(),val1.c_str(),node->
            // lexinfo->c_str(),val2.c_str());
            if((output.at(output.length()-3) != ' ') ||
            (output.at(output.length()-1) == '\n'))
                output += print_leading_spaces(10);
             output += regName + " = " + val1.c_str() + " "  +
             node->lexinfo->c_str() + " " + val2.c_str() + "\n";
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
             string regName = "$t" + to_string(f_reg_c) + ":" + add_signals();
         //  printf("%s = %s %s \n",regName.c_str(),node->lexinfo->c_str(),
         //val1.c_str());
             if((output.at(output.length()-3) != ' ') ||
             (output.at(output.length()-1) == '\n'))
               output += print_leading_spaces(10);
             output = output + regName.c_str() + " = " +
             node->lexinfo->c_str() + " " + val1.c_str() + "\n";
             s.push(regName);
             f_reg_c++;

             break;
         }
         case TOK_IDENT:{
            //still need to look up
            string value;
            if(globalStrings.count(string(*(node->lexinfo))) != 0){
                value = "." + globalStrings[string(*(node->lexinfo))];
                set_p = 1;
            }else{
                value = *(node->lexinfo);
                if(SymbolTable::getGlobalTable()->
                getAttributes(value).test(size_t(attr::TYPEID)))
                  set_p = 1;
                else if(SymbolTable::getGlobalTable()->
                getAttributes(value).test(size_t(attr::STRING)))
                    set_p = 1;
                else if(SymbolTable::getGlobalTable()->
                getAttributes(value).test(size_t(attr::ARRAY)))
                    set_p = 1;
                else if(SymbolTable::getGlobalTable()->
                getAttributes(value).test(size_t(attr::STRUCT)))
                    set_p = 1;
                else
                    set_i = 1;
            }
            //  printf("%s\n",value.c_str());
             s.push(value);
             break;
         }
         case TOK_STRINGCON:
         {
             //push int onto stack
             set_p = 1;
             string value = *(node->lexinfo);
            //  printf("%s\n",value.c_str());
             s.push(value);
             break;
         }
         case TOK_INTCON:{
             //push int onto stack
             set_i = 1;
             string value = *(node->lexinfo);
            //  printf("%s\n",value.c_str());
             s.push(value);
             break;
         }
         case TOK_CHARCON:{
             //push onto stack
             set_i = 1;
             string value = *(node->lexinfo);
             s.push(value);
             break;
         }
         case TOK_ARROW:{
            //  attrib_bitset a = SymbolTable::getGlobalTable()->
            // getAttributes("a");
            //  printf("%s\n",a.c_str());
             vector <string> things;
             //always two children I would assume
             things.push_back(s.top());
             s.pop();
             things.push_back(s.top());
             s.pop();
            //  printf("%s\n",things[1].c_str());
             string regName = "$t" + to_string(f_reg_c) + ":" +add_signals();
             f_reg_c++;
             string express = regName + " = " + things[1] + "->";
             string k = SymbolTable::getGlobalTable()->getStructName(things[1]);
             //insert the name of the look up here
             express += k + "." + things[0] + "\n";
             if((output.at(output.length()-3) != ' ') ||
             (output.at(output.length()-1) == '\n'))
                  output += print_leading_spaces(10);
             output += express;

             s.push(regName);

             break;
         }
         case TOK_NULLPTR:{
             s.push("nullptr");
             break;
         }
         case TOK_ALLOC:{
            //  printf("%d\n",s.size());
            //  printf("%s\n",s.top().c_str());

            string express = "malloc(";
            switch(node->children.at(0)->symbol){
                case TOK_ARRAY:{
                    // if(s.size() == 1){
                    //     s.pop();
                    // }
                    string top = s.top();
                    s.pop();
                    express += top + " * sizeof ";
                    switch(node->children.at(0)->children.at(0)->symbol){
                        case TOK_INT:{
                            express += "int";
                            break;
                        }
                        default:{
                            express += "ptr";
                            break;
                        }
                    }

                    express += ")";


                    break;
                }
                case TOK_STRING:{
                    express += s.top() + ")";
                    s.pop();
                    break;
                }
                case TOK_IDENT:{
                    //must be a struct
                    express += "sizeof struct " + s.top() + ")";
                    s.pop();
                }
            }
            s.push(express);
            break;
         }
         case TOK_INDEX:{
             vector <string> things;
             //now lets create out string
             string regName = "$t" + to_string(f_reg_c)  + ":" + add_signals();
             f_reg_c++;
             string expression = regName + " = ";
             string value = *(node->children.at(0)->lexinfo);

             expression += value + "[" + s.top() + " * :" + add_signals() +"]";
              for(int i = node->children.size() - 1; i >= 0;i--){
                // things.push_back(s.top());
                // printf("%s\n",s.top().c_str());
                s.pop();
             }
             if((output.at(output.length()-3) != ' ') ||
             (output.at(output.length()-1) == '\n'))
                  output += print_leading_spaces(10);
             output += expression + "\n";
             s.push(regName);
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
            if((output.at(output.length()-3) != ' ') ||
            (output.at(output.length()-1) == '\n'))
                output += print_leading_spaces(10);
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
    //if 0 child -> either operand or selection -> must start with specific
    // [ or ->
}
