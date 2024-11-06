
//#define  CAMALGAMATOR_DEBUG
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.api_define.h"
//silver_chain_scope_end



int main(){
    char *final =  CAmalgamator_generate_amalgamation( "doTheWorld_test/one.c",NULL,NULL);
    dtw_write_string_file_content("saida.c", final);
    free(final);
    return 0;
}
