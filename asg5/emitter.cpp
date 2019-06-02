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
             f_reg_c++;

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
