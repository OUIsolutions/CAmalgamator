
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_type1.h"
//silver_chain_scope_end
int  private_CAmalgamator_generate_amalgamation(
    short behavior,
    const char*filename,
    CTextStack * final,
    DtwStringArray *already_included,
    char **include_code_error,
    char **filename_errr,
    long max_content_size,
    const char *prev_file,
    const char *include_code,
    short (*generator_handler)(const char *filename,const  char *import_name, void *extra_args),
    void *args
);
