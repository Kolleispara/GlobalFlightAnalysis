# CS 225 Final Project

### Team Members

Yifu Song, Tim Miller, Annica Lao

### Presentation

https://illinois.zoom.us/rec/share/48AruuvXn_pSO2Cn4L8jcGsIpwmZ6WmjXgn-V1kVUzKHrkzxjB9hLcxsLjQ6RDLX.otSmWMp86dR-dpdd 

### Data

##### Data Source:

- OpenFlight: https://openflights.org/data.html airports.dat & airlines.dat

### Code

| Type                          | Source            | Linkage      |
| ----------------------------- | ----------------- | ------------ |
| Basic Graph Structure (node)  | airdict.h&.cpp    | None         |
| Basic Graph Structure (graph) | routeGraph.h&.cpp | airdict.h    |
| Algorithm (BFS)               | BFS.h&.cpp        | routeGraph.h |
| Algorithm (dijkstra)          | astar.cpp         | routeGraph.h |
| Algorithm (A*)                | astar.cpp         | routeGraph.h |
| Test Cases                    | test_BFS.cpp      | BFS.h        |

### Commands

##### Major Commands

| Command          | Output                                                       |
| ---------------- | ------------------------------------------------------------ |
| make             | compile all files and create an executable file "main"       |
| ./main           | run all the test cases for airport, routeGraph, dijkstra, and A* |
| make BFS & ./BFS | compile and run the test cases for BFS                       |

##### Other Commands

**In routeGraph:** 

- routeGraph(path_to_airport_data, path_to_route_data) to create a Graph

- dijkstra(source airport, destination airport) to get the shortest path between two airports using Dijkstra's algorithm

- aStar(source airport, destination airport) to get the shortest path between two airports using A* Algorithm

- aStar(source airport, destination airport, bool useHuer, true, int highLim, string methodName) to get the shortest path between two airports using A* Algorithm when excluding all airports with more than *highLim* edges and choose whether to use the hueristic distance

**In bfs**:

- BFS(airports, routes) to create a BFS traversal through the graph

### Test Cases

We provide a number of test cases for the basic graph structure and each algorithm, you can run "./main" and "./BFS" to see the tests after compiling them

##### In main.cpp:

- Tests for airport list. Shows longitude and latitude of several airports
- Tests for airport nodes. Shows edges (flights) from airports along with distances
- Tests Dijkstra's algorithm with several sources and destinations
- Tests A* algorithm with:
  - full graph
  - graph excluding airports with more than 50 airlines

##### In test_BFS.cpp:

- Tests BFS from airport ORD (Chicago O'Hare International Airport) with different destination

