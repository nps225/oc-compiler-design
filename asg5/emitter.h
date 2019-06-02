//this function will produce our output
void produce_function_output(astree* node);
void handle_func_params(astree* child);
void produce_struct_output(astree* child);
void produce_type_id_output(astree* child);
void emit_the_tree(astree* node);
void produce_struct_block_output(astree* node);
void produce_type_size_output(astree* node);
void produce_label(astree* node);
