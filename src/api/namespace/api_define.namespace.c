
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_declare.h"
//silver_chain_scope_end

CAmalgamatorNamesapce newCAmalgamatorNamesapce(){
    CAmalgamatorNamesapce self = {0};
    self.generate_amalgamation = CAmalgamator_generate_amalgamation;
    self.generate_amalgamation_simple = CAmalgamator_generate_amalgamation_simple;
    self.DONT_CHANGE = CAMALGAMATOR_DONT_CHANGE;
    self.DONT_INCLUDE = CAMALGAMATOR_DONT_INCLUDE;
    self.INCLUDE_ONCE = CAMALGAMATOR_INCLUDE_ONCE;
    self.INCLUDE_PERPETUAL= CAMALGAMATOR_INCLUDE_PERPETUAL;
    return self;
}
