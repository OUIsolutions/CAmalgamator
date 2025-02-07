
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

    if(!file->exist){
          printf(" entrie  file not provided \n");
          UniversalGarbage_free(garbage);
          return 1;
    }
    if(file->size == 0){
        printf("file flag its empty\n");
        UniversalGarbage_free(garbage);
        return 1;
    }
    char *filename =  cli.flag.get_str(file,0,CLI_NOT_CASE_SENSITIVE);
    CliFlag *output_flag = cli.entry.get_flag(entry,"o | out | output",CLI_NOT_CASE_SENSITIVE);
    if(!output_flag->exist){
        printf("you didint passed the output file\n");
        UniversalGarbage_free(garbage);
        return 1;
    }

    if(output_flag->size == 0){
        printf("output flag its empty\n");
        UniversalGarbage_free(garbage);
        return 1;
    }
    long max_size  = amalgamator.ONE_MB * 100;
    CliFlag *max_bytes = cli.entry.get_flag(entry,"maxbyte",CLI_NOT_CASE_SENSITIVE);
    if(max_bytes->size > 0){
        max_size = cli.flag.get_long(max_bytes,0);
    }
    if(max_size == -1){
        printf("max bytes its not a number\n");
        UniversalGarbage_free(garbage);
        return 1;
    }

    CliFlag *max_mega = cli.entry.get_flag(entry,"maxmega",CLI_NOT_CASE_SENSITIVE);
    if(max_mega->size > 0){
        max_size = cli.flag.get_long(max_mega,0);
    }
    if(max_size == -1){
        printf("max mega its not a number\n");
        UniversalGarbage_free(garbage);
        return 1;
    }

    int max_recursion = 1000;
    CliFlag * max_recursion_flag = cli.entry.get_flag(entry,"maxreq",CLI_NOT_CASE_SENSITIVE);
    if(max_recursion_flag->size > 0){
        max_recursion = cli.flag.get_long(max_recursion_flag,0);
    }

    if(max_recursion == -1){
        printf("max recursin its not a number\n");
        UniversalGarbage_free(garbage);
        return 1;
    }


    char *output_file = cli.flag.get_str(output_flag,0,CLI_NOT_CASE_SENSITIVE);

    Behaviors  behaviors = {0};

    behaviors.dont_change = newDtwStringArray();
    UniversalGarbage_add(garbage, dtw.string_array.free,  behaviors.dont_change );
    collect_flag(cli.entry.get_flag(entry,"nochange | nc",CLI_NOT_CASE_SENSITIVE), behaviors.dont_change);
    
    behaviors.dont_include = newDtwStringArray();
    UniversalGarbage_add(garbage, dtw.string_array.free,   behaviors.dont_include);
    collect_flag(cli.entry.get_flag(entry,"noinclude | ni",CLI_NOT_CASE_SENSITIVE), behaviors.dont_include);
    behaviors.include_perpetual = newDtwStringArray();
    UniversalGarbage_add(garbage, dtw.string_array.free,   behaviors.include_perpetual);
    collect_flag(cli.entry.get_flag(entry,"perpetual | p",false), behaviors.include_perpetual);


    CAmalgamatorErrorOrContent *error_or_content = amalgamator.generate_amalgamation(
          filename,
          max_size,
          max_recursion,
          generator_handler,
          (void*)&behaviors
      );

    UniversalGarbage_add(garbage,amalgamator.free_error_or_string,error_or_content);
    if(error_or_content->error){
        printf("%s\n",error_or_content->error_msg);
        UniversalGarbage_free(garbage);
        return 1;
    }
    dtw.write_string_file_content(output_file,error_or_content->content);
    UniversalGarbage_free(garbage);
    return 0;
}
