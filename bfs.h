/**
 * @file bfs.h
 */

#pragma once

#include <string>
#include <cmath>
#include <list>
#include <queue>
#include "routeGraph.h"

using namespace std;

/**
 * A breadth-first graph traversal.
 */
class BFS : public routeGraph {
public:
    struct connAirport {
        std::string IATA;
        std::string preIATA;
        std::string airportName;
        std::string country;
        double totalDist;  // from src airport
    };

    BFS(std::string airports, std::string routes);
    std::vector<connAirport> findPath(string srcAirportName, string destAirportName);
    void findShortestPath(string srcAirportName, string destAirportName, std::map<std::string, connAirport> &predecessor, std::vector<connAirport> &shortestPath);
    void findShortestPath(string srcAirportName, string destAirportName, std::map<std::string, connAirport> &predecessor, std::vector<connAirport> &shortestPath, double distance);
    void printBFSPath(std::vector<connAirport> &path);

private:
    std::queue<airportNode> que;
    int shortestDist;
    int numAirport;
};
