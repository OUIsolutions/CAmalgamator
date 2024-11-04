
#define  CAMALGAMATOR_DEBUG
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.api_define.h"
//silver_chain_scope_end

int main(){

    CAmalgamator_plot();
    CAmalgamation_append("aaa");
    CHashObject_set_string(stack_json,"a","aaa");


    CAmalgamator_plot();
    CAmalgamation_append("aaa");
    CHashObject_set_string(stack_json,"a","aaa");

    CAmalgamation_append("aaa");
    CAmalgamator_plot();

    CAmalgamation_pop();
    CAmalgamation_pop();
    CAmalgamation_pop();

    CAmalgamator_plot();


    CAmalgamator_plot();

    return 0;
    CTextStack *final = newCTextStack_string_empty();
    DtwStringArray *already_included = newDtwStringArray();
    const char *filnemae = "doTheWorld_test/one.c";
    private_CAmalgamator_generate_amalgamation(final,filnemae,already_included);
    dtw_write_string_file_content("saida.c", final->rendered_text);

}
