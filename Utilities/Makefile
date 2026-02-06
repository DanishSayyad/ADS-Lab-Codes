all: test

wipe:
	rm -f *.o

test: test.o stack.o queue.o
	g++ test.o queue.o node.o -o test

test.o: test.cpp
	g++ -c test.cpp

stack.o: stack.cpp
	g++ -c stack.cpp

queue.o: queue.cpp
	g++ -c queue.cpp

node.o: node.cpp
	g++ -c node.cpp

clean:
	rm -f test
