
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_const.h"
//silver_chain_scope_end
#ifdef CAMALGAMATOR_DEBUG

void CAmalgamator_start();

void CAmalgamation_append(const char *func_name);

void CAmalgamation_pop();

void CAmalgamator_plot_json(double point);

CHashArray * convert_string_array_to_chash_object(DtwStringArray *itens);
#endif
