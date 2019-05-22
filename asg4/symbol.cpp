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
// Include our own libraries
#include "string_set.h"
#include "auxlib.h"
#include "lyutils.h"
#include "asg3.h"
#include "typeChecker.h"


enum class attr {
VOID, INT, NULLPTR_T, STRING, STRUCT, ARRAY, FUNCTION, VARIABLE,
FIELD, TYPEID, PARAM, LOCAL, LVAL, CONST, VREG, VADDR, BITSET_SIZE,
};

using attr_bitset = bitset<size_t(attr::BITSET_SIZE)>;


struct symbol{

};