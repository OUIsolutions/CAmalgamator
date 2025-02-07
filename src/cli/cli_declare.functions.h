
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.cli_globals.h"
//silver_chain_scope_end

bool is_inside(const char *file,DtwStringArray *source);

short generator_handler(const char *filename,const  char *import_name, void *extra_args);

void collect_flag(CliFlag *flag,DtwStringArray *source);
