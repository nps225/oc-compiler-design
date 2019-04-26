#include "astree.h"
#include "string_set.h"
#include "lyutils.h"
#include "yyparse.h"

void printLexer(FILE* out){
    
    int val = yylex();
   
    while(val != YYEOF){
        astree::print(out,yylval);
        val = yylex(); 
    
    }


}
