
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_declare.h"
//silver_chain_scope_end
#ifdef CAMALGAMATOR_DEBUG

void CAmalgamator_start(){
    if(internal_stack_json == NULL){
        dtw_remove_any(CAMALGAMATION_PLOTAGE_FOLDER);
        internal_stack_json = newCxpathJsonArray();
    }
}

void CAmalgamation_append(const char *func_name){
    newCxpathJsonArray();
    CxpathJson_set_str(internal_stack_json,func_name, "['$append','func_name']");
    stack_json = newCxpathJsonArray();
    CxpathJson_set_xpathJson_getting_onwership(internal_stack_json, stack_json,"[-1,'itens']");

}

void CAmalgamator_plot(){

    CAmalgamator_start();
    if(CAmalgamation_total_plotage < CAmalgamator_min_plotage){
        return;
    }

    if(CAmalgamation_total_plotage > CAmalgamator_max_plotage && CAmalgamator_max_plotage != -1){
        return;
    }

    char *content = CxpathJson_dump_to_string(internal_stack_json,true);
    char path[sizeof(CAMALGAMATION_PLOTAGE_FOLDER) + 10] = {0};
    sprintf(path,"%s/%d.json",CAMALGAMATION_PLOTAGE_FOLDER,CAmalgamation_total_plotage);
    dtw_write_string_file_content(path,content);
    free(content);
    CAmalgamation_total_plotage+=1;
}

#endif
