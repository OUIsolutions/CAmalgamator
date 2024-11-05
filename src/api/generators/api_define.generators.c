
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_declare.h"
//silver_chain_scope_end



char * CAmalgamator_generate_amalgamation(
    const char*filename,
    bool (*include_callback)(const char *filename,const  char *path, void *extra_args),
    bool (*dont_change_callback)(const char *filename,const  char *path, void *extra_args),
    void *args
){
    CTextStack *final = newCTextStack_string_empty();
    DtwStringArray *already_included = newDtwStringArray();
    int error  = private_CAmalgamator_generate_amalgamation(final,filename,already_included,include_callback,dont_change_callback,args);
    DtwStringArray_free(already_included);
    if(error){
        CTextStack_free(final);
        return NULL;
    }
    return CTextStack_self_transform_in_string_and_self_clear(final);
}

char * CAmalgamator_generate_amalgamation_simple(const char*filename){
    return CAmalgamator_generate_amalgamation(filename,NULL,NULL,NULL);
}
