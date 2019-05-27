
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
    if(parent == nullptr){
        this->current_blk = 0;
    }
    else{
        this->current_blk = ++SymbolTable::blk_nr;
    }

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

void SymbolTable::dump (FILE* destination){
    if(this->parent == nullptr){
        for(auto it = this->table.begin(); it != this->table.end(); it++){
            const string* str = it->first;
            location loc = it->second->lloc;
            size_t blk = it->second->block_nr;
            fprintf(stdout, "<%s>  ===== (%zu.%zu.%zu){%zu}", str->c_str(),  loc.filenr, loc.linenr, loc.offset, blk);
            if(this->subtables.count(str))
               this->subtables[str]->dump(destination);
        }
    }
    else {
        for(auto it = this->table.begin(); it != this->table.end(); it++){
            const string* str = it->first;
            location loc = it->second->lloc;
            size_t blk = it->second->block_nr;
            fprintf(stdout, "<%s>  ===== (%zu.%zu.%zu){%zu}", str->c_str(),  loc.filenr, loc.linenr, loc.offset, blk);
        }
    }
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
    for(auto it = root->children.begin(); it != root->children.end(); it++){
        if((*it)->symbol == TOK_STRUCT){
            symbol* structSym = globalTable.newSymbol((*it)->attributes, (*it)->lloc, nullptr);
            globalTable.insertIntoTable((*it)->children.at(0)->lexinfo, structSym);
            symbol_table* fields = new symbol_table;
            ParseBlock((*it)->children.at(1), fields);
            globalTable.addFields(structSym, fields);
        }
        else if((*it)->symbol == FUNCTION){
            SymbolTable* tbl = new SymbolTable(globalTable);
            vector<symbol*>* params = ParseParameters(*it, tbl);
            globalTable.newSymbol((*it)->attributes, (*it)->lloc, params);
            printf("%s\n", (*it)->children.at(0)->children.at(1)->lexinfo->c_str());
            if((*it)->children.size() == 2)
              globalTable.addFunc((*it)->children.at(0)->children.at(1)->lexinfo, nullptr);
            else{
              // ParseBlock((*it)->children.at(3), tbl);
              globalTable.addFunc((*it)->children.at(0)->children.at(1)->lexinfo, tbl);
            }
        }
        else if ((*it)->symbol == TYPE_ID){
            symbol* sym = globalTable.newSymbol((*it)->attributes, (*it)->lloc, nullptr);
            globalTable.insertIntoTable((*it)->children.at(1)->lexinfo, sym);

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
        symbol* newSym = globalTable.newSymbol(param->children.at(i)->attributes, param->children.at(i)->lloc, nullptr);
        tbl->insertIntoTable(param->children.at(i)->children.at(1)->lexinfo, newSym);
        printf("%s\n", param->children.at(i)->children.at(1)->lexinfo->c_str());
        retVal->push_back(newSym);
    }
    return retVal;
}

void ParseBlock(astree* node, SymbolTable* table) {
   symbol* sym;
    for(size_t i = 0; i < node->children.size(); i++){
        astree* test = node->children.at(i);
        switch(test->symbol){
            case TYPE_ID:
            sym = globalTable.newSymbol(test->attributes, test->lloc, nullptr);
            table->insertIntoTable(test->children.at(1)->lexinfo, sym);
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
            sym = globalTable.newSymbol(test->attributes, test->lloc, nullptr);
            table->insert(make_pair<const string*&,symbol*&>(test->children.at(1)->lexinfo, sym));
            // if(test->children.size == 3)
            // perform semantic checks for type on this
            break;
            case BLOCK:
            ParseBlock(test, table);
            break;
        }
    }
}
