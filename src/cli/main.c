
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

    Behaviors  behaviors = {0};

    behaviors.dont_change = newDtwStringArray();
    UniversalGarbage_add(garbage, dtw.string_array.free,  behaviors.dont_change );
    if(collect_flag(cli.entry.get_flag(entry,"nochange | nc",CLI_NOT_CASE_SENSITIVE), behaviors.dont_change)){
            UniversalGarbage_free(garbage);
            return 1;
    }

    behaviors.dont_include = newDtwStringArray();
    UniversalGarbage_add(garbage, dtw.string_array.free,   behaviors.dont_include);
    if(collect_flag(cli.entry.get_flag(entry,"noinclude | ni",CLI_NOT_CASE_SENSITIVE), behaviors.dont_include)){
        UniversalGarbage_free(garbage);
        return 1;
    }

    behaviors.include_perpetual = newDtwStringArray();
    UniversalGarbage_add(garbage, dtw.string_array.free,   behaviors.include_perpetual);
    if(collect_flag(cli.entry.get_flag(entry,"perpetual | p",false), behaviors.include_perpetual)){
        UniversalGarbage_free(garbage);
        return 1;
    }

    CAmalgamatorErrorOrContent *error_or_content = amalgamator.generate_amalgamation(
        cli.flag.get_str(file,0,CLI_NOT_CASE_SENSITIVE),
        generator_handler,
        (void*)&behaviors
    );

    if(error_or_content->error){

    }



    UniversalGarbage_free(garbage);


    return 0;
}
