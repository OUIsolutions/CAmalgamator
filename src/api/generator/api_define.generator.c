
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_declare.h"
#include <cstdio>

//silver_chain_scope_end




int  private_CAmalgamator_generate_amalgamation(
    CTextStack * final,
    const char*filename,
    DtwStringArray *already_included_sha_list,
    CHashObject *old_stack
){
    #ifdef CAMALGAMATOR_DEBUG
        CAmalgamation_append("private_CAmalgamator_generate_amalgamation");
        CAmalgamator_plot_json(19);
    #endif

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
        return CAMALGAMATOR_ERROR;
    }

    #ifdef CAMALGAMATOR_DEBUG
            CHashObject_set_string(CAmalgamation_stack_json,"content",content);
            CAmalgamator_plot_json(37);
    #endif

    char *sha_content = dtw_generate_sha_from_any(content,size);
    #ifdef CAMALGAMATOR_DEBUG
        CHashObject_set_string(CAmalgamation_stack_json,"sha",sha_content);
        CAmalgamator_plot_json(43);
    #endif

    UniversalGarbage_add_simple(garbage, sha_content);
    bool is_already_included =DtwStringArray_find_position(already_included_sha_list,sha_content) != -1;

    #ifdef CAMALGAMATOR_DEBUG
        CHashObject_set_bool(CAmalgamation_stack_json,"already_included",is_already_included);
        CAmalgamator_plot_json(51);
    #endif

    if(is_already_included){

        UniversalGarbage_free(garbage);

        #ifdef CAMALGAMATOR_DEBUG
                    CAmalgamation_pop();
        #endif
        return CAMALGAMATOR_OK;
    }

    DtwStringArray_append(already_included_sha_list, sha_content);
    #ifdef CAMALGAMATOR_DEBUG
        CHashObject_set_any(old_stack, "already_included", convert_string_array_to_chash_object(already_included_sha_list));
        CAmalgamator_plot_json(67);

    #endif


    CTextStack *str_file = newCTextStack_string_empty();
    UniversalGarbage_add(garbage,CTextStack_free,str_file);
    #ifdef  CAMALGAMATOR_DEBUG
        CHashObject_set_string(CAmalgamation_stack_json,"str_file",str_file->rendered_text);
        CAmalgamator_plot_json(76);

    #endif


    int state = PRIVATE_CAMALGAMATOR_NORMAL_STATE;
    #ifdef  CAMALGAMATOR_DEBUG
        CHashObject_set_long(CAmalgamation_stack_json,"state",state);
        CAmalgamator_plot_json(84);
    #endif

    for(int i =0; i < size;i++){

        char current_char = content[i];
        #ifdef  CAMALGAMATOR_DEBUG
            char formmated_char[10] = {0};
            sprintf(formmated_char,"%c", current_char);
            CHashObject_set_string(CAmalgamation_stack_json,"current_char",formmated_char);
            CAmalgamator_plot_json(94);
        #endif


        if(state == PRIVATE_CAMALGAMATOR_NORMAL_STATE){

            bool is_multiline_coment_start = private_CAmalgamator_is_start_multiline_coment_at_point(content,size,i);
            #ifdef  CAMALGAMATOR_DEBUG
                CHashObject_set_bool(CAmalgamation_stack_json,"is_multiline_coment_start",is_multiline_coment_start);
                CAmalgamator_plot_json(103);
            #endif


            if(is_multiline_coment_start){
                state = PRIVATE_CAMALGAMATOR_INSIDE_MULTILINE_COMENT;
                CTextStack_format(final,"%c",current_char);
                #ifdef  CAMALGAMATOR_DEBUG
                    CHashObject_set_long(CAmalgamation_stack_json,"state",state);
                    CHashObject_set_string(old_stack,"final", final->rendered_text);
                    CAmalgamator_plot_json(113);
                #endif

                continue;
            }

            bool is_inline_coment_start =  private_CAmalgamator_is_start_inline_coment_at_point(content,size,i);
            if(is_inline_coment_start){
                state = PRIVATE_CAMALGAMATOR_INSIDE_INLINE_COMENT;
                CTextStack_format(final,"%c",current_char);
                #ifdef  CAMALGAMATOR_DEBUG
                    CHashObject_set_long(CAmalgamation_stack_json,"state",state);
                    CHashObject_set_string(old_stack,"final", final->rendered_text);
                    CAmalgamator_plot_json(126);
                #endif
                continue;
            }

            bool is_str_start = current_char == '"';
            if(is_str_start){
                state = PRIVATE_CAMALGAMATOR_INSIDE_NORMAL_STRING;
                CTextStack_format(final,"%c",current_char);
                #ifdef  CAMALGAMATOR_DEBUG
                    CHashObject_set_long(CAmalgamation_stack_json,"state",state);
                    CHashObject_set_string(old_stack,"final", final->rendered_text);
                    CAmalgamator_plot_json(138);
                #endif
                continue;
            }

            bool is_char_start = current_char == '\'';
            if(is_char_start){
                state = PRIVATE_CAMALGAMATOR_INSIDE_CHAR;
                CTextStack_format(final,"%c",current_char);
                #ifdef  CAMALGAMATOR_DEBUG
                    CHashObject_set_long(CAmalgamation_stack_json,"state",state);
                    CHashObject_set_string(old_stack,"final", final->rendered_text);
                    CAmalgamator_plot_json(150);
                #endif
                continue;
            }

            bool is_include = private_CAmalgamator_is_include_at_point(content,size,i);
            if(is_include){
                state =PRIVATE_CAMALGAMATOR_WATING_FILENAME_STRING_START;
                #ifdef  CAMALGAMATOR_DEBUG
                    CHashObject_set_long(CAmalgamation_stack_json,"state",state);
                    CAmalgamator_plot_json(160);
                #endif
                continue;; // we dont format include here
            }

            CTextStack_format(final,"%c",current_char);
            #ifdef  CAMALGAMATOR_DEBUG
                CHashObject_set_string(old_stack,"final", final->rendered_text);
                CAmalgamator_plot_json(168);
            #endif
            continue;
        }

        if(state == PRIVATE_CAMALGAMATOR_INSIDE_MULTILINE_COMENT ){
            bool is_multiline_coment_end = private_CAmalgamator_is_end_multiline_coment_at_point(content,size,i);
            #ifdef  CAMALGAMATOR_DEBUG
                CHashObject_set_bool(CAmalgamation_stack_json,"is_multiline_coment_end",is_multiline_coment_end);
                CAmalgamator_plot_json(177);
            #endif
            if(is_multiline_coment_end){
                state = PRIVATE_CAMALGAMATOR_NORMAL_STATE;
                #ifdef  CAMALGAMATOR_DEBUG
                    CHashObject_set_long(CAmalgamation_stack_json,"state",state);
                    CAmalgamator_plot_json(183);
                #endif
            }
            CTextStack_format(final,"%c",current_char);
            #ifdef  CAMALGAMATOR_DEBUG
                CHashObject_set_string(old_stack,"final", final->rendered_text);
                CAmalgamator_plot_json(189);
            #endif

            continue;

        }

        if(state == PRIVATE_CAMALGAMATOR_INSIDE_INLINE_COMENT){
            bool is_inline_comment_end = current_char == '\n';
            #ifdef CAMALGAMATOR_DEBUG
                CHashObject_set_bool(CAmalgamation_stack_json,"is_inline_comment_end", is_inline_comment_end);
            #endif

            if(is_inline_comment_end){
                state = PRIVATE_CAMALGAMATOR_NORMAL_STATE;
                #ifdef  CAMALGAMATOR_DEBUG
                    CHashObject_set_long(CAmalgamation_stack_json,"state",state);
                    CAmalgamator_plot_json(183);
                #endif
            }

            CTextStack_format(final,"%c",current_char);
            #ifdef  CAMALGAMATOR_DEBUG
                CHashObject_set_string(old_stack,"final", final->rendered_text);
                CAmalgamator_plot_json(213);
            #endif

            continue;
        }

        if(state == PRIVATE_CAMALGAMATOR_INSIDE_NORMAL_STRING){
            char last_char = content[i-1];
            #ifdef  CAMALGAMATOR_DEBUG
                char formmated_last_char[10] = {0};
                sprintf(formmated_char,"%c", last_char);
                CHashObject_set_string(old_stack,"last_char", formmated_last_char);
                CAmalgamator_plot_json(226);
            #endif
            bool is_str_end = current_char == '"' && last_char != '\\';
            #ifdef  CAMALGAMATOR_DEBUG
                CHashObject_set_bool(old_stack,"is_str_end", is_str_end);
                CAmalgamator_plot_json(231);
            #endif

            if(is_str_end){
                state = PRIVATE_CAMALGAMATOR_NORMAL_STATE;
                #ifdef  CAMALGAMATOR_DEBUG
                    CHashObject_set_long(old_stack,"state", state);
                    CAmalgamator_plot_json(237);
                #endif
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
                CTextStack_format(final,"#include < ");
                continue;

            }
        }

        if(state == PRIVATE_CAMALGAMATOR_COLLECTING_FILENAME){

            if(current_char == '"'){

                int error = private_CAmalgamator_generate_amalgamation(final,str_file->rendered_text,already_included_sha_list,old_stack);
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
        UniversalGarbage_free(garbage);
    }

    #ifdef CAMALGAMATOR_DEBUG
                        CAmalgamation_pop();
    #endif
    return CAMALGAMATOR_OK;
}
