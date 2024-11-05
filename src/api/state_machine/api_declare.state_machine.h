
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_const.h"
//silver_chain_scope_end
int  private_CAmalgamator_generate_amalgamation(
    CTextStack * final,
    const char*filename,
    DtwStringArray *already_included_sha_list,
    bool (*include_callback)(const char *filename,const  char *path, void *extra_args),
    bool (*dont_change_callback)(const char *filename,const  char *path, void *extra_args),
    void *args
);
