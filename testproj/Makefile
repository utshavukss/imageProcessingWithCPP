CC = g++

all: main

main: main.o function.o
	$(CC) -o main main.o function.o

main.o: main.cpp header1.h
	$(CC) -c main.cpp

function.o: function.cpp header1.h
	$(CC) -c function.cpp

clean:
	rm -f main *.o
