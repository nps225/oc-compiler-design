// $Id: astree.cpp,v 1.17 2019-03-15 14:32:40-07 - - $
/*
 *  *  oc-compiler astree.cpp
 *   *  CMPS 104A Assignment 3
 *    *  Author:
 *     *  Nikhil Punathil <npunathi@ucsc.edu> [SID:1584204]
 *      *  Nikhil Sheth <npsheth@ucsc.edu> [SID:1584204]
 *      Date: 2019.04.29
 */

#include <assert.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "astree.h"
#include "string_set.h"
#include "lyutils.h"

astree::astree (int symbol_, const location& lloc_, const char* info) {
   symbol = symbol_;
   lloc = lloc_;
   lexinfo = string_set::intern (info);

   // vector defaults to empty -- no children
}

astree::~astree() {
   while (not children.empty()) {
      astree* child = children.back();
      children.pop_back();
      delete child;
   }
   if (yydebug) {
      fprintf (stderr, "Deleting astree (");
      astree::dump (stderr, this);
      fprintf (stderr, ")\n");
   }
}

astree* astree::adopt (astree* child1, astree* child2) {
   if (child1 != nullptr) children.push_back (child1);
   if (child2 != nullptr) children.push_back (child2);
   return this;
}

astree* astree::adopt_sym (astree* child, int symbol_) {
   symbol = symbol_;
   return adopt (child);
}

astree* astree::symChange (astree* tree, int symbol_) {
   tree->symbol = symbol_;
   return tree;
}



void astree::dump_node (FILE* outfile) {
   fprintf (outfile, "%s \"%s\" %zd.%zd.%zd",
            parser::get_tname (symbol),
            lexinfo->c_str(),lloc.filenr,
            lloc.linenr, lloc.offset);
   // fprintf(outfile, "%s %zd.%zd.%zd",lexinfo->
   // c_str(),lloc.filenr, lloc.linenr, lloc.offset);
   for (size_t child = 0; child < children.size(); ++child) {
      // fprintf (outfile, " %p",
      //          static_cast<const void*> (children.at(child)));
   }
}

void astree::dump_tree (FILE* outfile, int depth) {
   fprintf (outfile, "%*s", depth * 3, "");
   dump_node (outfile);
   fprintf (outfile, "\n");
   for (astree* child: children) child->dump_tree (outfile, depth + 1);
   fflush (nullptr);
}

void astree::dump (FILE* outfile, astree* tree) {
   if (tree == nullptr) fprintf (outfile, "nullptr");
                   else tree->dump_node (outfile);
}


/*
*  1st 1 digit
*  2nd 2 digits
*  .
*  3 digits padded 0
*  3 digits 3 digits right aligned
*  string length 13
*
*/

void astree::print (FILE* outfile, astree* tree, int depth) {
   //fprintf (outfile, "; %*s", depth * 3, "");
   // fprintf (outfile, "%s \"%s\" (%zd.%zd.%zd)\n",
   //          parser::get_tname (tree->symbol), tree->lexinfo->c_str(),
   //          tree->lloc.filenr, tree->lloc.linenr, tree->lloc.offset);

   // out = outfile;

   fprintf(outfile, "  %1zd    %2zd.%.3zd    %3d    %-13s   %s\n",
               tree->lloc.filenr, tree->lloc.linenr, tree->lloc.offset,
               tree->symbol,parser::get_tname (tree->symbol),
                  tree->lexinfo->c_str());
   // fprintf(outfile, "   %zd  ", tree->lloc.filenr);
   //  fprintf(outfile, "\n");

   for (astree* child: tree->children) {
      astree::print (outfile, child, depth + 1);
   }
}

// void astree::print (FILE* outfile, astree* tree, int depth) {
//    fprintf (outfile, "; %*s", depth * 3, "");
//    fprintf (outfile, "%s \"%s\" (%zd.%zd.%zd)\n",
//             parser::get_tname (tree->symbol), tree->lexinfo->c_str(),
//             tree->lloc.filenr, tree->lloc.linenr, tree->lloc.offset);
//    for (astree* child: tree->children) {
//       astree::print (outfile, child, depth + 1);
//    }
// }

void destroy (astree* tree1, astree* tree2) {
   if (tree1 != nullptr) delete tree1;
   if (tree2 != nullptr) delete tree2;
}

void errllocprintf (const location& lloc, const char* format,
                    const char* arg) {
   static char buffer[0x1000];
   assert (sizeof buffer > strlen (format) + strlen (arg));
   snprintf (buffer, sizeof buffer, format, arg);
   errprintf ("%s:%zd.%zd: %s",
              lexer::filename (lloc.filenr), lloc.linenr, lloc.offset,
              buffer);
}

string print_attrib(astree* tree){
   string strAttrs = "";
   if(tree->attributes[size_t(attr::VOID)] == 1){
      strAttrs += "void ";
   }
   if(tree->attributes[size_t(attr::INT)] == 1){
      strAttrs += "int ";
   }
   if(tree->attributes[size_t(attr::NULLPTR_T)] == 1){
      strAttrs += "nullptr ";
   }
   if(tree->attributes[size_t(attr::STRING)] == 1){
      strAttrs += "string ";
   }
   if(tree->attributes[size_t(attr::STRUCT)] == 1){
      strAttrs += "struct ";
   }
   if(tree->attributes[size_t(attr::ARRAY)] == 1){
      strAttrs += "array ";
   }
   if(tree->attributes[size_t(attr::FUNCTION)] == 1){
      strAttrs += "function ";
   }
   if(tree->attributes[size_t(attr::VARIABLE)] == 1){
      strAttrs += "variable ";
   }
   if(tree->attributes[size_t(attr::FIELD)] == 1){
      strAttrs += "field ";
   }
   if(tree->attributes[size_t(attr::TYPEID)] == 1){
      strAttrs += "typeid ";
   }
   if(tree->attributes[size_t(attr::PARAM)] == 1){
      strAttrs += "param ";
   }
   if(tree->attributes[size_t(attr::LOCAL)] == 1){
      strAttrs += "local ";
   }
   if(tree->attributes[size_t(attr::LVAL)] == 1){
      strAttrs += "lval ";
   }
   if(tree->attributes[size_t(attr::CONST)] == 1){
      strAttrs += "const ";
   }
   if(tree->attributes[size_t(attr::VREG)] == 1){
      strAttrs += "vreg ";
   }
   if(tree->attributes[size_t(attr::VADDR)] == 1){
      strAttrs += "vaddr ";
   }
   if(tree->attributes[size_t(attr::BITSET_SIZE)] == 1){
      strAttrs += "bitset_size ";
   }
   return strAttrs;
}

//  VOID, INT, NULLPTR_T, STRING, STRUCT, ARRAY, FUNCTION, VARIABLE,
//     FIELD, TYPEID, PARAM, LOCAL, LVAL, CONST, VREG, VADDR, BITSET_SIZE
