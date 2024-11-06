
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_type1.h"
//silver_chain_scope_end


CAmalgamatorErrorOrString * Private_new_CAmalgamatorErrorOrString_as_error(int error_code,const char *filename);

CAmalgamatorErrorOrString * Private_new_CAmalgamatorErrorOrString_as_ok(char *content);

void CAmalgamatorErrorOrString_free(CAmalgamatorErrorOrString *self);
