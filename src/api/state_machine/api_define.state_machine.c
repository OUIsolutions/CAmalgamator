
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_declare.h"
//silver_chain_scope_end

#define COLLECT_ERROR_ATTIBUTES \
if(include_code == NULL){\
    *filename_errr = strdup(prev_file);\
}\
if(include_code){\
    *include_code_error = strdup(include_code);\
    *filename_errr = dtw_get_absolute_path(prev_file);\
}


int  private_CAmalgamator_generate_amalgamation(
    const char *prev_file,
    const char *include_code,
    CTextStack * final,
    DtwStringArray *already_included,
    char **include_code_error,
    char **filename_errr,
    long max_content_size,
    int recursion_call,
    int max_recursion,
    short (*generator_handler)(const char *filename,const  char *import_name, void *extra_args),
    void *args
){
    if(recursion_call >= max_recursion){
      COLLECT_ERROR_ATTIBUTES
        return CAMALGAMATOR_MAX_RECURSION_CALL;
    }

    if(final->size >= max_content_size ){
        COLLECT_ERROR_ATTIBUTES
        return CAMALGAMATOR_MAX_CONTENT_SIZE;
    }

    short behavior = CAMALGAMATOR_INCLUDE_ONCE;
    char *filename = (char*)prev_file;
    UniversalGarbage *garbage = newUniversalGarbage();

    DtwPath *current_path = newDtwPath(prev_file);
    UniversalGarbage_add(garbage,DtwPath_free, current_path);
    char *dir = DtwPath_get_dir(current_path);

    if(include_code){
        filename = dtw_concat_path(dir,include_code);

        UniversalGarbage_add_simple(garbage,filename);
    }

    bool is_binary;
    long size;
    char *content = (char*)dtw_load_any_content(filename,&size,&is_binary);
    UniversalGarbage_add_simple(garbage, content);
    if(content == NULL || is_binary){


        COLLECT_ERROR_ATTIBUTES
        UniversalGarbage_free(garbage);
        return CAMALGAMATOR_FILE_NOT_FOUND_OR_ITS_NOT_CORRECTED_FORMATED;
    }

    if(generator_handler && include_code){
         behavior  = generator_handler(filename,include_code, args);
    }

    if(behavior < 0) {
        COLLECT_ERROR_ATTIBUTES
        UniversalGarbage_free(garbage);
        return behavior;
    }

    if(behavior == CAMALGAMATOR_DONT_INCLUDE){
        return PRIVATE_CAMALGAMATOR_NO_ERRORS;
    }
    if(behavior == CAMALGAMATOR_DONT_CHANGE){
        CTextStack_format(final,"#include \"%s\"\n", include_code);
        return PRIVATE_CAMALGAMATOR_NO_ERRORS;
    }


    if(behavior == CAMALGAMATOR_INCLUDE_ONCE){
        char *absolute = dtw_get_absolute_path(filename);
        UniversalGarbage_add_simple(garbage, absolute);
        bool is_already_included =DtwStringArray_find_position(already_included,absolute) != -1;
        if(is_already_included){
               UniversalGarbage_free(garbage);
                return PRIVATE_CAMALGAMATOR_NO_ERRORS;
        }
        DtwStringArray_append(already_included, absolute);
    }

    CTextStack *new_include_code = newCTextStack_string_empty();
    UniversalGarbage_add(garbage,CTextStack_free,new_include_code);

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
                i+=sizeof("#include")-1;
                continue; // we dont format include here
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

            if(current_char == ' '){
            continue;

            }
            state = PRIVATE_CAMALGAMATOR_NORMAL_STATE;
            //aborts inclusion
            CTextStack_format(final,"#include %c",current_char);
        }

        if(state == PRIVATE_CAMALGAMATOR_COLLECTING_FILENAME){

            // means its the end of the #include "filename"
            // so whe have the hle filename stored in
            // new_include_code->rendered_text
            if(current_char == '"'){
                int error = private_CAmalgamator_generate_amalgamation(
                    filename,
                    new_include_code->rendered_text,
                    final,
                    already_included,
                    include_code_error,
                    filename_errr,
                    max_content_size,
                    recursion_call+1,
                    max_recursion,
                    generator_handler,
                    args
                );
                if(error){
                        UniversalGarbage_free(garbage);
                        return error;
                }
                CTextStack_restart(new_include_code);
                state = PRIVATE_CAMALGAMATOR_NORMAL_STATE;
            }

            else{
                CTextStack_format(new_include_code,"%c", current_char);
            }
        }
    }
    UniversalGarbage_free(garbage);
    return PRIVATE_CAMALGAMATOR_NO_ERRORS;
}
