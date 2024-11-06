rm -rf release
mkdir release
gcc src/cli/main.c -o release/CAmalgamator.o
./release/CAmalgamator.o --file   src/cli/main.c -o release/CAmalgamator.c
./release/CAmalgamator.o --file src/imports/imports.api_define.h  -o release/CAmalgamatorApiOne.h
./release/CAmalgamator.o --file  src/imports/imports.api_define.h  -o release/CAmalgamatorApiNoDependenciesIncluded.h \
--noinclude  dependencies
