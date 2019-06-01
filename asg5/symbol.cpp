
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
static size_t structSeq = 0;
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
 *  Member function of the SymbolTable class to add a symbol to the
 *  object's symbol_table member.
 *
 */

 unordered_map<string,SymbolTable*>* SymbolTable::getSubtables(){
    return &subtables;
 }


symbol* SymbolTable::newSymbol(attr_bitset attributes, location lloc,
                                  vector<symbol*>* parameters){
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
    if(!(attributes.test(size_t(attr::PARAM))) && !
          attributes.test(size_t(attr::LOCAL))){
        new_sym->sequence = -1;
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
 *  This is useful when we want to create a symbol_table for a structure
 *  field after we have entered the structure itself to the global
 *  symbol table, as the type of an element in a structure could be the
 *  structure itself.
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

void dumpStructTable (symbol_table* t, FILE* destination, int depth){
    for(auto it = t->begin(); it != t->end(); it++){
        string str = it->first;
        location loc = it->second->lloc;
        string att = attrToString(it->second->attributes);
        for(int i = 0; i < depth - 1; i++)
            fprintf(destination, " ");
        fprintf(destination, "%s (%zu.%zu.%zu) %s %d\n", str.c_str(),
                    loc.filenr, loc.linenr, loc.offset, att.c_str(),
                        it->second->sequence);
    }
}

void SymbolTable::dump (FILE* destination, int depth){
        for(auto it = table.begin(); it != table.end(); it++){
            string str = it->first;
            location loc = it->second->lloc;
            size_t blk = it->second->block_nr;
            string att = attrToString(it->second->attributes);
            if(it->second->attributes.test(size_t(attr::STRUCT))){
                for(int i = 0; i < depth - 1; i++)
                    fprintf(destination, " ");
                att.append(it->second->type_id);
                fprintf(destination, "%s (%zu.%zu.%zu) {%zu} %s\n",
                          str.c_str(),  loc.filenr, loc.linenr,
                              loc.offset, blk, att.c_str());
                dumpStructTable(it->second->fields,
                                    destination, depth+4);
                continue;
            }
            for(int i = 0; i < depth - 1; i++)
                fprintf(destination, " ");
            if(it->second->sequence != -1)
                fprintf(destination, "%s (%zu.%zu.%zu) {%zu} %s %d\n",
                      str.c_str(),  loc.filenr, loc.linenr, loc.offset,
                            blk, att.c_str(), it->second->sequence);
            else
                fprintf(destination, "%s (%zu.%zu.%zu) {%zu} %s\n",
                          str.c_str(),  loc.filenr,
                              loc.linenr, loc.offset, blk, att.c_str());
            if(subtables.size())
                if(subtables.at(str))
                    subtables.at(str)->dump(destination, depth + 4);

        }
}

attr_bitset SymbolTable::getAttributes(string name){
    attr_bitset ret(size_t(attr::BITSET_SIZE));
    if(table.find(name) != table.end()){
        return table[name]->attributes;
    }
    else if(getGlobalTable()->
              getAttributes(name).test(size_t(attr::BITSET_SIZE))){
        errprintf("Unknown symbol encountered\n");
        return ret;
    }
    else {
        return getGlobalTable()->getAttributes(name);
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
 * Begin helper function definitions to construct a series of symbol
 * tables
 *
 */


/*
 *  Function to iterate through the AST and construct the necessary
 *  SymbolTables
 */
void ConstructTable(astree* root){
    //for(it = root->children.begin(); it != root.children.end(); it++){
    SymbolTable* global = SymbolTable::getGlobalTable();
    for(auto it = root->children.begin();
          it != root->children.end(); it++){
        if((*it)->symbol == TOK_STRUCT){
            (*it)->attributes.set(size_t(attr::STRUCT));
            (*it)->attributes.set(size_t(attr::TYPEID));
            symbol* structSym = global->newSymbol((*it)->attributes,
                                              (*it)->lloc, nullptr);
            structSym->type_id =
                            string(*((*it)->children.at(0)->lexinfo));
            global->insertIntoTable(
                  string(*((*it)->children.at(0)->lexinfo)), structSym);
            symbol_table* fields = new symbol_table;
            ParseBlock((*it)->children.at(1), fields);
            global->addFields(structSym, fields);
        }
        else if((*it)->symbol == FUNCTION){
            SymbolTable* tbl = new SymbolTable(global);
            (*it)->attributes.set(size_t(attr::FUNCTION));
            switch((*it)->children.at(0)->children.at(0)->symbol){
                case TOK_INT:
                (*it)->attributes.set(size_t(attr::INT));
                break;
                case TOK_STRING:
                (*it)->attributes.set(size_t(attr::STRING));
                break;
                case TOK_VOID:
                (*it)->attributes.set(size_t(attr::VOID));
                break;
            }
            vector<symbol*>* params = ParseParameters(*it, tbl);
            string name (*((*it)->children.at(0)->
                              children.at(1)->lexinfo));
            symbol* func = global->newSymbol((*it)->attributes,
                                              (*it)->lloc, params);
            global->insertIntoTable(name, func);
            // cout << (*it)->children.size() <<"\n";
            if((*it)->children.size() == 2)
              global->addFunc(name, tbl);
            else{
              if(global->getSubtables()->find(name) !=
                  global->getSubtables()->end())
                  global->setSubtable(name, tbl);
              else
                  global->addFunc(name, tbl);
              ParseBlock((*it)->children.at(2), tbl);
            }

        }
        else if ((*it)->symbol == TYPE_ID){
            symbol* sym = global->newSymbol((*it)->attributes,
                                              (*it)->lloc, nullptr);
            global->insertIntoTable(
                      (*it)->children.at(1)->lexinfo->c_str(), sym);

        }
    }
}

vector<symbol*>* ParseParameters(astree* func, SymbolTable* tbl){
    // std::vector<astree*>::iterator it;
    astree* param = func->children.at(1);
    vector<symbol*>* retVal = new vector<symbol*>;
    for(auto it = param->children.begin();
            it != param->children.end(); it++){
        (*it)->attributes.set(size_t(attr::VARIABLE));
        (*it)->attributes.set(size_t(attr::LVAL));
        (*it)->attributes.set(size_t(attr::PARAM));
        switch((*it)->children.at(0)->symbol){
            case TOK_STRING:
            (*it)->attributes.set(size_t(attr::STRING));
            break;
            case TOK_INT:
            (*it)->attributes.set(size_t(attr::INT));
            break;
        }
        symbol* newSym = tbl->newSymbol((*it)->attributes,
                                        (*it)->lloc, nullptr);
        string name (*((*it)->children.at(1)->lexinfo));
        tbl->insertIntoTable(name, newSym);
        retVal->push_back(newSym);
    }
    return retVal;
}

void HandleTypeID(astree* node, SymbolTable* table, int func){
    if(func == 0)
        node->attributes.set(size_t(attr::FIELD));
    else{
        node->attributes.set(size_t(attr::VARIABLE));
        node->attributes.set(size_t(attr::LOCAL));
        node->attributes.set(size_t(attr::LVAL));
    }
    if(node->children.size() == 2){
        astree* child0 = node->children.at(0);
        astree* child1 = node->children.at(1);
        switch(child0->symbol){
            case TOK_INT:
            node->attributes.set(size_t(attr::INT));
            child0->attributes.set(size_t(attr::INT));
            child1->attributes.set(size_t(attr::INT));
            child1->attributes.set(size_t(attr::LVAL));
            child1->attributes.set(size_t(attr::VARIABLE));
            break;
            case TOK_STRING:
            // node->attributes.set(size_t(attr::STRING));
            node->attributes.set(size_t(attr::STRING));
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
    }
    else {
        astree* child0 = node->children.at(0);
        astree* child1 = node->children.at(1);
        astree* child2 = node->children.at(2);
        switch(child0->symbol){
          case TOK_INT:
          node->attributes.set(size_t(attr::INT));
          child0->attributes.set(size_t(attr::INT));
          child1->attributes.set(size_t(attr::INT));
          child1->attributes.set(size_t(attr::LVAL));
          child1->attributes.set(size_t(attr::VARIABLE));
          traverse_expressions(child2,table);
          break;
          case TOK_STRING:
          node->attributes.set(size_t(attr::INT));
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
                errprintf ("error: Invalid assignment to int \
                variable at (%zu.%zu.%zu)\n",
                node->lloc.filenr,node->lloc.linenr,node->lloc.offset);
            }
            node->attributes.set(size_t(attr::INT));
            node->attributes.set(size_t(attr::VREG));
            break;
        }
        case TOK_NOT: {
            astree* child = node->children.at(0);
            if(child->attributes[size_t(attr::INT)] != 1){
                errprintf("error: Invalid assignment to int variable \
                 at (%zu.%zu.%zu)\n",
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
                    errprintf("error: Invalid assignment to int \
                    variable at (%zu.%zu.%zu)\n",
                    node->lloc.filenr, node->lloc.linenr, node);
                }
                node->attributes.set(size_t(attr::INT));
                node->attributes.set(size_t(attr::VREG));
            }else{
                astree* child0 = node->children.at(0);
                if(child0->attributes[size_t(attr::INT)] != 1){
                    errprintf("error: Invalid assignment to int \
                    variable at (%zu.%zu.%zu)\n",
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
                    errprintf("error: Invalid assignment to int \
                     variable at (%zu.%zu.%zu)\n",
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
                attr_bitset at =
                table->getAttributes(string(*(node->lexinfo)));
                //unable to redefine bitset
                node->attributes = at;
            }else{
                //if it is a caller function
            }

            break;
        }
        case TOK_ALLOC:{
            alloc_helper(node);
            break;
        }
        case TOK_ARRAY:{
            node->attributes.set(size_t(attr::ARRAY));
        }




    }
}

void alloc_helper(astree* node){
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
            HandleTypeID(test,table,1);
            sym = table->newSymbol(test->attributes,
                                    test->lloc, nullptr);
            table->insertIntoTable(string(
              *(test->children.at(1)->lexinfo)), sym);
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
    for(auto it = node->children.begin(); it != node->children.end();
                          it++){
        astree* test = *it;
        switch(test->symbol){
            case TYPE_ID:
            HandleTypeID(test,nullptr,0);
            sym = SymbolTable::getGlobalTable()->newSymbol(
                                test->attributes, test->lloc, nullptr);
            sym->sequence = structSeq++;
            table->insert(make_pair(
                      string(*(test->children.at(1)->lexinfo)), sym));
            // if(test->children.size == 3)
            // perform semantic checks for type on this
            break;
            case BLOCK:
            ParseBlock(test, table);
            break;
        }
    }
    structSeq = 0;
}

string attrToString(attr_bitset attr){
   string strAttrs = "";
   if(attr[size_t(attr::VOID)] == 1){
      strAttrs += "void ";
   }
   if(attr[size_t(attr::INT)] == 1){
      strAttrs += "int ";
   }
   if(attr[size_t(attr::NULLPTR_T)] == 1){
      strAttrs += "nullptr ";
   }
   if(attr[size_t(attr::STRING)] == 1){
      strAttrs += "string ";
   }
   if(attr[size_t(attr::STRUCT)] == 1){
      strAttrs += "struct ";
   }
   if(attr[size_t(attr::ARRAY)] == 1){
      strAttrs += "array ";
   }
   if(attr[size_t(attr::FUNCTION)] == 1){
      strAttrs += "function ";
   }
   if(attr[size_t(attr::VARIABLE)] == 1){
      strAttrs += "variable ";
   }
   if(attr[size_t(attr::FIELD)] == 1){
      strAttrs += "field ";
   }
   if(attr[size_t(attr::PARAM)] == 1){
      strAttrs += "param ";
   }
   if(attr[size_t(attr::LOCAL)] == 1){
      strAttrs += "local ";
   }
   if(attr[size_t(attr::LVAL)] == 1){
      strAttrs += "lval ";
   }
   if(attr[size_t(attr::CONST)] == 1){
      strAttrs += "const ";
   }
   if(attr[size_t(attr::VREG)] == 1){
      strAttrs += "vreg ";
   }
   if(attr[size_t(attr::VADDR)] == 1){
      strAttrs += "vaddr ";
   }
   if(attr[size_t(attr::BITSET_SIZE)] == 1){
      strAttrs += "bitset_size ";
   }
   return strAttrs;
}
