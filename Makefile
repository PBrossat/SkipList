prog : main.o skipList.o element.o 
	g++ main.o skipList.o element.o -o main

main.o : main.cpp skipList.h element.h
	g++ -g -Wall -c main.cpp -o main.o

skipList.o : skipList.cpp skipList.h element.h
	g++ -g -Wall -c skipList.cpp -o skipList.o

element.o : element.cpp element.h
	g++ -g -Wall -c element.cpp -o element.o

