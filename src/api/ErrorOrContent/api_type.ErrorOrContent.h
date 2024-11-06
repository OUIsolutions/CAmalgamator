
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_const.h"
//silver_chain_scope_end


struct CAmalgamatorErrorOrContent{
    char *content;
    int error;
    char *error_msg;
    char *include_name;
    char *filename;
};
typedef  struct CAmalgamatorErrorOrContent CAmalgamatorErrorOrContent;
