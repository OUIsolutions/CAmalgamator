
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_declare.h"
//silver_chain_scope_end



CAmalgamatorErrorOrContent * CAmalgamator_generate_amalgamation(
    const char*filename,
    long max_content_size,
    short (*generator_handler)(const char *filename,const  char *path, void *extra_args),
    void *args
){
    CTextStack *final = newCTextStack_string_empty();
    DtwStringArray *already_included = newDtwStringArray();
    char *include_error_name = NULL;
    char *filename_error = NULL;
    int error  = private_CAmalgamator_generate_amalgamation(
        CAMALGAMATOR_INCLUDE_ONCE,
        filename,
        final,
        already_included,
        &include_error_name,
        &filename_error,
        max_content_size,
        0, //recursion size
        NULL, //filename
        NULL, //include code
        generator_handler,
        args
    );

    DtwStringArray_free(already_included);
    if(error){
        long size = final->size;
        CTextStack_free(final);

        if(error == CAMALGAMATOR_FILE_NOT_FOUND_OR_ITS_NOT_CORRECTED_FORMATED && include_error_name){
            return Private_new_CAmalgamatorErrorOrString_as_error(
                CAMALGAMATOR_FILE_NOT_FOUND_OR_ITS_NOT_CORRECTED_FORMATED,
                include_error_name,
                filename_error,
                "include:'%s' at file '%s' not found",
                include_error_name,
                filename_error
            );
        }

        if(error == CAMALGAMATOR_FILE_NOT_FOUND_OR_ITS_NOT_CORRECTED_FORMATED){
            return Private_new_CAmalgamatorErrorOrString_as_error(
                CAMALGAMATOR_FILE_NOT_FOUND_OR_ITS_NOT_CORRECTED_FORMATED,
                NULL,
                filename_error,
                "file '%s' not found",
                filename_error
            );
        }
        if(error == CAMALGAMATOR_MAX_RECURSION_CALL && filename_error){
            return Private_new_CAmalgamatorErrorOrString_as_error(
                CAMALGAMATOR_MAX_RECURSION_CALL,
                include_error_name,
                filename_error,
                "mex recursion call of: %d at file '%s'",
                CAMALGAMATOR_MAX_RECURSION,
                filename_error
            );
        }

        if(error == CAMALGAMATOR_MAX_RECURSION_CALL){
            return Private_new_CAmalgamatorErrorOrString_as_error(
                CAMALGAMATOR_MAX_RECURSION_CALL,
                include_error_name,
                filename_error,
                "mex recursion call of:%d",
                CAMALGAMATOR_MAX_RECURSION
            );
        }

        if(error == CAMALGAMATOR_MAX_CONTENT_SIZE && filename_error){
            return Private_new_CAmalgamatorErrorOrString_as_error(
                CAMALGAMATOR_MAX_CONTENT_SIZE,
                include_error_name,
                filename_error,
                "reached the max content size of %ld bytes in %ld bytes in file '%s'",
                max_content_size,
                size - max_content_size,
                filename_error
            );
        }

        if(error == CAMALGAMATOR_MAX_CONTENT_SIZE){
            return Private_new_CAmalgamatorErrorOrString_as_error(
                CAMALGAMATOR_MAX_CONTENT_SIZE,
                include_error_name,
                filename_error,
                "reached the max content size of %ld bytes in %ld bytes",
                max_content_size,
                size - max_content_size
            );
        }
        return Private_new_CAmalgamatorErrorOrString_as_error(
                CAMALGAMATOR_UNEXPECTED_ERROR,
                NULL,
                NULL,
                "unexpected behavior"
        );

    }
    char *content =  CTextStack_self_transform_in_string_and_self_clear(final);
    return Private_new_CAmalgamatorErrorOrString_as_ok(content);
}

CAmalgamatorErrorOrContent * CAmalgamator_generate_amalgamation_simple(const char*filename,long max_content_size){
    return CAmalgamator_generate_amalgamation(filename,max_content_size,NULL,NULL);
}
