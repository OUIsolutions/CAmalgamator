
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_type.h"
//silver_chain_scope_end

struct CAmalgamatorNamesapce{
    char * (*generate_amalgamation)(
        const char*filename,
        short (*generator_handler)(const char *filename,const  char *path, void *extra_args),
        void *args
    );
    char * (*generate_amalgamation_simple)(const char*filename);
    short DONT_INCLUDE;
    short DONT_CHANGE;
    short INCLUDE_ONCE;
    short INCLUDE_PERPETUAL;
    short FILE_NOT_FOUND;
    short UNEXPECTED_ERROR;

    void (*free_error)(CAmalgamatorErrorType *self);

};
typedef   struct  CAmalgamatorNamesapce CAmalgamatorNamesapce;
