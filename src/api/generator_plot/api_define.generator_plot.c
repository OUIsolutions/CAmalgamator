
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_declare.h"
//silver_chain_scope_end
private_CAmalgamator_plot_start(
    CTextStack * final,
    const char*filename,
    DtwStringArray *already_included_sha_list,
    double index
){
    #ifdef CAMALGAMATOR_DEBUG
        CAmalgamation_append("private_CAmalgamator_generate_amalgamation");
        CHashObject_set_string(CAmalgamation_stack_json, "final",final->rendered_text);
        CHashObject_set_string(CAmalgamation_stack_json,"filename",filename);
        CHashObject_set_any(CAmalgamation_stack_json, "already_included", convert_string_array_to_chash_object(already_included_sha_list));
        CAmalgamator_plot_json(index);
    #endif
}
