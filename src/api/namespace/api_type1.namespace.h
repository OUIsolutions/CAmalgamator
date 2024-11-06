
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_type.h"
//silver_chain_scope_end

struct CAmalgamatorNamesapce{

    CAmalgamatorErrorOrContent * (*generate_amalgamation)(
        const char*filename,
        long max_content_size,
        short (*generator_handler)(const char *filename,const  char *path, void *extra_args),
        void *args
    );
    CAmalgamatorErrorOrContent * (*generate_amalgamation_simple)(const char*filename, long maxcontent_size);

    short DONT_INCLUDE;
    short DONT_CHANGE;
    short INCLUDE_ONCE;
    short INCLUDE_PERPETUAL;
    short FILE_NOT_FOUND;
    short UNEXPECTED_ERROR;
    short NO_ERRORS;
    int ONE_BYTE;
    int  ONE_MB;

    void (*free_error_or_string)(CAmalgamatorErrorOrContent *self);

};
typedef   struct  CAmalgamatorNamesapce CAmalgamatorNamesapce;
