CC=g++
CFLAGS=-std=c++11 -Wall 

all: main
 
empresa.o: Empresa.hpp Empresa.cpp
	${CC} ${CFLAGS} -c Empresa.cpp
 
onibus.o: Onibus.hpp Onibus.cpp
	${CC} ${CFLAGS} -c Onibus.cpp

main.o: Onibus.hpp Empresa.hpp main.cpp
	${CC} ${CFLAGS} -c main.cpp

main: main.o empresa.o onibus.o
    ${CC} ${CFLAGS} main.o empresa.o onibus.o -o main

clean:
rm -rf  main *.o 