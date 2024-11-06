rm -rf release
mkdir release
gcc src/cli/main.c -o CAmalgamator.o
./CAmalgamator.o --file   src/cli/main.c -o release/CAmalgamator.c
./CAmalgamator.o --file src/imports/imports.api_define.h  -o release/CAmalgamatorApiOne.h
./CAmalgamator.o --file  src/imports/imports.api_define.h  -o release/CAmalgamatorApiNoDependenciesIncluded.h \
--noinclude  dependencies
