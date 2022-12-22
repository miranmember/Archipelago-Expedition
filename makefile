Project6: main.o
	g++ -o Project6 main.o 

main.o: main.cpp island.h
	g++ -c main.cpp