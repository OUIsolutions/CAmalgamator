
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
    if(content == NULL || is_binary){
        #ifdef CAMALGAMATOR_DEBUG
                    CAmalgamation_pop();
        #endif
        UniversalGarbage_free(garbage);
        return CAMALGAMATOR_FILE_NOT_FOUND;
    }



    char *sha_content = dtw_generate_sha_from_any(content,size);

    UniversalGarbage_add_simple(garbage, sha_content);
    bool is_already_included =DtwStringArray_find_position(already_included_sha_list,sha_content) != -1;



    if(is_already_included){
            UniversalGarbage_free(garbage);
            return CAMALGAMATOR_OK;
        }


    DtwStringArray_append(already_included_sha_list, sha_content);
    DtwPath *current_path = newDtwPath(filename);
    UniversalGarbage_add(garbage,DtwPath_free, current_path);


    char *dir = DtwPath_get_dir(current_path);

    CTextStack *str_file = newCTextStack_string_empty();
    UniversalGarbage_add(garbage,CTextStack_free,str_file);

    int state = PRIVATE_CAMALGAMATOR_NORMAL_STATE;
    for(int i =0; i < size;i++){

        char current_char = content[i];

        if(state == PRIVATE_CAMALGAMATOR_NORMAL_STATE){

            bool is_multiline_coment_start = private_CAmalgamator_is_start_multiline_coment_at_point(content,size,i);



            if(is_multiline_coment_start){
                state = PRIVATE_CAMALGAMATOR_INSIDE_MULTILINE_COMENT;
                CTextStack_format(final,"%c",current_char);
                continue;
            }

            bool is_inline_coment_start =  private_CAmalgamator_is_start_inline_coment_at_point(content,size,i);

            if(is_inline_coment_start){
                state = PRIVATE_CAMALGAMATOR_INSIDE_INLINE_COMENT;
                CTextStack_format(final,"%c",current_char);

                continue;
            }

            bool is_str_start = current_char == '"';
            if(is_str_start){
                state = PRIVATE_CAMALGAMATOR_INSIDE_NORMAL_STRING;
                CTextStack_format(final,"%c",current_char);
                continue;
            }

            bool is_char_start = current_char == '\'';
            if(is_char_start){
                state = PRIVATE_CAMALGAMATOR_INSIDE_CHAR;
                CTextStack_format(final,"%c",current_char);
                continue;
            }

            bool is_include = private_CAmalgamator_is_include_at_point(content,size,i);
            if(is_include){
                state =PRIVATE_CAMALGAMATOR_WATING_FILENAME_STRING_START;
                continue;; // we dont format include here
            }

            CTextStack_format(final,"%c",current_char);
            continue;
        }

        if(state == PRIVATE_CAMALGAMATOR_INSIDE_MULTILINE_COMENT ){
            bool is_multiline_coment_end = private_CAmalgamator_is_end_multiline_coment_at_point(content,size,i);
            if(is_multiline_coment_end){
                state = PRIVATE_CAMALGAMATOR_NORMAL_STATE;
            }
            CTextStack_format(final,"%c",current_char);
            continue;

        }

        if(state == PRIVATE_CAMALGAMATOR_INSIDE_INLINE_COMENT){
            bool is_inline_comment_end = current_char == '\n';

            if(is_inline_comment_end){
                state = PRIVATE_CAMALGAMATOR_NORMAL_STATE;
            }

            CTextStack_format(final,"%c",current_char);
            continue;
        }

        if(state == PRIVATE_CAMALGAMATOR_INSIDE_NORMAL_STRING){
            char last_char = content[i-1];
            bool is_str_end = current_char == '"' && last_char != '\\';
            if(is_str_end){
                state = PRIVATE_CAMALGAMATOR_NORMAL_STATE;
            }

            CTextStack_format(final,"%c",current_char);

            continue;
        }

        if(state == PRIVATE_CAMALGAMATOR_INSIDE_CHAR){
            char last_char = content[i-1];


            bool is_char_end = current_char == '\''&& last_char != '\'';

            if(is_char_end){
                state = PRIVATE_CAMALGAMATOR_NORMAL_STATE;

            }
            CTextStack_format(final,"%c",current_char);

            continue;
        }

        if(state == PRIVATE_CAMALGAMATOR_WATING_FILENAME_STRING_START){
            if (current_char == '"'){
                state = PRIVATE_CAMALGAMATOR_COLLECTING_FILENAME;

                continue;
            }
            if(current_char == '<'){
                state = PRIVATE_CAMALGAMATOR_NORMAL_STATE;
                //aborts inclusion
                CTextStack_text(final,"#include <");
                continue;

            }
        }

        if(state == PRIVATE_CAMALGAMATOR_COLLECTING_FILENAME){

            if(current_char == '"'){
                char *new_path = dtw_concat_path(dir, str_file->rendered_text);
                int error = private_CAmalgamator_generate_amalgamation(final,new_path,already_included_sha_list);
                free(new_path);
                if(error){
                    UniversalGarbage_free(garbage);
                    return error;
                }
                CTextStack_restart(str_file);
                state = PRIVATE_CAMALGAMATOR_NORMAL_STATE;

                continue;
            }

            CTextStack_format(str_file,"%c", current_char);

            continue;
        }
    }
    UniversalGarbage_free(garbage);

    return CAMALGAMATOR_OK;
}
