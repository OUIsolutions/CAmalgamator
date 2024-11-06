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
|  --maxbyte | The max bytes of the final output(optional) | 10mb |
| --maxmega | The max mebagytes of the final output(optional) | 10mb |
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

## Api Usage
