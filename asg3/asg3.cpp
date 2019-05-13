/*
 *  *  oc-compiler asg2.cpp
 *   *  CMPS 104A Assignment 2: Scanner
 *    *  Author: 
 *     *  Nikhil Punathil <npunathi@ucsc.edu> [SID:1584204]
 *      *  Nikhil Sheth <npsheth@ucsc.edu> [SID:1584204]
 *      Date: 2019.04.29
 */

#include "astree.h"
#include "string_set.h"
#include "lyutils.h"
#include "yyparse.h"

FILE* outstream;

void scanToFile(string filename){
  //here we parse the file
   string filenameTOK = filename + ".tok";
   string filenameSTR = filename + ".str";
   string filenameAST = filename + ".ast";
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
    parser::root-> astree::dump_tree(outAST,0);
    string_set::dump (outSTR);
    astree::print(outTOK,parser::root,0);
  }
   destroy(parser::root);
   fclose(outSTR);
   fclose(outTOK);
   fclose(outAST);
   


}

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
