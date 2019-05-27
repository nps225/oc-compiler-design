#ifndef _SYMBOL_H__
#define _SYMBOL_H__

#include <bitset>
#include <unordered_map>
#include <string>
#include <vector>
#include "astree.h"


// symbol node
struct symbol{
    attr_bitset attributes;
    size_t sequence = 0;
    unordered_map<const string*,symbol*>* fields = nullptr;
    location lloc;
    size_t block_nr = 0;
    vector<symbol*>* parameters = nullptr;
};

// using attr_bitset = bitset<size_t(attr::BITSET_SIZE)>;
using symbol_table = unordered_map<const string*,symbol*>;
using symbol_entry = symbol_table::value_type;

//symbol table definition
class SymbolTable {
    SymbolTable* parent;
    static size_t blk_nr;
    size_t local_sequence = 0;
    size_t param_sequence = 0;
    size_t current_blk;
    symbol_table table;
    unordered_map<const string*,SymbolTable*> subtables;

  public:
    SymbolTable(SymbolTable* parent_);
    symbol* newSymbol(attr_bitset attributes, location lloc, vector<symbol*>* parameters);
    void insertIntoTable(const string* name, symbol* sym);
    void addFields(symbol* dest, symbol_table* fields);
    void addFunc(const string* name, SymbolTable* table_);
    void dump (FILE destination);
};


#endif
