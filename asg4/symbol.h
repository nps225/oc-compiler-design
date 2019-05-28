#ifndef _SYMBOL_H__
#define _SYMBOL_H__

#include <bitset>
#include <unordered_map>
#include <string>
#include <vector>
#include "astree.h"
#include "lyutils.h"


// symbol node
struct symbol{
    attr_bitset attributes;
    size_t sequence = 0;
    unordered_map<const string*,symbol*>* fields = nullptr;
    const string* type_id;
    location lloc;
    size_t block_nr = 0;
    vector<symbol*>* parameters = nullptr;
};

// using attr_bitset = bitset<size_t(attr::BITSET_SIZE)>;
using symbol_table = unordered_map<const string*,symbol*>;
using symbol_entry = symbol_table::value_type;

//symbol table definition
class SymbolTable {
    SymbolTable* parent = nullptr;
    static SymbolTable globalTable;
    static size_t blk_nr;
    size_t local_sequence = 0;
    size_t param_sequence = 0;
    size_t current_blk;
    symbol_table table;
    unordered_map<const string*,SymbolTable*> subtables;

  public:
    SymbolTable(SymbolTable* parent_);
    static SymbolTable* getGlobalTable();
    SymbolTable* getParent();
    attr_bitset getAttributes(const string* name);
    symbol* newSymbol(attr_bitset attributes, location lloc, vector<symbol*>* parameters);
    void insertIntoTable(const string* name, symbol* sym);
    void addFields(symbol* dest, symbol_table* fields);
    void addFunc(const string* name, SymbolTable* table_);
    static void dump (FILE* destination, SymbolTable* tbl);
};

void ConstructTable(astree* root);
vector<symbol*>* ParseParameters(astree* func, SymbolTable* tbl);
void ParseBlock(astree* node, SymbolTable* table);
void ParseBlock(astree* node, symbol_table* table);
void traverse_expressions(astree* node);



#endif
