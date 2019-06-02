/*
 *  *  oc-compiler asg3.cpp
 *   *  CMPS 104A Assignment 3
 *    *  Author:
 *     *  Nikhil Punathil <npunathi@ucsc.edu> [SID:1584204]
 *      *  Nikhil Sheth <npsheth@ucsc.edu> [SID:1584204]
 *      Date: 2019.04.29
 */

#include "astree.h"
#include "string_set.h"
#include "lyutils.h"
#include "yyparse.h"
#include "symbol.h"
#include "emitter.h"

FILE* outstream;

void scanToFile(string filename){
  //here we parse the file
   string filenameTOK = filename + ".tok";
   string filenameSTR = filename + ".str";
   string filenameAST = filename + ".ast";
   string filenameSYM = filename + ".sym";
   FILE* outSTR = fopen (filenameSTR.c_str(), "w");
   if (!outSTR)
      fprintf (stderr, "Error creating str file");
   FILE* outTOK = fopen (filenameTOK.c_str(), "w");
   if (!outTOK)
      fprintf (stderr, "Error creating tok file");
   outstream = outTOK;
   FILE* outAST = fopen (filenameAST.c_str(), "w");
   if (!outAST)
      fprintf (stderr, "Error creating tok file");
  //call yyparse to construct our tree
  int val = yyparse();
  if(val == 0){
    //handle symbol table part of code
    string_set::dump (outSTR);
    astree::print(outTOK,parser::root,0);
  }else{
     fprintf (stderr, "issue parsing");
  }
  ConstructTable(parser::root);
  FILE* outSYM = fopen(filenameSYM.c_str(), "w");
  if(!outSYM)
      fprintf(stderr, "Error creating sym file");
  SymbolTable::getGlobalTable()->dump(stdout, 1);
  //  delete parser::root;
   emit_the_tree(parser::root);
   parser::root-> astree::dump_tree(outAST,0);

   destroy(parser::root);
   fclose(outSTR);
   fclose(outTOK);
   fclose(outAST);



}

//old code from asg2
// void scanToFile(string filename){
//    //here we parse the file
//    string filenameTOK = filename + ".tok";
//    string filenameSTR = filename + ".str";
//    FILE* outSTR = fopen (filenameSTR.c_str(), "w");
//    if (!outSTR)
//       fprintf (stderr, "Error creating str file");
//    FILE* outTOK = fopen (filenameTOK.c_str(), "w");
//    if (!outTOK)
//       fprintf (stderr, "Error creating tok file");
//    outstream = outTOK;
//    int val = yylex();
//    while(val != YYEOF){
//       astree::print(outstream,yylval);
//       //yylval is our token in this case scenario

//       string_set::intern(yytext);
//       //printf("%d\n", yylval->symbol);//token title
//       //printf("%s\n",yylval->lexinfo->c_str());//actual string rep
//       val = yylex();
//    }
//    string_set::dump (outSTR);
//    fclose(outSTR);
//    fclose(outTOK);
// }
