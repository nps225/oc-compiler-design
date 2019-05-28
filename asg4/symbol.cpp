
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

// Include our own libraries
#include "string_set.h"
#include "symbol.h"
#include "auxlib.h"
#include "lyutils.h"
#include "asg3.h"
// #include "typeChecker.h"


size_t SymbolTable::blk_nr = 0;
SymbolTable* SymbolTable::globalTable = new SymbolTable();
/*
 *  Begin member function definition for SymbolTable
 */

 void PrintSTMap(symbol_table t){
    for(auto const &pair: t){
        std::cout << "{" << pair.first << "}\n";
    }
 }

 void PrintSubMap(unordered_map<string,SymbolTable*> t){
    for(auto const &pair: t){
        std::cout << "{" << pair.first << "}\n";
    }
 }

/*
 *  Constructor for SymbolTable
 */
SymbolTable::SymbolTable() {
     //if(parent_ != nullptr)
     current_blk = 0;
}

SymbolTable::SymbolTable(SymbolTable* parent_) {
    //if(parent_ != nullptr)
    parent = parent_;
    current_blk = ++SymbolTable::blk_nr;
}

/*
 *  Member function of the SymbolTable class to add a symbol to the object's
 *  symbol_table member.
 *
 */

 unordered_map<string,SymbolTable*>* SymbolTable::getSubtables(){
    return &subtables;
 }


symbol* SymbolTable::newSymbol(attr_bitset attributes, location lloc, vector<symbol*>* parameters){
    symbol* new_sym = new symbol;
    new_sym->attributes = attributes;
    // cout << current_blk << "----\n";
    // keep track of the sequence
    if(attributes.test(size_t(attr::PARAM))){
        new_sym->sequence = param_sequence++;
    }
    if(attributes.test(size_t(attr::LOCAL))){
        new_sym->sequence = local_sequence++;
    }
    if(!(attributes.test(size_t(attr::PARAM))) && !attributes.test(size_t(attr::LOCAL))){
        new_sym->sequence = 0;
    }

    new_sym->fields = nullptr;
    new_sym->lloc = lloc;
    new_sym->block_nr = current_blk;
    new_sym->parameters = parameters;

    // insert the newly created symbol object into the table.

    return new_sym;
}

void SymbolTable::insertIntoTable(string name, symbol* sym){
    // pair<string*,symbol*> toIns (name, sym);
    table.insert(make_pair(name, sym));
    // PrintSTMap(table);
}

/*
 *  Function to modify the field of an existing symbol in the table
 *  This is useful when we want to create a symbol_table for a structure field
 *  after we have entered the structure itself to the global symbol table, as
 *  the type of an element in a structure could be the structure itself.
 *
 */
SymbolTable* SymbolTable::getGlobalTable(){
    return globalTable;
}
void SymbolTable::addFields(symbol* dest, symbol_table* fields){
    dest->fields = fields;
}

void SymbolTable::addFunc(string name, SymbolTable* table_){
    if(table_ != nullptr){
        auto it = subtables.find(name);
        if(it != subtables.end()){
            it->second = table_;
            return;
        }

    }
    // pair<string,SymbolTable*> toIns (name, table_);
    subtables.insert(make_pair(name, table_));
    // PrintSubMap(subtables);
}

void SymbolTable::dump (FILE* destination, int depth){
        for(auto it = table.begin(); it != table.end(); it++){
            string str = it->first;
            location loc = it->second->lloc;
            size_t blk = it->second->block_nr;
            for(int i = 0; i < depth - 1; i++)
                fprintf(destination, " ");
            fprintf(destination, "%s (%zu.%zu.%zu){%zu}\n", str.c_str(),  loc.filenr, loc.linenr, loc.offset, blk);
            if(subtables.size())
                if(subtables.at(str))
                    subtables.at(str)->dump(destination, depth + 4);

        }
}

attr_bitset SymbolTable::getAttributes(string name){
    if(table.find(name) != table.end()){
        return table[name]->attributes;
    }
    else {
        printf("Unknown symbol encountered\n");
        return NULL;
    }
}

void SymbolTable::setSubtable(string name, SymbolTable* tbl){
    subtables[name] = tbl;
}

SymbolTable* SymbolTable::getParent(){
  return parent;
}
/*
 *
 * Begin helper function definitions to construct a series of symbol tables
 *
 */


