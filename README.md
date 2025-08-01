# Amalgamator
A C amalgamator cli to join all files in one, build to be rich in features
and also provide a api for you to use in your building programs


## Releases
| item          | plataform |
|-------        |-----------|
| [CAmalgamator.c](https://github.com/OUIsolutions/CAmalgamator/releases/download/0.0.4/CAmalgamator.c)| Source  |
| [CAmalgamatorApiOne.h](https://github.com/OUIsolutions/CAmalgamator/releases/download/0.0.4/CAmalgamatorApiOne.h)| Source of The Lib  |
| [CAmalgamatorApiNoDependenciesIncluded.h](https://github.com/OUIsolutions/CAmalgamator/releases/download/0.0.4/CAmalgamatorApiNoDependenciesIncluded.h)| Lib without dependenies  |
| [CAmalgamator.out](https://github.com/OUIsolutions/CAmalgamator/releases/download/0.0.4/CAmalgamator.out)| Linux Binary |
| [CAmalgamator64.exe](https://github.com/OUIsolutions/CAmalgamator/releases/download/0.0.4/CAmalgamator64.exe)| Windows 64 Binary |
| [CAmalgamatori32.exe](https://github.com/OUIsolutions/CAmalgamator/releases/download/0.0.4/CAmalgamatori32.exe)| Windows i32 Binary |
| [CAmalgamator.rpm](https://github.com/OUIsolutions/CAmalgamator/releases/download/0.0.4/CAmalgamator.rpm)| fedora/rehl/centos package |
| [CAmalgamator.deb](https://github.com/OUIsolutions/CAmalgamator/releases/download/0.0.4/CAmalgamator.deb)| debian/ubuntu package |


## Cli Usage

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
curl -L https://github.com/OUIsolutions/CAmalgamator/releases/download/0.002/CAmalgamatorApiOne.h  -o CAmalgamatorApiOne.h

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


## Building from Scratch
if you want to build the code from scracth  you need to have [Darwin](https://github.com/OUIsolutions/Darwin) 
installed on versio **0.020** and **Docker** our **Podman** installed on your machine.
After install all dependecies,clone the repo on your machine , than run:
```shel
 darwin run_blueprint build/ --mode folder amalgamation_build alpine_static_build windowsi32_build windowsi64_build rpm_static_build debian_static_build
```