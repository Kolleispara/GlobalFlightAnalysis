# Results

### Brief Description

##### Goals:

Our goal for this project is to:

- practice the coding skills we learned in CS 225
- engage in teamwork using github
- implement graph of airports in worlds for civilian flight
- close some large airports to simulate the situation under covid and see how these closures will affect air routes

##### Final Deliverable:

Our final deliverable includes the code files and test cases for the graph structure and three algorithms (BFS, Dijkstra's, A*)

- graph structure: adjacency list
- BFS: queue
- Dijkstra's: priority queue
- A*: priority queue with heuristic distance

### Outcomes & Discoveries

- Observations for BFS:
  - The route with the least connecting flights may not be the shortest
  - Shortest route may have more connecting flights in between, which means it would actually take longer time for passengers to travel along due to flight transfer times
  - It has the extremely useful property that if all of the edges in a graph are unweighted (we don’t care about the distance) then when the first time a node is visited is the path with the fewest connecting flights to that airport from the source airport

- A* is way much faster than Dijkstra's:
  - For a flight from YUL (Montreal) to ORD (Chicago), Dijkstra checks 213 nodes. A* checks 18. They find the same path.
  - For a flight from YUL (Montreal) to PEK (Beijing), Dijkstra checks 3313 nodes. A* checks 82. They find the same path.
  - For a flight from PEK (Beijing) to VDM (Argentina, near antipode of Beijing) Dijkstra checks 755 nodes. A* checks 4602 nodes. They find the same path.
- What happens when we remove all nodes with more than 50 edges:
  - The average and median for a given path become significantly larger
  - There occurs routes with more than 20 stops (flight transfer)
  - The median and mean path distance increases significantly
  - With limited nodes, it is possible to have a flight path going the long way around the globe