all: main

clean:
	rm -f *.o

main: main.o bst.o
	g++ main.o bst.o -o main

main.o: main.cpp
	g++ -c main.cpp

bst.o: bst.cpp
	g++ -c bst.cpp

