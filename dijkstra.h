#pragma once
// A simple implementation of Dijkstra's Single Source Shortest Path Algorithm using priority queue and adjacency list
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <cfloat>
#include <functional>
#include "routeGraph.h"
// # define INF std::DOUBLE_MAX

// Prints shortest paths from src to all other vertices
class dijkstraSSSP : public routeGraph
{
    private:
        typedef std::pair<std::string, double> myPair; // node in priority queue
        //typedef std::vector<myPair> myContainer;
        class myComp
        {
        public:
            bool operator() (myPair lhs, myPair rhs)
            {
                return lhs.second > rhs.second;
            }
        };
        /* bool myComp (myPair lhs, myPair rhs)
        {
            return lhs.second > rhs.second;
        }; */
       /*  bool myComp =
            [](const myPair& p1, const myPair& p2) 
            { return p1.second > p2.second; }; */
        std::priority_queue<myPair, std::vector<myPair>, myComp> pq;
        /* 
        Create a priority queue to save vertices that need to be preprocessed.
        */
        // std::priority_queue<myPair, vector<myPair>, greater<myPair>> pq;

    public:
        std::map<std::string, double> dijkstra(std::string src);
};