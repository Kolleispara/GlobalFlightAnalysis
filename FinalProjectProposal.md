# Final Project Proposal

### Leading Question

Due to the COVID, many large countries have blocked their airports, which has caused great inconvenience to countless people (including one of our team members). We want to use the knowledge learned in the CS225 class to analyze how much impact these measures will have on people's travel. Specifically, we will compare the extra distance or time spent by some people before and after the epidemic with the same place of departure and destination, so as to more intuitively show the inconvenience caused by the epidemic to people's travel.



### Dataset Acquisition and Processing

Our group has elected to use the OpenFlights dataset for our project. We intend to download the .csv file version of the airport database with the air routes database (.dat, but also comma-separated variable) to create a graph containing nodes for each airport and edges representing direct routes between two points, where routes are weighted based on great circle distance (i.e. the flat metric on spherical shell) between the source and destination.  The open flights data will be downloaded as a csv file, where this just means that columns in the data are separated by a comma, and each row represents a different datapoint. The flights data contains information of source airport and destination airport, as well as the carrier, the number of stops, and whether the flight is direct or not. The airport data contains information about the name of the airport, the abbreviations used to signify it, the longitude and latitude, altitude, time zone, the type of airport it is, as well as the data source. As many air routes may contain invalid data, we intend to remove all entries which do not correctly specify a destination or source. Similarly, airports missing longitude, latitude, or an airport identifier will be discarded. Only direct routes will be considered.



### Graph Algorithms

##### Traversal:

BFS

##### Covered Algorithm:

Dijkstra’s Algorithm

##### Complex Algorithm:

A* Search

Our group intends to pursue Djikstra's Algorithm for finding the shortest path as well as A*, which also aims to find the shortest path. Both methods will take in a starting node and a target node and will output a backtrack path telling how to get from the starting node to the output node while minimizing some objective.

For the heuristic distance, we will use great circle distance from a given node to the target, which represents the theoretical minimum cost of getting from one point to the target. This property guarantees that our output will be the shortest possible path, as opposed to an approximation.



### Timeline

| Task                               | Deadline |
| ---------------------------------- | -------- |
| Process the dataset                | April 16 |
| Complete the basic graph structure | April 23 |
| Traversal & Covered Algorithm      | April 30 |
| Complex Algorithm                  | May 7    |
| Debugging                          | May 12   |

