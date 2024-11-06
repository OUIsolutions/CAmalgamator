
//#define  CAMALGAMATOR_DEBUG
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.cli_define.h"
//silver_chain_scope_end



int main(int argc, char *argv[]){
    cli = newCliNamespace();
    amalgamator = newCAmalgamatorNamesapce();
    dtw = newDtwNamespace();
    UniversalGarbage *garbage = newUniversalGarbage();
    CliEntry* entry = newCliEntry(argc,argv);
    UniversalGarbage_add(garbage, cli.entry.free, entry);

    CliFlag *file = cli.entry.get_flag(entry,"f | file",CLI_NOT_CASE_SENSITIVE);

    if(file->exist == false){
          printf("you didint passed the entrie file\n");
          UniversalGarbage_free(garbage);
          return 1;
    }
    if(file->size == 0){
        printf("file flag its empty\n");
        UniversalGarbage_free(garbage);
        return 1;
    }

    CliFlag *output_flag = cli.entry.get_flag(entry,"o | out | output",CLI_NOT_CASE_SENSITIVE);
    if(output_flag->exist){
        printf("you didint passed the output file\n");
        UniversalGarbage_free(garbage);
        return 1;
    }

    if(output_flag->size == 0){
        printf("output flag its empty\n");
        UniversalGarbage_free(garbage);
        return 1;
    }


    return 0;
}
