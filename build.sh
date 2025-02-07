rm -rf release
mkdir release
./CAmalgamator001.o --file   src/cli/main.c -o release/CAmalgamator.c
./CAmalgamator001.o --file src/imports/imports.api_define.h  -o release/CAmalgamatorApiOne.h
./CAmalgamator001.o  --file  src/imports/imports.api_define.h  -o release/CAmalgamatorApiNoDependenciesIncluded.h \
--noinclude  dependencies
