
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_declare.h"
//silver_chain_scope_end




int  private_CAmalgamator_generate_amalgamation(
    CTextStack * final,
    const char*filename,
    DtwStringArray *already_included_sha_list
){
    UniversalGarbage *garbage = newUniversalGarbage();
    bool is_binary;
    long size;
    char *content = (char*)dtw_load_any_content(filename,&size,&is_binary);
    UniversalGarbage_add_simple(garbage, content);
    CTextStack *str_file = newCTextStack_string_empty();
    UniversalGarbage_add(garbage,CTextStack_free,str_file);

    int state = PRIVATE_CAMALGAMATOR_COLECTING_CHAR_STATE;

    if(content == NULL || is_binary){
        UniversalGarbage_free(garbage);
        return CAMALGAMATOR_ERROR;
    }
    for(int i =0; i < size;i++){


        bool is_include_point =
        state == PRIVATE_CAMALGAMATOR_COLECTING_CHAR_STATE &&
        private_CAmalgamator_is_include_at_point(content,size,i);

        if(is_include_point){
            state = PRIVATE_CAMALGAMATOR_WATING_FILENAME_STRING_START;
            continue;
        }
        char current_char = content[i];

        bool is_multiline_coment_start =
        state == PRIVATE_CAMALGAMATOR_COLECTING_CHAR_STATE &&
        private_CAmalgamator_is_start_multiline_coment_at_point(content,size,i);

        if(is_multiline_coment_start){
            state = PRIVATE_CAMALGAMATOR_INSIDE_MULTILINE_COMENT;
        }

        bool is_multiline_coment_end =
        state == PRIVATE_CAMALGAMATOR_COLECTING_CHAR_STATE &&
        private_CAmalgamator_is_end_multiline_coment_at_point(content,size,i);

        bool normal_code =state = PRIVATE_CAMALGAMATOR_COLECTING_CHAR_STATE;
        if(normal_code){
            CTextStack_format(final,"%c", current_char);
            continue;
        }


        bool is_str_char = current_char == '"';
        bool is_include_string_beguining = state == PRIVATE_CAMALGAMATOR_WATING_FILENAME_STRING_START && is_str_char;
        if(is_include_string_beguining){
            state = PRIVATE_CAMALGAMATOR_COLLECTING_FILENAME;
            continue;
        }


        bool is_inside_include_string = state == PRIVATE_CAMALGAMATOR_COLLECTING_FILENAME && !is_str_char;
        if(is_inside_include_string){
            CTextStack_format(str_file,"%c",current_char);
        }


        bool is_include_string_end =state == PRIVATE_CAMALGAMATOR_COLLECTING_FILENAME && is_str_char;
        if(is_include_string_end){
            int error = private_CAmalgamator_generate_amalgamation(final,str_file->rendered_text,already_included_sha_list);
            if(error){
                UniversalGarbage_free(garbage);
                return error;
            }
            CTextStack_restart(str_file);
            state = PRIVATE_CAMALGAMATOR_COLECTING_CHAR_STATE;
        }



        char current = content[i];

    }

    return CAMALGAMATOR_OK;
}
