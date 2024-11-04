
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_declare.h"

//silver_chain_scope_end





int  private_CAmalgamator_generate_amalgamation(
    CTextStack * final,
    const char*filename,
    DtwStringArray *already_included_sha_list
){

    #ifdef CAMALGAMATOR_DEBUG
        CAmalgamation_append("private_CAmalgamator_generate_amalgamation");
        CHashObject_set_string(CAmalgamation_stack_json, "final",final->rendered_text);
        CHashObject_set_string(CAmalgamation_stack_json,"filename",filename);
        CHashObject_set_any(CAmalgamation_stack_json, "already_included", convert_string_array_to_chash_object(already_included_sha_list));
        CAmalgamator_plot_json(1);
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
        return CAMALGAMATOR_FILE_NOT_FOUND;
    }

    #ifdef CAMALGAMATOR_DEBUG
            CHashObject_set_string(CAmalgamation_stack_json,"content",content);
            CAmalgamator_plot_json(2);
    #endif


    char *sha_content = dtw_generate_sha_from_any(content,size);
    #ifdef CAMALGAMATOR_DEBUG
        CHashObject_set_string(CAmalgamation_stack_json,"sha",sha_content);
        CAmalgamator_plot_json(3);
    #endif

    UniversalGarbage_add_simple(garbage, sha_content);
    bool is_already_included =DtwStringArray_find_position(already_included_sha_list,sha_content) != -1;

    #ifdef CAMALGAMATOR_DEBUG
        CHashObject_set_bool(CAmalgamation_stack_json,"already_included",is_already_included);
        CAmalgamator_plot_json(4);
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
        CHashObject_set_any(CAmalgamation_stack_json, "already_included", convert_string_array_to_chash_object(already_included_sha_list));
        CAmalgamator_plot_json(5);
    #endif

    DtwPath *current_path = newDtwPath(filename);
    UniversalGarbage_add(garbage,DtwPath_free, current_path);


    char *dir = DtwPath_get_dir(current_path);

    CTextStack *str_file = newCTextStack_string_empty();
    UniversalGarbage_add(garbage,CTextStack_free,str_file);
    #ifdef  CAMALGAMATOR_DEBUG
        CHashObject_set_string(CAmalgamation_stack_json,"str_file",str_file->rendered_text);
        CAmalgamator_plot_json(6);

    #endif


    int state = PRIVATE_CAMALGAMATOR_NORMAL_STATE;
    #ifdef  CAMALGAMATOR_DEBUG
        CHashObject_set_long(CAmalgamation_stack_json,"state",state);
        CAmalgamator_plot_json(7);
    #endif
    for(int i =0; i < size;i++){

        char current_char = content[i];
        #ifdef  CAMALGAMATOR_DEBUG
            char formmated_char[10] = {0};
            sprintf(formmated_char,"%c", current_char);
            CHashObject_set_string(CAmalgamation_stack_json,"current_char",formmated_char);
            CAmalgamator_plot_json(8);
        #endif


        if(state == PRIVATE_CAMALGAMATOR_NORMAL_STATE){

            bool is_multiline_coment_start = private_CAmalgamator_is_start_multiline_coment_at_point(content,size,i);
            #ifdef  CAMALGAMATOR_DEBUG
                CHashObject_set_bool(CAmalgamation_stack_json,"is_multiline_coment_start",is_multiline_coment_start);
                CAmalgamator_plot_json(9);
            #endif


            if(is_multiline_coment_start){
                state = PRIVATE_CAMALGAMATOR_INSIDE_MULTILINE_COMENT;
                CTextStack_format(final,"%c",current_char);
                #ifdef  CAMALGAMATOR_DEBUG
                    CHashObject_set_long(CAmalgamation_stack_json,"state",state);
                    CHashObject_set_string(CAmalgamation_stack_json,"final", final->rendered_text);
                    CAmalgamator_plot_json(10);
                #endif

                continue;
            }

            bool is_inline_coment_start =  private_CAmalgamator_is_start_inline_coment_at_point(content,size,i);
            #ifdef  CAMALGAMATOR_DEBUG
                CHashObject_set_bool(CAmalgamation_stack_json,"is_inline_coment_start",is_inline_coment_start);
                CAmalgamator_plot_json(11);
            #endif

            if(is_inline_coment_start){
                state = PRIVATE_CAMALGAMATOR_INSIDE_INLINE_COMENT;
                CTextStack_format(final,"%c",current_char);
                #ifdef  CAMALGAMATOR_DEBUG
                    CHashObject_set_long(CAmalgamation_stack_json,"state",state);
                    CHashObject_set_string(CAmalgamation_stack_json,"final", final->rendered_text);
                    CAmalgamator_plot_json(12);
                #endif
                continue;
            }

            bool is_str_start = current_char == '"';
            if(is_str_start){
                state = PRIVATE_CAMALGAMATOR_INSIDE_NORMAL_STRING;
                CTextStack_format(final,"%c",current_char);
                #ifdef  CAMALGAMATOR_DEBUG
                    CHashObject_set_long(CAmalgamation_stack_json,"state",state);
                    CHashObject_set_string(CAmalgamation_stack_json,"final", final->rendered_text);
                    CAmalgamator_plot_json(13);
                #endif
                continue;
            }

            bool is_char_start = current_char == '\'';
            if(is_char_start){
                state = PRIVATE_CAMALGAMATOR_INSIDE_CHAR;
                CTextStack_format(final,"%c",current_char);
                #ifdef  CAMALGAMATOR_DEBUG
                    CHashObject_set_long(CAmalgamation_stack_json,"state",state);
                    CHashObject_set_string(CAmalgamation_stack_json,"final", final->rendered_text);
                    CAmalgamator_plot_json(14);
                #endif
                continue;
            }

            bool is_include = private_CAmalgamator_is_include_at_point(content,size,i);
            if(is_include){
                state =PRIVATE_CAMALGAMATOR_WATING_FILENAME_STRING_START;
                #ifdef  CAMALGAMATOR_DEBUG
                    CHashObject_set_long(CAmalgamation_stack_json,"state",state);
                    CAmalgamator_plot_json(15);
                #endif
                continue;; // we dont format include here
            }

            CTextStack_format(final,"%c",current_char);
            #ifdef  CAMALGAMATOR_DEBUG
                CHashObject_set_string(CAmalgamation_stack_json,"final", final->rendered_text);
                CAmalgamator_plot_json(16);
            #endif
            continue;
        }

        if(state == PRIVATE_CAMALGAMATOR_INSIDE_MULTILINE_COMENT ){
            bool is_multiline_coment_end = private_CAmalgamator_is_end_multiline_coment_at_point(content,size,i);
            #ifdef  CAMALGAMATOR_DEBUG
                CHashObject_set_bool(CAmalgamation_stack_json,"is_multiline_coment_end",is_multiline_coment_end);
                CAmalgamator_plot_json(17);
            #endif
            if(is_multiline_coment_end){
                state = PRIVATE_CAMALGAMATOR_NORMAL_STATE;
                #ifdef  CAMALGAMATOR_DEBUG
                    CHashObject_set_long(CAmalgamation_stack_json,"state",state);
                    CAmalgamator_plot_json(18);
                #endif
            }
            CTextStack_format(final,"%c",current_char);
            #ifdef  CAMALGAMATOR_DEBUG
                CHashObject_set_string(CAmalgamation_stack_json,"final", final->rendered_text);
                CAmalgamator_plot_json(19);
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
                    CAmalgamator_plot_json(20);
                #endif
            }

            CTextStack_format(final,"%c",current_char);
            #ifdef  CAMALGAMATOR_DEBUG
                CHashObject_set_string(CAmalgamation_stack_json,"final", final->rendered_text);
                CAmalgamator_plot_json(21);
            #endif

            continue;
        }

        if(state == PRIVATE_CAMALGAMATOR_INSIDE_NORMAL_STRING){
            char last_char = content[i-1];
            #ifdef  CAMALGAMATOR_DEBUG
                char formmated_last_char[10] = {0};
                sprintf(formmated_char,"%c", last_char);
                CHashObject_set_string(CAmalgamation_stack_json,"last_char", formmated_last_char);
                CAmalgamator_plot_json(22);
            #endif
            bool is_str_end = current_char == '"' && last_char != '\\';
            #ifdef  CAMALGAMATOR_DEBUG
                CHashObject_set_bool(CAmalgamation_stack_json,"is_str_end", is_str_end);
                CAmalgamator_plot_json(23);
            #endif

            if(is_str_end){
                state = PRIVATE_CAMALGAMATOR_NORMAL_STATE;
                #ifdef  CAMALGAMATOR_DEBUG
                    CHashObject_set_long(CAmalgamation_stack_json,"state", state);
                    CAmalgamator_plot_json(24);
                #endif
            }

            CTextStack_format(final,"%c",current_char);
            #ifdef  CAMALGAMATOR_DEBUG
                CHashObject_set_string(CAmalgamation_stack_json,"final", final->rendered_text);
                CAmalgamator_plot_json(25);
            #endif

            continue;
        }

        if(state == PRIVATE_CAMALGAMATOR_INSIDE_CHAR){
            char last_char = content[i-1];
            #ifdef  CAMALGAMATOR_DEBUG
                    char formmated_last_char[10] = {0};
                    sprintf(formmated_char,"%c", last_char);
                    CHashObject_set_string(CAmalgamation_stack_json,"last_char", formmated_last_char);
                    CAmalgamator_plot_json(26);
            #endif

            bool is_char_end = current_char == '\''&& last_char != '\'';
            #ifdef  CAMALGAMATOR_DEBUG
                    CHashObject_set_bool(CAmalgamation_stack_json,"is_char_end", is_char_end);
                    CAmalgamator_plot_json(27);
            #endif
            if(is_char_end){
                state = PRIVATE_CAMALGAMATOR_NORMAL_STATE;
                #ifdef  CAMALGAMATOR_DEBUG
                    CHashObject_set_long(CAmalgamation_stack_json,"state", state);
                    CAmalgamator_plot_json(28);
                #endif
            }
            CTextStack_format(final,"%c",current_char);
            #ifdef  CAMALGAMATOR_DEBUG
                CHashObject_set_string(CAmalgamation_stack_json,"final", final->rendered_text);
                CAmalgamator_plot_json(29);
            #endif
            continue;
        }

        if(state == PRIVATE_CAMALGAMATOR_WATING_FILENAME_STRING_START){
            if (current_char == '"'){
                state = PRIVATE_CAMALGAMATOR_COLLECTING_FILENAME;
                #ifdef  CAMALGAMATOR_DEBUG
                    CHashObject_set_long(CAmalgamation_stack_json,"state", state);
                    CAmalgamator_plot_json(30);
                #endif
                continue;
            }
            if(current_char == '<'){
                state = PRIVATE_CAMALGAMATOR_NORMAL_STATE;
                //aborts inclusion
                CTextStack_text(final,"#include <");
                #ifdef  CAMALGAMATOR_DEBUG
                    CHashObject_set_long(CAmalgamation_stack_json,"state", state);
                    CHashObject_set_string(CAmalgamation_stack_json,"final", final->rendered_text);
                    CAmalgamator_plot_json(31);
                #endif
                continue;

            }
        }

        if(state == PRIVATE_CAMALGAMATOR_COLLECTING_FILENAME){

            if(current_char == '"'){

                char *new_path = dtw_concat_path(dir, str_file->rendered_text);
                #ifdef  CAMALGAMATOR_DEBUG
                    CHashObject_set_string(CAmalgamation_stack_json,"new_path", (const char*)new_path);
                    CAmalgamator_plot_json(32);
                #endif
                int error = private_CAmalgamator_generate_amalgamation(final,new_path,already_included_sha_list);
                #ifdef  CAMALGAMATOR_DEBUG
                    CHashObject_set_long(CAmalgamation_stack_json,"error", error);
                    CAmalgamator_plot_json(33);
                #endif
                if(error){
                    UniversalGarbage_free(garbage);
                    return error;
                }



                CTextStack_restart(str_file);
                #ifdef  CAMALGAMATOR_DEBUG
                    CHashObject_set_string(CAmalgamation_stack_json,"str_file", str_file->rendered_text);
                    CAmalgamator_plot_json(34);
                #endif

                state = PRIVATE_CAMALGAMATOR_NORMAL_STATE;
                #ifdef  CAMALGAMATOR_DEBUG
                    CHashObject_set_long(CAmalgamation_stack_json,"state", state);
                    CAmalgamator_plot_json(35);
                #endif
                continue;
            }

            CTextStack_format(str_file,"%c", current_char);
            #ifdef  CAMALGAMATOR_DEBUG
                    CHashObject_set_string(CAmalgamation_stack_json,"str_file", str_file->rendered_text);
                    CAmalgamator_plot_json(36);
            #endif
            continue;
        }
    }
    UniversalGarbage_free(garbage);

    #ifdef CAMALGAMATOR_DEBUG
                        CAmalgamation_pop();
    #endif
    return CAMALGAMATOR_OK;
}
