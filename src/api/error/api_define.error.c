
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_declare.h"
//silver_chain_scope_end


CAmalgamatorErrorType * Private_newCAmalgamatorType(int error_code,const char *filename){
    CAmalgamatorErrorType * self = (CAmalgamatorErrorType*)malloc(sizeof(CAmalgamatorErrorType));
    self->code = error_code;
    self->filename = NULL;
    if(self->filename){
        self->filename= strdup(filename);
    }
    return  self;
}

void PrivateCAmalgamatorType_free(CAmalgamatorErrorType *self){
    if(self->filename){
        free(self->filename);
    }
    free(self);
}
