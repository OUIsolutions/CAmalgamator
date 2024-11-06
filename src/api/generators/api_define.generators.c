
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_declare.h"
//silver_chain_scope_end



CAmalgamatorErrorOrContent * CAmalgamator_generate_amalgamation(
    const char*filename,
    short (*generator_handler)(const char *filename,const  char *path, void *extra_args),
    void *args
){
    CTextStack *final = newCTextStack_string_empty();
    DtwStringArray *already_included = newDtwStringArray();
    char *filename_error = NULL;
    int error  = private_CAmalgamator_generate_amalgamation(
        CAMALGAMATOR_INCLUDE_ONCE,
        filename,
        final,
        already_included,
        generator_handler,
        args,
        &filename_error,
        NULL
    );

    DtwStringArray_free(already_included);
    if(error){
        CTextStack_free(final);
        if(error == CAMALGAMATOR_FILE_NOT_FOUND){
            return Private_new_CAmalgamatorErrorOrString_as_error(
                CAMALGAMATOR_FILE_NOT_FOUND,
                filename_error,
                "file %s not found",
                filename
            );
        }

        return Private_new_CAmalgamatorErrorOrString_as_error(
                CAMALGAMATOR_FILE_NOT_FOUND,
                NULL,
                "unexpected behavior"
        );

    }
    char *content =  CTextStack_self_transform_in_string_and_self_clear(final);
    return Private_new_CAmalgamatorErrorOrString_as_ok(content);
}

CAmalgamatorErrorOrContent * CAmalgamator_generate_amalgamation_simple(const char*filename){
    return CAmalgamator_generate_amalgamation(filename,NULL,NULL);
}
