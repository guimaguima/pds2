CC = g++
CFLAGS = -std=c++11 -Wall

all: main

aluno.o: aluno.hpp aluno.cpp 
	$(CC) $(CFLAGS) -c aluno.cpp -o aluno.o

main.o: aluno.hpp main.cpp 
	$(CC) $(CFLAGS) -c main.cpp -o main.o

main: main.o aluno.o
	$(CC) $(CFLAGS) main.o aluno.o -o main

clean:
	rm -rf *.o 
