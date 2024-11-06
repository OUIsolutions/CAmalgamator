
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.cli_declare.h"
//silver_chain_scope_end

void is_inside(const char *import_name,const char *flag,DtwStringArray *source){
    for(int i = 0; i < source->size; i++){

        char *current = source->strings[i];

    }
}

void collect_flag(CliFlag *flag,DtwStringArray *source){
    if(flag->exist == false){
        return;
    }
    for(int i = 0; i < flag->size;i++){
        char *current = cli.flag.get_str(flag,i,false);
        dtw.string_array.append(source,current);
    }
}
