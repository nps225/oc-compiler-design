#include <string>
#include <vector>
#include <assert.h>
#include <errno.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>
#include <bitset>
#include <unordered_map>
// Include our own libraries
#include "string_set.h"
#include "auxlib.h"
#include "lyutils.h"
#include "asg3.h"
// #include "typeChecker.h"

SymbolTable globalTable = new SymbolTable(nullptr);

/*
 *  Begin member function definition for SymbolTable
 */

/*
 *  Constructor for SymbolTable
 */
SymbolTable::SymbolTable(SymbolTable* parent) {
    this->parent = parent;
    if(parent == nullptr)
        this.current_blk = 0;
    else
        this.current_blk = ++SymbolTable::blk_nr;
}

/*
 *  Member function of the SymbolTable class to add a symbol to the object's
 *  symbol_table member.
 *
 */
symbol* SymbolTable::newSymbol(string name, attr_bitset attributes, location lloc, vector<symbol*>* parameters = nullptr){
    symbol new_sym;
    new_sym.attributes = attributes;

    // keep track of the sequence
    switch(node->attribute){
      case attr::PARAM: new_sym.sequence = param_sequence++;
      break;
      case attr::LOCAL: new_sym.sequence = local_sequence++;
      break;
      default:
      new_sym.sequence = 0;
      break;
    }

    new_sym.fields = nullptr;
    new_sym.lloc = lloc;
    new_sym.block_nr = this.current_blk;
    new_sym.parameters = parameters;

    // insert the newly created symbol object into the table.
    table.insert(&name, &new_sym);
    return &new_sym;
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

/*
 *
 * Begin helper function definitions to construct a series of symbol tables
 *
 */


// Mackey function to convert attribute to its string equivalent
const string AttrToString (attr attribute) {
   static const unordered_map<attr,string> hash {
      {attr::VOID       , "void"       },
      {attr::INT        , "int"        },
      {attr::NULLX      , "null"       },
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

/*
 *  Function to iterate through the AST and construct the necessary SymbolTables
 */
void ConstructTable(astree* root){
    std::vector<astree*>::iterator it;
    for(it = root->children.begin(); it != root.children.end(); it++){
        switch(it->attrributes){
            case attr::STRUCT:
            break;
            case attr::FUNCTION:
            break;
            case attr::TYPE_ID:
            break;
        }
    }
}

vector<symbol*>* ParseParameters(astree* func){
    
}

void ParseeBlock(astree* node, SymbolTable* table) {

}
