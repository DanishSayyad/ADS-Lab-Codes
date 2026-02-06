all: main

clean:
	rm -f *.o

main: main.o emp.o
	g++ main.o emp.o -o main

main.o: main.cpp
	g++ -c main.cpp

emp.o: emp.cpp
	g++ -c emp.cpp
