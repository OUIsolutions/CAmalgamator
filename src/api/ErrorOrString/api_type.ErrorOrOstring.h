
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_const.h"
//silver_chain_scope_end


struct CAmalgamatorErrorOrString{
    bool ok;
    char *content;
    int error_code;
    char *filename;
};
typedef  struct CAmalgamatorErrorOrString CAmalgamatorErrorOrString;