// Mackey function to convert attribute to its string equivalent
/*const string AttrToString (attr attribute) {
   static const unordered_map<attr,string> hash {
      {attr::VOID       , "void"       },
      {attr::INT        , "int"        },
      {attr::NULLPTR_T  , "null"       },
      {attr::STRING     , "string"     },
      {attr::STRUCT     , "struct"     },
      {attr::ARRAY      , "array"      },
      {attr::FUNCTION   , "function"   },
      {attr::VARIABLE   , "variable"   },
      {attr::FIELD      , "field"      },
      {attr::TYPEID     , "typeid"     },
      {attr::PARAM      , "param"      },
      {attr::LOCAL      , "local"      },
      {attr::LVAL       , "lval"       },
      {attr::CONST      , "const"      },
      {attr::VREG       , "vreg"       },
      {attr::VADDR      , "vaddr"      },
      {attr::BITSET_SIZE, "bitset_size"},
   };

   auto str = hash.find (attribute);
   if (str == hash.end()) {
      throw invalid_argument (string (__PRETTY_FUNCTION__) + ": "
                              + to_string (unsigned (attribute)));
   }
   return str->second;
}
*/

/*
 *  Function to iterate through the AST and construct the necessary SymbolTables
 */
void ConstructTable(astree* root){
    //for(it = root->children.begin(); it != root.children.end(); it++){
    SymbolTable* global = SymbolTable::getGlobalTable();
    for(auto it = root->children.begin(); it != root->children.end(); it++){
        if((*it)->symbol == TOK_STRUCT){
            symbol* structSym = global->newSymbol((*it)->attributes, (*it)->lloc, nullptr);
            global->insertIntoTable((*it)->children.at(0)->lexinfo->c_str(), structSym);
            symbol_table* fields = new symbol_table;
            ParseBlock((*it)->children.at(1), fields);
            global->addFields(structSym, fields);
        }
        else if((*it)->symbol == FUNCTION){
            SymbolTable* tbl = new SymbolTable(global);
            vector<symbol*>* params = ParseParameters(*it, tbl);
            string name (*((*it)->children.at(0)->children.at(1)->lexinfo));
            symbol* func = global->newSymbol((*it)->attributes, (*it)->lloc, params);
            global->insertIntoTable(name, func);
            // cout << (*it)->children.size() <<"\n";
            if((*it)->children.size() == 2)
              global->addFunc(name, tbl);
            else{
              if(global->getSubtables()->find(name) != global->getSubtables()->end())
                  global->setSubtable(name, tbl);
              else
                  global->addFunc(name, tbl);
              ParseBlock((*it)->children.at(2), tbl);
            }

        }
        else if ((*it)->symbol == TYPE_ID){
            symbol* sym = global->newSymbol((*it)->attributes, (*it)->lloc, nullptr);
            global->insertIntoTable((*it)->children.at(1)->lexinfo->c_str(), sym);

        }
    }
}

vector<symbol*>* ParseParameters(astree* func, SymbolTable* tbl){
    // std::vector<astree*>::iterator it;
    astree* param = func->children.at(1);
    vector<symbol*>* retVal = new vector<symbol*>;
    //for(it = param->children.begin(); it != param->children.end(); it++){
    //    symbol newSym = SymbolTable::newSymbol(*it->children.at(1)->lexinfo, *it->attributes, *it->it->children.at(1)->lloc, nullptr);
    for(auto it = param->children.begin(); it != param->children.end(); it++){
        symbol* newSym = tbl->newSymbol((*it)->attributes, (*it)->lloc, nullptr);
        string name (*((*it)->children.at(1)->lexinfo));
        tbl->insertIntoTable(name, newSym);
        retVal->push_back(newSym);
    }
    return retVal;
}


void HandleStructs(astree* node, SymbolTable* table){
     //printf("Hi\n");
}

