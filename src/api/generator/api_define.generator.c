
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_declare.h"
//silver_chain_scope_end


bool private_CAmalgamator_is_include_at_point(char *content,int content_size,int point){
    if(point + PRIVATE_CAMALGAMATOR_INCLUDE_SIZE >= content_size){
        return false;
    }
    #define PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point,char)\
        if(content[point] != char){\
        return false;\
    }\

    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point,'#')
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point+1,'i')
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point+2,'n')
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point+3,'c')
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point+4,'l')
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point+5,'u')
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point+6,'d')
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point+7,'e')
    return true;
}
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


        bool is_include_point = state == PRIVATE_CAMALGAMATOR_COLECTING_CHAR_STATE &&
        private_CAmalgamator_is_include_at_point(content,size,i);
        if(is_include_point){
            state = PRIVATE_CAMALGAMATOR_WATING_FILENAME_STRING_START;
            continue;
        }
        char current_char = content[i];

        bool normal_code =state =  PRIVATE_CAMALGAMATOR_COLECTING_CHAR_STATE;
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
