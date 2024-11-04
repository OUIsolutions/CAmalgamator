
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_declare.h"
//silver_chain_scope_end

#define PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point,char)\
    if(content[point] != char){\
    return false;\
}
#define PRIVATE_CAMALGAMATOR_STR_SIZE(str) (sizeof(str)-1)

bool private_CAmalgamator_is_include_at_point(char *content,int content_size,int point){
    if(point + PRIVATE_CAMALGAMATOR_STR_SIZE("#include") >= content_size){
        return false;
    }
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point,'#')
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point+1,'i')
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point+2,'n')
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point+3,'c')
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point+4,'l')
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point+5,'u')
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point+6,'d')
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point+7,'e')
    return true;
}

bool private_CAmalgamator_is_start_multiline_coment_at_point(char *content,int content_size,int point){
    if(point + PRIVATE_CAMALGAMATOR_STR_SIZE("/*") >= content_size){
        return false;
    }
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point,'/')
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point+1,'*')
    return true;
}

bool private_CAmalgamator_is_end_multiline_coment_at_point(char *content,int content_size,int point){
    if(point + PRIVATE_CAMALGAMATOR_STR_SIZE("*/") >= content_size){
        return false;
    }
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point,'*')
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point+1,'/')
    return true;
}


bool private_CAmalgamator_is_start_inline_coment_at_point(char *content,int content_size,int point){
    if(point + PRIVATE_CAMALGAMATOR_STR_SIZE("//") >= content_size){
        return false;
    }
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point,'/')
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point+1,'/')
    return true;
}
