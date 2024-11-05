
//#define  CAMALGAMATOR_DEBUG
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.api_define.h"
#include <stdbool.h>
//silver_chain_scope_end


bool include_teste(const char *filename,const char *path,void *args){
    return true;
}

bool no_change(const char *filename,const char *path,void *args){
    printf("filename: %s path: %s\n",filename,path);
    return true;
}

int main(){
    char *final =  CAmalgamator_generate_amalgamation( "doTheWorld_test/one.c",include_teste,no_change,NULL);
    dtw_write_string_file_content("saida.c", final);
    free(final);
    return 0;
}