void HandleTypeID(astree* node,SymbolTable* table){
    node->attributes.set(size_t(attr::VARIABLE));
    node->attributes.set(size_t(attr::LOCAL));
    node->attributes.set(size_t(attr::LVAL));
    if(node->children.size() == 2){
        astree* child0 = node->children.at(0);
        astree* child1 = node->children.at(1);
        switch(child0->symbol){
            case TOK_INT:
            node->attributes.set(size_t(attr::INT));
            node->attributes.set(size_t(attr::LVAL));
            node->attributes.set(size_t(attr::VARIABLE));
            child0->attributes.set(size_t(attr::INT));
            child1->attributes.set(size_t(attr::INT));
            child1->attributes.set(size_t(attr::LVAL));
            child1->attributes.set(size_t(attr::VARIABLE));
            break;
            case TOK_STRING:
            // node->attributes.set(size_t(attr::STRING));
            node->attributes.set(size_t(attr::STRING));
            node->attributes.set(size_t(attr::LVAL));
            node->attributes.set(size_t(attr::VARIABLE));
            child0->attributes.set(size_t(attr::STRING));
            child1->attributes.set(size_t(attr::STRING));
            child1->attributes.set(size_t(attr::LVAL));
            child1->attributes.set(size_t(attr::VARIABLE));
            break;
            case TOK_ARRAY:
            node->attributes.set(size_t(attr::ARRAY));
            child0->attributes.set(size_t(attr::ARRAY));
            if(child0->children.at(0)->symbol == TOK_INT){
            node->attributes.set(size_t(attr::INT));
            child0->attributes.set(size_t(attr::INT));
            child1->attributes.set(size_t(attr::INT));
            child1->attributes.set(size_t(attr::LVAL));
            child1->attributes.set(size_t(attr::VARIABLE));
            }else{
            node->attributes.set(size_t(attr::STRING));
            child0->attributes.set(size_t(attr::STRING));
            child1->attributes.set(size_t(attr::STRING));
            child1->attributes.set(size_t(attr::LVAL));
            child1->attributes.set(size_t(attr::VARIABLE));
            }
            break;
        }
        // printf("%s  %s\n",parser::get_tname(node->symbol),print_attrib(node).c_str());
    }
    else {
        astree* child0 = node->children.at(0);
        astree* child1 = node->children.at(1);
        astree* child2 = node->children.at(2);
        switch(child0->symbol){
          case TOK_INT:
        //   if(child2->symbol == TOK_INTCON)
        //     if(child2->lexinfo->find_first_not_of( "0123456789" ) != string::npos)
        //       printf("error: Invalid assignment to int variable at (%zu.%zu.%zu)\n", child2->lloc.filenr, child2->lloc.linenr, child2);
          node->attributes.set(size_t(attr::INT));
          node->attributes.set(size_t(attr::LVAL));
          node->attributes.set(size_t(attr::VARIABLE));
          child0->attributes.set(size_t(attr::INT));
          child1->attributes.set(size_t(attr::INT));
          child1->attributes.set(size_t(attr::LVAL));
          child1->attributes.set(size_t(attr::VARIABLE));
          traverse_expressions(child2,table);
          break;
          case TOK_STRING:
          node->attributes.set(size_t(attr::INT));
          node->attributes.set(size_t(attr::LVAL));
          node->attributes.set(size_t(attr::VARIABLE));
          child0->attributes.set(size_t(attr::INT));
          child1->attributes.set(size_t(attr::INT));
          child1->attributes.set(size_t(attr::LVAL));
          child1->attributes.set(size_t(attr::VARIABLE));
          traverse_expressions(child2,table);
          break;
          case TOK_ARRAY:
          node->attributes.set(size_t(attr::ARRAY));
          if(child0->children.at(0)->symbol == TOK_INT){
          node->attributes.set(size_t(attr::INT));
          }else{
          node->attributes.set(size_t(attr::STRING));
          }
          traverse_expressions(child2,table);

          break;

        }
        // printf("%s  %s\n",parser::get_tname(child1->symbol),print_attrib(child1).c_str());
    }


}

