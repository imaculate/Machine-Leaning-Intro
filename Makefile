

finds:finds.o
	g++ -g  finds.o -o finds
finds.o: finds.cpp
	g++ -g -c -o finds.o finds.cpp

