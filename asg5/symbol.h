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
    int sequence = -1;
    unordered_map<string,symbol*>* fields = nullptr;
    string type_id;
    location lloc;
    size_t block_nr = 0;
    vector<symbol*>* parameters = nullptr;
};

// using attr_bitset = bitset<size_t(attr::BITSET_SIZE)>;
using symbol_table = unordered_map<string,symbol*>;
using symbol_entry = symbol_table::value_type;

//symbol table definition
class SymbolTable {
    SymbolTable* parent = nullptr;
    static SymbolTable* globalTable;
    static size_t blk_nr;
    size_t local_sequence = 0;
    size_t param_sequence = 0;
    size_t current_blk;
    symbol_table table;
    unordered_map<string,SymbolTable*> subtables;

  public:
    SymbolTable();
    SymbolTable(SymbolTable* parent_);
    static SymbolTable* getGlobalTable();
    SymbolTable* getParent();
    unordered_map<string,SymbolTable*>* getSubtables();
    void setSubtable(string name, SymbolTable* tbl);
    attr_bitset getAttributes(string name);
    symbol* newSymbol(attr_bitset attributes, location lloc, vector<symbol*>* parameters, string tid = "");
    void insertIntoTable(string name, symbol* sym);
    string dumpLVHelper(string name);
    string dumpLocalVariables();
    void addFields(symbol* dest, symbol_table* fields);
    void addFunc(string name, SymbolTable* table_);
    void dump (FILE* destination, int depth);
};

void ConstructTable(astree* root);
vector<symbol*>* ParseParameters(astree* func, SymbolTable* tbl);
void ParseBlock(astree* node, SymbolTable* table);
void ParseBlock(astree* node, symbol_table* table);
void traverse_expressions(astree* node,SymbolTable* table);
void alloc_helper(astree* node);
void HandleStructs(astree* node, SymbolTable* table);
string attrToString(symbol* sym);



#endif
