
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_const.h"
//silver_chain_scope_end
char * CAmalgamator_generate_amalgamation(
    const char*filename,
    bool (*include_callback)(const char *filename,const  char *path, void *extra_args),
    bool (*dont_change_callback)(const char *filename,const  char *path, void *extra_args),
    void *args
);
char * CAmalgamator_generate_amalgamation_simple(const char*filename);
