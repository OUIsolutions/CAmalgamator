
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_declare.h"
//silver_chain_scope_end

CAmalgamatorNamesapce newCAmalgamatorNamesapce(){
    CAmalgamatorNamesapce self = {0};
    self.generate_amalgamation = CAmalgamator_generate_amalgamation;
    self.generate_amalgamation_simple = CAmalgamator_generate_amalgamation_simple;
    self.free_error_or_string = CAmalgamatorErrorOrString_free;
    self.DONT_CHANGE = CAMALGAMATOR_DONT_CHANGE;
    self.DONT_INCLUDE = CAMALGAMATOR_DONT_INCLUDE;
    self.INCLUDE_ONCE = CAMALGAMATOR_INCLUDE_ONCE;
    self.INCLUDE_PERPETUAL= CAMALGAMATOR_INCLUDE_PERPETUAL;
    self.FILE_NOT_FOUND = PRIVATE_CAMALGAMATOR_WATING_FILENAME_STRING_START;
    self.UNEXPECTED_ERROR = CAMALGAMATOR_UNEXPECTED_ERROR;
    self.NO_ERRORS = PRIVATE_CAMALGAMATOR_NO_ERRORS;
    self.ONE_KBYTE =CAMALGAMATOR_ONE_KBYTE;
    self.ONE_MB = CAMALGAMATOR_ONE_MB;

    return self;
}
