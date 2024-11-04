#define  CAMALGAMATOR_DEBUG

//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_declare.h"
//silver_chain_scope_end
#ifdef CAMALGAMATOR_DEBUG

void CAmalgamator_start(){
    if(internal_stack_json == NULL){
        dtw_remove_any(CAMALGAMATION_PLOTAGE_FOLDER);
        internal_stack_json = newCHashArrayEmpty();
    }
}

void CAmalgamation_append(const char *func_name){
    CAmalgamator_start();

    stack_json = newCHashObjectEmpty();
    CHashArray_append(internal_stack_json,
        newCHashObject(
                "func_name",newCHashString(func_name),
                "itens",stack_json
            )
    );
}

void CAmalgamation_pop(){
    CAmalgamator_start();
    CHashArray_remove(internal_stack_json, -1);
    if(CHash_get_size(internal_stack_json)){
        stack_json = CHashArray_get(internal_stack_json,-1);
    }

}

void CAmalgamator_plot_json(){

    CAmalgamator_start();
    if(CAmalgamation_total_plotage < CAmalgamator_min_plotage){
        return;
    }

    if(CAmalgamation_total_plotage > CAmalgamator_max_plotage && CAmalgamator_max_plotage != -1){
        return;
    }

    char *content = CHash_dump_to_json_string(internal_stack_json);
    char path[sizeof(CAMALGAMATION_PLOTAGE_FOLDER) + 10] = {0};
    sprintf(path,"%s/%d.json",CAMALGAMATION_PLOTAGE_FOLDER,CAmalgamation_total_plotage);
    dtw_write_string_file_content(path,content);
    free(content);

    CAmalgamation_total_plotage+=1;
}

#endif
