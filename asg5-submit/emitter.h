//this function will produce our output
void produce_function_output(astree* node);
void produce_struct_output(astree* child);
void produce_type_id_output(astree* node);
void emit_the_tree(astree* node, FILE* destination);
void produce_struct_block_output(astree* node);
void produce_type_size_output(astree* node);
void produce_label(astree* node);
void produce_expression_output(astree* node);
void produce_operand_output(astree* node);
void handle_global_variables(astree* node);
void handle_func_params(astree* node);
void handle_func_blocks(astree* node);
void handle_vars(astree* node);
void set_signals(astree* node);
string add_signals();
void reset_signals();
void produce_label_if(int local);
void produce_if_output(astree* node,int reg_val);
void handle_instruction(astree* node);
void produce_label_else(int reg_val);
void produce_label_while(int reg_val);
void produce_equals_output(astree* node);
void produce_while_output(astree* node,int while_reg_c);
string print_leading_spaces(int count);