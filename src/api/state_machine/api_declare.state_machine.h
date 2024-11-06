
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_type1.h"
//silver_chain_scope_end
int  private_CAmalgamator_generate_amalgamation(
    short behavionr,
    const char*filename,
    CTextStack * final,
    DtwStringArray *already_included_sha_list,
    short (*generator_handler)(const char *filename,const  char *import_name, void *extra_args),
    void *args,
    char **include_code_error,
    const char *include_code
);
