
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_declare.h"
//silver_chain_scope_end

CAmalgamatorErrorOrContent * Private_new_CAmalgamatorErrorOrString_as_error(int error_code,const char *error_msg,const char *filename){
    CAmalgamatorErrorOrContent *self = (CAmalgamatorErrorOrContent*)malloc(sizeof(CAmalgamatorErrorOrContent*));
    *self = (CAmalgamatorErrorOrContent){0};
    self->error = error_code;
    self->error_msg = strdup(error_msg);
    self->filename = strdup(filename);
    return  self;
}

CAmalgamatorErrorOrContent * Private_new_CAmalgamatorErrorOrString_as_ok(char *content){
    CAmalgamatorErrorOrContent *self = (CAmalgamatorErrorOrContent*)malloc(sizeof(CAmalgamatorErrorOrContent*));
    *self = (CAmalgamatorErrorOrContent){0};
    self->error = PRIVATE_CAMALGAMATOR_NO_ERRORS;
    self->content = content; //we take the ownership
    return  self;
}

void CAmalgamatorErrorOrString_free(CAmalgamatorErrorOrContent *self){
    if(self->filename){
        free(self->filename);
    }
    if(self->content){
        free(self->content);
    }
    if(self->error_msg){
        free(self->error_msg);
    }

    free(self);
}
