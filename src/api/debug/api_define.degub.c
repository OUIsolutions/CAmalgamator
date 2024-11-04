
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_declare.h"
//silver_chain_scope_end

void CAmalgamator_start(){
    if(CAmalgamation_internal_stack_json == NULL){
        dtw_remove_any(CAMALGAMATION_PLOTAGE_FOLDER);
        CAmalgamation_internal_stack_json = newCHashArrayEmpty();
    }
}

void CAmalgamation_append(const char *func_name){
    CAmalgamator_start();
    CAmalgamation_func_name  = func_name;
    CAmalgamation_stack_json = newCHashObjectEmpty();
    CHashArray_append(CAmalgamation_internal_stack_json,
        newCHashObject(
                "func_name",newCHashString(func_name),
                "itens",CAmalgamation_stack_json
            )
    );
}

void CAmalgamation_pop(){
    CAmalgamator_start();
    CHashArray_remove(CAmalgamation_internal_stack_json, -1);
    if(CHash_get_size(CAmalgamation_internal_stack_json)){
        CAmalgamation_stack_json = CHashArray_get(CAmalgamation_internal_stack_json,-1);
    }

}

void CAmalgamator_plot_json(int line){
    dtw_write_long_file_content("plotage.txt",CAmalgamation_total_plotage);
    CAmalgamation_total_plotage+=1;

    CAmalgamator_start();
    if(CAmalgamation_total_plotage < CAmalgamator_min_plotage){
   
        return;
    }

    if(CAmalgamation_total_plotage > CAmalgamator_max_plotage && CAmalgamator_max_plotage != -1){
        return;
    }


    char *content = CHash_dump_to_json_string(CAmalgamation_internal_stack_json);
    char path[sizeof(CAMALGAMATION_PLOTAGE_FOLDER) + 200] = {0};
    sprintf(path,"%s/%d:%s:%d.json",CAMALGAMATION_PLOTAGE_FOLDER,CAmalgamation_total_plotage,CAmalgamation_func_name,line);
    dtw_write_string_file_content(path,content);

    free(content);
}


CHashArray * convert_string_array_to_chash_object(DtwStringArray *itens){
    CHashArray * created = newCHashArrayEmpty();
    for(int i=0; i< itens->size; i++){
        CHashArray_append_string(created,itens->strings[i]);
    }
    return created;
}
