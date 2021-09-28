#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
#include "bfs.h"

using namespace std;

BFS::BFS(std::string airports, std::string routes) : routeGraph (airports, routes){

}

void BFS::findShortestPath(string srcAirportName, string connAirportName, std::map<std::string, connAirport> &predecessor, std::vector<connAirport> &route) {

    if (srcAirportName == connAirportName) {
        // finish constructing the shortest path
        return;
    }
    if (predecessor.count(connAirportName) <= 0) {
        std::cout << "Error: Cannot find predecessor\n";
        return;
    }

    route.push_back(predecessor[connAirportName]);
    findShortestPath(srcAirportName, predecessor[connAirportName].preIATA, predecessor, route);

}

void BFS::findShortestPath(std::string srcAirportName, std::string destAirportName, std::map<std::string, connAirport> &predecessor, std::vector<connAirport> &route, double distance){

    if (distance >= shortestDist) {
        // this path is longer then the current path
        return;
    }

    route.clear();
    findShortestPath(srcAirportName, destAirportName, predecessor, route);

    std::reverse(route.begin(), route.end());

}

std::vector<BFS::connAirport> BFS::findPath(string srcAirportName, string destAirportName) {
    std::vector<connAirport> route;

    std::map<std::string, bool> visited;
    std::map<std::string, connAirport> predecessor;
    std::map<std::string, double> distance;

    connAirport destAirport;
    airportNode srcAirport(srcAirportName);
    //srcAirport.weights = 0;
    que.push(srcAirport);

    shortestDist = 999999999;
    distance[srcAirportName] = 0;
    visited[srcAirportName] = true;

    while (!que.empty()) {
        airportNode queAirport = que.front();

        que.pop();
        std::string queAirportName = queAirport.airportName;
        if (queAirportName == destAirportName) {
            std::cout << "Reach destination: " << queAirportName << std::endl;
            struct connAirport temp = {queAirportName, "", "", "", 0};
            destAirport = temp;
            findShortestPath(srcAirportName, destAirportName, predecessor, route, distance[destAirportName]);
        }

        std::vector<pair<airportNode, double>> edgeNodes = getEdges(queAirportName);
        for (auto edge: edgeNodes) {
            if (!visited[edge.first.airportName]) {
                visited[edge.first.airportName] = true;
                double dist = distance[queAirportName] + edge.second;
                distance[edge.first.airportName] = dist;
                que.push(edge.first);
                struct connAirport temp = {edge.first.airportName, queAirportName, "", "", dist};
                predecessor[edge.first.airportName] = temp;
            }
        }
    }

    struct connAirport src = {srcAirportName, "", "", "", 0};
    route.insert(route.begin(), src);
    return route;
}

void BFS::printBFSPath(std::vector<connAirport> & path) {

    int i = 0;
    int distance = 0;
    if (path.size() == 0) {
        std::cout << "No flight found\n";
    }

    for (auto it = path.begin(); it != path.end(); ++it) {
        if (i++ == 0) {
            std::cout << "BFS path from : " << it->IATA << std::endl;
        }
        else {
            std::cout << " to : " << it->IATA << ": " << it->totalDist << std::endl;
        }
    }
    //std::cout << "Total distance = " << distance << std::endl;
}
