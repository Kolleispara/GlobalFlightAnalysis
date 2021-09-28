#include "routeGraph.h"
#include <queue>
#include <stack>
#include <fstream>

//lol
class prioQueueObj{
    public:
        std::string nodeName;
        double srcDist;
        
        prioQueueObj(std::string nodeN, double prio){
            nodeName = nodeN;
            srcDist = prio;
        }
};


//below code for priority queue found on
//https://stackoverflow.com/questions/19535644/how-to-use-the-priority-queue-stl-for-objects
bool operator<(const prioQueueObj& lhs, const prioQueueObj& rhs)
{
    //NOTE: we reverse logic here so our prio queue picks the MINIMUM first
    return lhs.srcDist > rhs.srcDist;
}

void routeGraph::allRoutes(int highLim, std::string fileName){
    std::ofstream myfile;
    myfile.open (fileName);
    
    std::vector<std::string> path;
    
    for (auto it = nodeDict.begin(); it != nodeDict.end(); it++)
    {
        if (it->first == "AGF") break;
        for (auto it2 = it; it2 != nodeDict.end(); it2++)
        {
            if (highLim > 0){
                path = aStarExclusion(it->first, it2->first, highLim);
            }
            else{
                path = aStar(it->first, it2->first);
            } 
            for (int i = 0; i < path.size(); i++){
                if (i == path.size() - 1){
                    myfile << path[i] << std::endl;
                    continue;
                }
                myfile << path[i] << " -> ";
            }
            myfile << std::endl;
        }
    }
    
    myfile.close();
    
}

typename std::vector<std::string> routeGraph::aStar(std::string srcAirport, std::string destAirport){
    return aStar(srcAirport, destAirport, true, false, 0, "aStar");
}

/*
aStar exclusion runs aStar, but omits ALL nodes with more than (highLim) edges.
*/

typename std::vector<std::string> routeGraph::aStarExclusion(std::string srcAirport, std::string destAirport, int highLim){
    if (highLim < 0) return aStar(srcAirport, destAirport);
    return aStar(srcAirport, destAirport, true, true, highLim, "aStarExclusion");
}

typename std::vector<std::string> routeGraph::djikstra(std::string srcAirport, std::string destAirport){
    return aStar(srcAirport, destAirport, false, false, 0, "djikstra");
}


typename std::vector<std::string> routeGraph::aStar(std::string srcAirport, std::string destAirport,
                                                 bool useHeur, bool exclusion, int highLim, std::string methodName){

    if (nodeDict.find(srcAirport) == nodeDict.end()){
        std::cout << "Oops, source airport not found!" << std::endl;
        return std::vector<std::string>();
    }
    if (nodeDict.find(destAirport) == nodeDict.end()){
        std::cout << "Oops, destination airport not found!" << std::endl;
        return std::vector<std::string>();
    }
    
    std::map<std::string, std::string> backTrace;
    std::map<std::string, double> pathLength;
    std::priority_queue<prioQueueObj, std::vector<prioQueueObj>> frontier;
    
    frontier.push(prioQueueObj(srcAirport, 0.));
    backTrace[srcAirport] = " ";
    pathLength[srcAirport] = 0.;
    
    int numChecked = 0;
    
    while(frontier.top().nodeName != destAirport){
        //extract our current location...
        numChecked += 1;
        double currDist = frontier.top().srcDist;
        std::string currName = frontier.top().nodeName;
        //std::cout << currName << std::endl;
        
        //If we've found a path that cannot possibly be beat... stop looping!
        if (currName == destAirport) break;
        
        //update the queue
        frontier.pop();
        
        if (nodeDict[currName].edges.size() > highLim && exclusion) {
            if (frontier.empty()){
            std::cout << "No path found between the airports" << std::endl;
            return std::vector<std::string>();
            }
            else continue;
        }
        
        //for EVERY edge from current location...
        for (unsigned i = 0; i < nodeDict[currName].edges.size(); i++){
            std::string nextName = nodeDict[currName].edges[i]->airportName;
            double nextDist = nodeDict[currName].weights[i];
            double heurDist = 0.;
            if (useHeur){
                heurDist = compDist(nextName, destAirport);
            }
            
            
            //If we've seen the node before...
            
            if (backTrace.find(nextName) != backTrace.end()){
                //AND this path is longer than previously seen
                //ignore it. otherwise, reprocess it
                //continue;
                if (pathLength[nextName] <= (pathLength[currName] + nextDist)){
                    //Above, ignore heuristic distance since it's same on both sides
                    continue;
                }
            }
            
            //Now, we process the "new" node:
            backTrace[nextName] = currName;
            pathLength[nextName] = pathLength[currName] + nextDist;
            frontier.push(prioQueueObj(nextName, pathLength[nextName] + heurDist));
        }
    
        if (frontier.empty()){
            std::cout << "No path found between the airports" << std::endl;
            return std::vector<std::string>();
        }
    }
    
    std::cout << "Number of Nodes Checked in " << methodName << ": " << numChecked << std::endl;
    
    //Now, we reverse our path... (since we do a backtrace, we use a stack then load into vector...)
    std::string currPort = destAirport;
    double totalDist = pathLength[destAirport];
    std::stack<std::string> reversePath;
    
    
    while(currPort != srcAirport){
        reversePath.push(currPort);
        currPort = backTrace[currPort];
    }
    
    std::vector<std::string> connectPath;
    
    connectPath.push_back(srcAirport);
    
    while(!reversePath.empty()){
        connectPath.push_back(reversePath.top());
        reversePath.pop();
    }
    
    return connectPath;
}