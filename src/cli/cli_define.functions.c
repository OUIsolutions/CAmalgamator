
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.cli_declare.h"
//silver_chain_scope_end

bool is_inside(const char *file,DtwStringArray *source){
    for(int i = 0; i < source->size; i++){
        char *current = source->strings[i];

        if(dtw_starts_with(file,current)){
            return  true;
        }
    }
    return  false;
}
short generator_handler(const char *filename,const  char *import_name, void *extra_args){
    Behaviors * behavior = (Behaviors*)extra_args;
    char *absolute_file  = dtw.get_absolute_path(filename);
    if(absolute_file == NULL){
        return amalgamator.UNEXPECTED_ERROR;
    }

    if(is_inside(absolute_file,behavior->dont_change)){
        free(absolute_file);
        return  amalgamator.DONT_CHANGE;
    }
    if(is_inside(absolute_file, behavior->dont_include)){
        free(absolute_file);
        return  amalgamator.DONT_INCLUDE;
    }
    if(is_inside(absolute_file, behavior->include_perpetual)){
        free(absolute_file);
        return amalgamator.INCLUDE_PERPETUAL;
    }
    free(absolute_file);
    return  amalgamator.INCLUDE_ONCE;
}

int  collect_flag(CliFlag *flag,DtwStringArray *source){
    if(flag->exist == false){
        return amalgamator.NO_ERRORS;
    }
    for(int i = 0; i < flag->size;i++){
        char *current = cli.flag.get_str(flag,i,false);
        char *current_absolute = dtw.get_absolute_path(current);
        if(current_absolute == NULL){
            return amalgamator.UNEXPECTED_ERROR;
        }
        dtw.string_array.append(source,current_absolute);
        free(current_absolute);
    }
    return  amalgamator.NO_ERRORS;
}
