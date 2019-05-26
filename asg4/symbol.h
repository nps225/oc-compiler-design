#ifndef _SYMBOL_H__
#define _SYMBOL_H__

using attr_bitset = bitset<size_t(attr::BITSET_SIZE)>;
using symbol_table = unordered_map<string*,symbol*>;
using symbol_entry = symbol_table::value_type;

enum class attr unsigned {
    VOID, INT, NULLPTR_T, STRING, STRUCT, ARRAY, FUNCTION, VARIABLE,
    FIELD, TYPEID, PARAM, LOCAL, LVAL, CONST, VREG, VADDR, BITSET_SIZE,
};

// symbol node
struct symbol{
    attr_bitset attributes;
    size_t sequence = 0;
    symbol_table* fields = nullptr;
    location lloc;
    size_t block_nr = 0;
    vector<symbol*>* parameters = nullptr;
};

//symbol table definition
class SymbolTable {
    SymbolTable* parent;
    static size_t blk_nr = 0;
    size_t local_sequence = 0;
    size_t param_sequence = 0;
    size_t current_blk;
    symbol_table table;
    unordered_map<string,symbol_table> structs;
    unordered_map<string,symbol_table> functions;

  public:
    SymbolTable(SymbolTable* parent);
    symbol* newSymbol(astree* node);
    void addFields(symbol* dest, symbol_table* fields);
    void dump (FILE destination);
};


#endif
