
#define  CAMALGAMATOR_DEBUG
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.api_define.h"
//silver_chain_scope_end

int main(){
    #ifdef CAMALGAMATOR_DEBUG
                CAmalgamation_append("main");
    #endif

    CTextStack *final = newCTextStack_string_empty();
    DtwStringArray *already_included = newDtwStringArray();
    const char *filnemae = "doTheWorld_test/one.c";
    private_CAmalgamator_generate_amalgamation(final,filnemae,already_included);
    dtw_write_string_file_content("saida.c", final->rendered_text);
    #ifdef CAMALGAMATOR_DEBUG
                CAmalgamation_pop();
                CAmalgamator_plot_json();
     #endif
     return 0;
}