void traverse_expressions(astree* node, SymbolTable* table){
    for(astree* child: node->children){
        traverse_expressions(child,table);
    }
    switch(node->symbol){
        case TOK_INTCON:{
            node->attributes.set(size_t(attr::INT));
            node->attributes.set(size_t(attr::CONST));
            break;
        }
        case TOK_CHAR:
        case TOK_INT:{
            node->attributes.set(size_t(attr::INT));
            break;
        }
        case TOK_CHARCON:{
            node->attributes.set(size_t(attr::INT));
            node->attributes.set(size_t(attr::CONST));
            break;
        }
        case TOK_STRING:{
            node->attributes.set(size_t(attr::STRING));
            break;
        }
        case TOK_STRINGCON:{
            node->attributes.set(size_t(attr::STRING));
            node->attributes.set(size_t(attr::CONST));
            break;
        }
        case TOK_NULLPTR:{
            node->attributes.set(size_t(attr::NULLPTR_T));
            node->attributes.set(size_t(attr::CONST));
            break;
        }
        //these two are untested
        case TOK_EQ:
        case TOK_NE:{
            astree* child0 = node->children.at(0);
            astree* child1 = node->children.at(1);
            if((child0->attributes[size_t(attr::INT)] == 0 &&
                child1->attributes[size_t(attr::INT)] == 0)||
                (child0->attributes[size_t(attr::STRING)] == 0 &&
                child1->attributes[size_t(attr::STRING)] == 0)){
                errprintf("error: Invalid assignment to int variable at (%zu.%zu.%zu)\n",
                node->lloc.filenr, node->lloc.linenr, node);
            }
            node->attributes.set(size_t(attr::INT));
            node->attributes.set(size_t(attr::VREG));
            break;
        }
        case TOK_NOT: {
            astree* child = node->children.at(0);
            if(child->attributes[size_t(attr::INT)] != 1){
                errprintf("error: Invalid assignment to int variable at (%zu.%zu.%zu)\n",
                 child->lloc.filenr, child->lloc.linenr, child);
            }
            node->attributes.set(size_t(attr::INT));
            node->attributes.set(size_t(attr::VREG));
            break;
        }
        case '<':
        case '*':
        case '/':
        case '%':
        case '-':
        case '+': {
            if(node->children.size() == 2){
                astree* child0 = node->children.at(0);
                astree* child1 = node->children.at(1);
                if(child0->attributes[size_t(attr::INT)] != 1 ||
                   child1->attributes[size_t(attr::INT)] != 1){
                    errprintf("error: Invalid assignment to int variable at (%zu.%zu.%zu)\n",
                    node->lloc.filenr, node->lloc.linenr, node);
                }
                node->attributes.set(size_t(attr::INT));
                node->attributes.set(size_t(attr::VREG));
            }else{
                astree* child0 = node->children.at(0);
                if(child0->attributes[size_t(attr::INT)] != 1){
                    errprintf("error: Invalid assignment to int variable at (%zu.%zu.%zu)\n",
                    node->lloc.filenr, node->lloc.linenr, node);
                }
                node->attributes.set(size_t(attr::INT));
                node->attributes.set(size_t(attr::VREG));
            }
            break;
        }
        case POS:
        case NEG:{
            astree* child0 = node->children.at(0);
                if(child0->attributes[size_t(attr::INT)] != 1){
                    errprintf("error: Invalid assignment to int variable at (%zu.%zu.%zu)\n",
                    node->lloc.filenr, node->lloc.linenr, node);
                }
                node->attributes.set(size_t(attr::INT));
                node->attributes.set(size_t(attr::VREG));
            break;
        }
        case TOK_IDENT:{//look up in table
            if(node->children.size() == 0){
                //attr_bitset getAttributes(const string* name);
                // printf("%s",node->lexinfo->c_str());
                attr_bitset at = table->getAttributes(string(*(node->lexinfo)));
                //unable to redefine bitset
                node->attributes = at;
            }else{
                //if it is a caller function
            }

            break;
        }
        case TOK_ALLOC:{
            alloc_helper(node,table);
            break;
        }
        case TOK_ARRAY:{
            node->attributes.set(size_t(attr::ARRAY));
        }




    }
    printf("%s  %s\n",parser::get_tname(node->symbol),print_attrib(node).c_str());
}

void alloc_helper(astree* node, SymbolTable* table){
     switch(node->children.at(0)->symbol){
                case TOK_STRING:
                     node->attributes.set(size_t(attr::STRING));
                     node->attributes.set(size_t(attr::VREG));
                break;
                case TOK_ARRAY:
                     node->attributes.set(size_t(attr::ARRAY));
                     node->attributes.set(size_t(attr::VREG));
                     //add bases here
                break;
                case TOK_IDENT:
                    node->attributes.set(size_t(attr::ARRAY));
                    node->attributes.set(size_t(attr::VREG));
                    node->attributes.set(size_t(attr::TYPEID));
                break;
      }
}

void ParseBlock(astree* node, SymbolTable* table) {
   symbol* sym;
    for(size_t i = 0; i < node->children.size(); i++){
        astree* test = node->children.at(i);
        switch(test->symbol){
            case TYPE_ID:
            HandleTypeID(test,table);
            sym = table->newSymbol(test->attributes, test->lloc, nullptr);
            table->insertIntoTable(string(*(test->children.at(1)->lexinfo)), sym);
            // if(test->children.size == 3)
            // perform semantic checks for type on this
            break;
            case BLOCK:
            ParseBlock(test, table);
            break;
        }
    }
}


void ParseBlock(astree* node, symbol_table* table) {
    symbol* sym;
    for(auto it = node->children.begin(); it != node->children.end(); it++){
        astree* test = *it;
        switch(test->symbol){
            case TYPE_ID:
            sym = SymbolTable::getGlobalTable()->newSymbol(test->attributes, test->lloc, nullptr);
            table->insert(make_pair(string(*(test->children.at(1)->lexinfo)), sym));
            // if(test->children.size == 3)
            // perform semantic checks for type on this
            break;
            case BLOCK:
            ParseBlock(test, table);
            break;
        }
    }
}
