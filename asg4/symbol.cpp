
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


size_t SymbolTable::blk_nr = 0;
SymbolTable SymbolTable::globalTable = new SymbolTable(nullptr);
/*
 *  Begin member function definition for SymbolTable
 */

/*
 *  Constructor for SymbolTable
 */
SymbolTable::SymbolTable(SymbolTable* parent_) {
    //if(parent_ != nullptr)
      //parent = parent_;
    if(parent == nullptr){
        current_blk = 0;
    }
    else{
        current_blk = ++SymbolTable::blk_nr;
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
SymbolTable* SymbolTable::getGlobalTable(){
    return &globalTable;
}
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

void SymbolTable::dump (FILE* destination, SymbolTable* tbl){
    if(tbl->getParent() == nullptr){
        printf("test\n");
        for(auto it = tbl->table.begin(); it != tbl->table.end(); it++){
            printf("test\n");
            const string* str = it->first;
            location loc = it->second->lloc;
            size_t blk = it->second->block_nr;
            printf("<%s>  ===== (%zu.%zu.%zu){%zu}\n", str->c_str(),  loc.filenr, loc.linenr, loc.offset, blk);
            if(tbl->subtables.count(str))
               dump(destination, tbl->subtables[str]);
        }
    }
    else {
        for(auto it = tbl->table.begin(); it != tbl->table.end(); it++){
            const string* str = it->first;
            location loc = it->second->lloc;
            size_t blk = it->second->block_nr;
            printf("<%s>  ===== (%zu.%zu.%zu){%zu}\n", str->c_str(),  loc.filenr, loc.linenr, loc.offset, blk);
        }
    }
}

attr_bitset SymbolTable::getAttributes(const string* name){
    if(table.find(name) != table.end()){
        return table[name]->attributes;
    }
    else {
        printf("Unknown symbol encountered\n");
        return nullptr;
    }
}

SymbolTable* SymbolTable::getParent(){
  return this->parent;
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
            symbol* structSym = SymbolTable::getGlobalTable()->newSymbol((*it)->attributes, (*it)->lloc, nullptr);
            SymbolTable::getGlobalTable()->insertIntoTable((*it)->children.at(0)->lexinfo, structSym);
            symbol_table* fields = new symbol_table;
            ParseBlock((*it)->children.at(1), fields);
            SymbolTable::getGlobalTable()->addFields(structSym, fields);
        }
        else if((*it)->symbol == FUNCTION){
            if(SymbolTable::getGlobalTable()->getParent())
              printf("wtaf\n");
            SymbolTable* tbl = new SymbolTable(SymbolTable::getGlobalTable());
            vector<symbol*>* params = ParseParameters(*it, tbl);
            SymbolTable::getGlobalTable()->newSymbol((*it)->attributes, (*it)->lloc, params);
            printf("%s\n", (*it)->children.at(0)->children.at(1)->lexinfo->c_str());
            if((*it)->children.size() == 2)
              SymbolTable::getGlobalTable()->addFunc((*it)->children.at(0)->children.at(1)->lexinfo, nullptr);
            else{
              // ParseBlock((*it)->children.at(3), tbl);
              SymbolTable::getGlobalTable()->addFunc((*it)->children.at(0)->children.at(1)->lexinfo, tbl);
            }
        }
        else if ((*it)->symbol == TYPE_ID){
            symbol* sym = SymbolTable::getGlobalTable()->newSymbol((*it)->attributes, (*it)->lloc, nullptr);
            SymbolTable::getGlobalTable()->insertIntoTable((*it)->children.at(1)->lexinfo, sym);

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
        symbol* newSym = SymbolTable::getGlobalTable()->newSymbol(param->children.at(i)->attributes, param->children.at(i)->lloc, nullptr);
        tbl->insertIntoTable(param->children.at(i)->children.at(1)->lexinfo, newSym);
        printf("%s\n", param->children.at(i)->children.at(1)->lexinfo->c_str());
        retVal->push_back(newSym);
    }
    return retVal;
}

void HandleTypeID(astree* node){
    node->attributes.set(attr::VARIABLE);
    node->attributes.set(attr::LOCAL);
    node->attributes.set(attr::LVAL);
    if(node->children.size() == 2){
        astree* child0 = node->children.at(0);
        astree* child1 = node->children.at(1);
        switch(child0->symbol){
            case TOK_INT:
            node->attributes.set(attr::INT);
            break;
            case TOK_STRING:
            node->attributes.set(attr::STRING);
            case TOK_ARRAY:
            node->attributes.set(attr::ARRAY);
            if(child0->children.at(0) == TOK_INT)
            node->attributes.set(attr::INT);
            else
            node->attributes.set(attr::STRING);
            break;
        }
    }
    else {
        astree* child0 = node->children.at(0);
        astree* child1 = node->children.at(1);
        astree* child2 = node->children.at(2);
        switch(child0->symbol){
          case TOK_INT:
          if(child2->symbol == TOK_INTCON)
            if(child2->lexinfo.find_first_not_of( "0123456789" ) != string::npos)
              printf("error: Invalid assignment to int variable at (%zu.%zu.%zu)\n", child2->lloc.filenr, child2->lloc.linenr, child2)
          node->attributes.set(attr::INT);
          break;
          case TOK_STRING:
          node->attributes.set(attr::STRING);
          case TOK_ARRAY:
          node->attributes.set(attr::ARRAY);
          if(child0->children.at(0) == TOK_INT)
          node->attributes.set(attr::INT);
          else
          node->attributes.set(attr::STRING);
          break;

        }

    }

}

void ParseBlock(astree* node, SymbolTable* table) {
   symbol* sym;
    for(size_t i = 0; i < node->children.size(); i++){
        astree* test = node->children.at(i);
        switch(test->symbol){
            case TYPE_ID:

            sym = SymbolTable::getGlobalTable()->newSymbol(test->attributes, test->lloc, nullptr);
            table->insertIntoTable(test->children.at(1)->lexinfo, sym);
            // if(test->children.size == 3)
            // perform semantic checks for type on this
            break;
            case BLOCK:
            ParseBlock(test, table);
            break;
            case: TYPE_ID://vars-funcs
            break;
            case: FUNCTION:
            break;
            case: TOK_STRUCT:
            break;
            case: TOK_PARAM:
            break;
            case: BLOCK:
            break;
            case: TOK_NULLPTR:
            break;
            case: TOK_INDEX:
            break;
            case: CALL:
            break;
            case: TOK_GE:
            break;
            case: TOK_LE:
            break;
            case: TOK_EQ:
            break;
            case: TOK_NE:
            break;
            case '+':
            break;
            case '-':
            break;
            case '*':
            break;
            case '/':
            break;
            case '^':
            break;
            case '%':
            break;
            case: TOK_INDEX:
            break;
            case: TOK_IF:
            break;
            case TOK_ELSE:
            break;
            case TOK_ARRAY:
            break;
            case TOK_ALLOC:
            break;
            case TOK_PTR:
            break;
            case TOK_RETURN:
            break;
            case TOK_NOT:
            break;
            case TOK_ARROW:
            break;
            case TOK_VOID:
            break;
            case TOK_INT:
            break;
            case TOK_STRING:
            break;
            case TOK_CHAR:
            break;
            case TOK_CHARCON:
                node->attributes.set(size_t(attr::CONST));
                node->attributes.set(size_t(attr::CHAR));
            break;
            case TOK_STRINGCON:
                node->attributes.set(size_t(attr::CONST));
                node->attributes.set(size_t(attr::STRING));
            break;
            case TOK_INTCON:

            break;
            case TOK_IDENT://look up in symbol table
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
