
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_type1.h"
//silver_chain_scope_end
CAmalgamatorErrorOrString * CAmalgamator_generate_amalgamation(
    const char*filename,
    short (*generator_handler)(const char *filename,const  char *path, void *extra_args),
    void *args
);
CAmalgamatorErrorOrString * CAmalgamator_generate_amalgamation_simple(const char*filename);
