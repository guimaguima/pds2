CC = g++
CFLAGS = -std=c++11 -Wall

all: main

HeapInt.o: HeapInt.hpp HeapInt.cpp 
	$(CC) $(CFLAGS) -c HeapInt.cpp -o HeapInt.o


main: main.o HeapInt.o
	$(CC) $(CFLAGS) main.o HeapInt.o -o main

clean:
	rm -rf *.o 
