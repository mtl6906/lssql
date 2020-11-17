mkdir /usr/include/ls
mkdir /usr/include/ls/sql

cp build/liblssql.so /usr/lib
cp src/ls/sql/*.h /usr/include/ls/sql
