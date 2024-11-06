
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_type1.h"
//silver_chain_scope_end


CAmalgamatorErrorOrContent * Private_new_CAmalgamatorErrorOrString_as_error(int error_code,const char *error_msg,const char *filename);


CAmalgamatorErrorOrContent * Private_new_CAmalgamatorErrorOrString_as_ok(char *content);

void CAmalgamatorErrorOrString_free(CAmalgamatorErrorOrContent *self);
