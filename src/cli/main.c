
//#define  CAMALGAMATOR_DEBUG
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.api_define.h"
//silver_chain_scope_end



int main(){
    //CAmalgamator_max_plotage = -1;
    //CAmalgamator_min_plotage = 0;
    #ifdef CAMALGAMATOR_DEBUG
                CAmalgamation_append("main");
    #endif

    CTextStack *final = newCTextStack_string_empty();
    DtwStringArray *already_included = newDtwStringArray();
    const char *filnemae = "doTheWorld_test/one.c";

    #ifdef CAMALGAMATOR_DEBUG
        CHashObject_set_string(CAmalgamation_stack_json,"final", final->rendered_text);
        CHashObject_set_string(CAmalgamation_stack_json,"fiename", filnemae);
        CHashObject_set_any(CAmalgamation_stack_json, "already_included", convert_string_array_to_chash_object(already_included));
        CAmalgamator_plot_json(1);

    #endif

    private_CAmalgamator_generate_amalgamation(final,filnemae,already_included);
    #ifdef CAMALGAMATOR_DEBUG
            CAmalgamator_plot_json(2);
     #endif
    dtw_write_string_file_content("saida.c", final->rendered_text);
    #ifdef CAMALGAMATOR_DEBUG
                CAmalgamation_pop();
                CAmalgamator_plot_json(2);
     #endif
     return 0;
}
