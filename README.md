# Amalgamator
A C amalgamator cli to join all files in one, build to be rich in features
and also provide a api for you to use in your building programs


# Cli Usage
## Install
to use the  cli, just clone the amalgamated c code
```shell
curl -L https://github.com/OUIsolutions/CAmalgamator/releases/download/0.001/CAmalgamator.c  -o CAmalgamator.c
```
then compile the c file with
```shell
gcc CAmalgamator.c -o CAmalgamator.o
```
## Run
than you can run the cli , by:
```shel
./CAmalgamator.o --file your_main.c  -o your_dest_amalgamation.c
```
Aditionaly , you can pass flags to help you in the usage
## Flags
| Flag | Description | Default |
|------|-------------|---------|
| --f, --file | The start file (required) | - |
| --o, --out, output | The dest output(required) | - |
|  --maxbyte | The max bytes of the final output(optional) | 100mb |
| --maxmega | The max mebagytes of the final output(optional) | 100mb |
| --maxreq | The max recursion to be used (optional) | 1000 |
|--nc, --nochange | The files or dirs you dont want to be changed if ocours a **#include** (optional) | - |
|--ni, --noinclude | The files or dirs you dont want to be include if ocours a **#include** (the dif betwen no change,  its that it will be hidded) (optional) | - |
|--p, --perpetual | the files or dir  you will need to include more than one time (double inclusion)  (optional) | - |

### Example of usage of flag
in these case, I want to not include nothing inside dependencies, so i type:
```shel
./CAmalgamator.o --file  src/imports/imports.api_define.h  -o release/CAmalgamatorApiNoDependenciesIncluded.h \
--noinclude  dependencies
```
note that you can pass any  files or dirs  you want in (--noinclude , --nochange,--perpetual )

# Api Usage
you also can use the code into your build programs, using the public api,
for downloading it, just type
```shel
curl -L https://github.com/OUIsolutions/CAmalgamator/releases/download/0.001/CAmalgamatorApiOne.h  -o CAmalgamatorApiOne.h

```

```c
#include "CAmalgamatorApiOne.h"
CAmalgamatorNamesapce amalgamator;

int main(){
    amalgamator = newCAmalgamatorNamesapce();
    const char *entrie  = "src/cli/main.c";

    int max_recursion = 1000;
    int max_size = amalgamator.ONE_MB * 10;
    CAmalgamatorErrorOrContent *error_or_content =amalgamator.generate_amalgamation_simple(
        entrie,
        max_size,
        max_recursion
    );
    if(error_or_content->error){
        printf("%s\n",error_or_content->error_msg);
        amalgamator.free_error_or_string(error_or_content);
        return 1;
    }
    printf("%s",error_or_content->content);
    amalgamator.free_error_or_string(error_or_content);
}

```
## Seleting files, with the generator_callback
with the generator callback you can determine ,the exact type of file  you want to return
based on the code return

```c
#include "CAmalgamatorApiOne.h"

CAmalgamatorNamesapce amalgamator;


short generator_callback(const char *filename,const char *include_name,void *args){
    printf("amalgamated the : %s file with the include %s\n\n",filename,include_name);
    return amalgamator.INCLUDE_ONCE;
}


int main(){
    amalgamator = newCAmalgamatorNamesapce();
    const char *entrie  = "src/cli/main.c";

    int max_recursion = 1000;
    int max_size = amalgamator.ONE_MB * 10;
    void *external_args_you_want_to_use = NULL;
    CAmalgamatorErrorOrContent *error_or_content =amalgamator.generate_amalgamation(
        entrie,
        max_size,
        max_recursion,
        generator_callback,
        external_args_you_want_to_use
    );

    if(error_or_content->error){
        printf("%s\n",error_or_content->error_msg);
        amalgamator.free_error_or_string(error_or_content);
        return 1;
    }
    printf("%s",error_or_content->content);
    amalgamator.free_error_or_string(error_or_content);
}

```

the code return can be betwen
| Namespace | Pure Var | Description |
|------|-------------|---------|
|amalgamator.DONT_INCLUDE|CAMALGAMATOR_DONT_INCLUDE | dont make the inclusion and hide the text of **#include** |
|amalgamator.DONT_CHANGE | CAMALGAMATOR_DONT_CHANGE | dont change the **#include**|
|amalgamator.INCLUDE_ONCE | CAMALGAMATOR_INCLUDE_ONCE| include the content once |
|amalgamator.INCLUDE_PERPETUAL | CAMALGAMATOR_INCLUDE_PERPETUAL| include the content, every time it founds it  |

# Building from scratch
if you want to build the code from scracth clone ,the repo on your machine , than run
```shel
sh install_dependencies.sh
```
than you can build the project with:
```shel
sh build.sh
```
these will generate the releases in the **release** folder

## SilverChain Usage
These project uses CilverChain as dependencie to organize the files,
to use it , download [Silverchain](https://github.com/OUIsolutions/SilverChain) and
run
```shel
sh watch.sh
```
