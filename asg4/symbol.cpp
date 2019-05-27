
#include <assert.h>
#include <errno.h>
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

vector<symbol*>* ParseParameters(astree* func);
SymbolTable* ParseBlock(astree* node, SymbolTable* tbl);
symbol_table* ParseStruct(astree* node);


SymbolTable globalTable = new SymbolTable(nullptr);
size_t SymbolTable::blk_nr = 0;

/*
 *  Begin member function definition for SymbolTable
 */

/*
 *  Constructor for SymbolTable
 */
SymbolTable::SymbolTable(SymbolTable* parent_) {
    this->parent = parent_;
    if(parent == nullptr)
        this->current_blk = 0;
    else
        this->current_blk = ++SymbolTable::blk_nr;
}

/*
 *  Member function of the SymbolTable class to add a symbol to the object's
 *  symbol_table member.
 *
 */
symbol* SymbolTable::newSymbol(attr_bitset attributes, location lloc, vector<symbol*>* parameters){
    symbol* new_sym = new symbol;
    new_sym->attributes = attributes;

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
    new_sym->block_nr = this->current_blk;
    new_sym->parameters = parameters;

    // insert the newly created symbol object into the table.

    return new_sym;
}

void SymbolTable::insertIntoTable(const string* name, symbol* sym){
    // pair<string*,symbol*> toIns (name, sym);
    table.insert(make_pair<const string*&,symbol*&>(name, sym));
}

/*
 *  Function to modify the field of an existing symbol in the table
 *  This is useful when we want to create a symbol_table for a structure field
 *  after we have entered the structure itself to the global symbol table, as
 *  the type of an element in a structure could be the structure itself.
 *
 */
void SymbolTable::addFields(symbol* dest, symbol_table* fields){
    dest->fields = fields;
}

void SymbolTable::addFunc(const string* name, SymbolTable* table_){
    if(table_ != nullptr){
        auto it = subtables.find(name);
        if(it != subtables.end()){
            it->second = table_;
            return;
        }

    }
    // pair<string,SymbolTable*> toIns (name, table_);
    subtables.insert(make_pair<const string*&,SymbolTable*&>(name, table_));
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
    for(size_t i = 0; i < root->children.size(); i++){
        if(root->attributes.test(size_t(attr::STRUCT))){
            symbol* structSym = globalTable.newSymbol(root->children.at(i)->attributes, root->children.at(i)->lloc, nullptr);
            globalTable.insertIntoTable(root->children.at(i)->children.at(0)->lexinfo, structSym);
            symbol_table* fields = ParseStruct(root->children.at(i)->children.at(1));
            globalTable.addFields(structSym, fields);
        }
        else if(root->attributes.test(size_t(attr::FUNCTION))){
            SymbolTable* tbl = new SymbolTable(globalTable);
            vector<symbol*>* params = ParseParameters(root->children.at(i));
            globalTable.newSymbol(root->children.at(i)->attributes, root->children.at(i)->lloc, params);
            if(root->children.at(i)->children.size() == 2)
              globalTable.addFunc(root->children.at(i)->children.at(0)->children.at(1)->lexinfo, nullptr);
            else
              globalTable.addFunc(root->children.at(i)->children.at(0)->children.at(1)->lexinfo, ParseBlock(root->children.at(i)->children.at(3), tbl));
        }
        else if (root->attributes.test(size_t(attr::TYPEID))){
            symbol* sym = globalTable.newSymbol(root->children.at(i)->attributes, root->children.at(i)->lloc, nullptr);
            globalTable.insertIntoTable(root->children.at(i)->children.at(1)->lexinfo, sym);

        }
    }
}

vector<symbol*>* ParseParameters(astree* func, SymbolTable* tbl){
    // std::vector<astree*>::iterator it;
    astree* param = func->children.at(1);
    vector<symbol*>* retVal = new vector<symbol*>;
    //for(it = param->children.begin(); it != param->children.end(); it++){
    //    symbol newSym = SymbolTable::newSymbol(*it->children.at(1)->lexinfo, *it->attributes, *it->it->children.at(1)->lloc, nullptr);
    for(size_t i = 0; i < param->children.size(); i++){
        symbol* newSym = tbl->newSymbol(param->children.at(i)->attributes, param->children.at(i)->lloc, nullptr);
        retVal->push_back(newSym);
    }
    return retVal;
}

void ParseBlock(astree* node, SymbolTable* table) {
    for(size_t i = 0; i < node->children.size(); i++){
        switch(node->children.at(i)->symbol){
            case TYPE_ID:

            break;
            case '=':

            break;
            case BLOCK:

            break;
            case CALL:

            break;
            case WHILE:

            break;

            case TOK_IF:

            break;

            case RETURN:

            break;

            case TOK_INDEX:

            break;
            

        }
    }
}
