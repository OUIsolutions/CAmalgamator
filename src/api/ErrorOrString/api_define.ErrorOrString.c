
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_declare.h"
//silver_chain_scope_end

CAmalgamatorErrorOrString * Private_new_CAmalgamatorErrorOrString_as_error(int error_code,const char *filename){
    CAmalgamatorErrorOrString *self = (CAmalgamatorErrorOrString*)malloc(sizeof(CAmalgamatorErrorOrString*));
    *self = (CAmalgamatorErrorOrString){0};
    self->ok = false;
    self->error_code = error_code;
    self->filename = strdup(filename);
    return  self;
}

CAmalgamatorErrorOrString * Private_new_CAmalgamatorErrorOrString_as_ok(char *content){
    CAmalgamatorErrorOrString *self = (CAmalgamatorErrorOrString*)malloc(sizeof(CAmalgamatorErrorOrString*));
    *self = (CAmalgamatorErrorOrString){0};
    self->ok = true;
    self->content = content; //we take the ownership
    return  self;
}

void CAmalgamatorErrorOrString_free(CAmalgamatorErrorOrString *self){
    if(self->filename){
        free(self->filename);
    }
    if(self->content){
        free(self->content);
    }
    free(self);
}
