CC = g++
main : main.o airportDict.o routeGraph.o astar.o
	$(CC) -o main --std=c++11 main.o airportDict.o routeGraph.o astar.o

main.o : main.cpp airportDict.h
	$(CC) -c  --std=c++11 main.cpp
airportDict.o : airportDict.h airportDict.cpp
	$(CC) -c --std=c++11 airportDict.cpp
routeGraph.o : routeGraph.cpp routeGraph.h
	$(CC) -c --std=c++11 routeGraph.cpp astar.cpp
astar.o : astar.cpp routeGraph.h
	$(CC) -c --std=c++11 astar.cpp

BFS : test_bfs.o bfs.o airportDict.o routeGraph.o
	$(CC) -o BFS --std=c++11 test_bfs.o bfs.o airportDict.o routeGraph.o
bfs.o : bfs.cpp bfs.h
	$(CC) -c --std=c++11 bfs.cpp
test_bfs.o : test_bfs.cpp bfs.h
	$(CC) -c --std=c++11 test_bfs.cpp
	
clean :
	rm main BFS *.o
