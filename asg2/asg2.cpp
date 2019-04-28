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


void scanToFile(string filename){
   //here we parse the file
   string filenameTOK = filename + ".tok";
   string filenameSTR = filename + ".str";
   FILE* outSTR = fopen (filenameSTR.c_str(), "w");
   FILE* outTOK = fopen (filenameTOK.c_str(), "w");
   int val = yylex();
   while(val != YYEOF){
      astree::print(stdout,yylval);
      //yylval is our token in this case scenario
      string_set::intern(yytext);
      //printf("%d\n", yylval->symbol);//token title
      //printf("%s\n",yylval->lexinfo->c_str());//actual string rep
      val = yylex();
   }
   string_set::dump (outSTR);
   fclose(outSTR);
}