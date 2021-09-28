#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "airportDict.h"


class routeGraph
{
    public:
    
        routeGraph();
        
        routeGraph(std::string airFile, std::string routeFile);
        
        struct airportNode{
            std::vector<double> weights;
            std::vector<airportNode *> edges;
            std::string airportName;
            
            airportNode(std::string portName){
                airportName = portName;
            }
            airportNode(){}
        };
        
        
        void loadAirports(std::string inFile);
        void loadRoutes(std::string routeFile);
        
        void getDests(std::string airportName);
        
        void allRoutes(int highLim, std::string fileName);
        
        std::vector<std::string> aStar(std::string srcAiport, std::string destAirport);
        
        std::vector<std::string> aStar(std::string srcAiport, std::string destAirport,
                                        bool useHeur, bool exclusion, int highLim, std::string methodName);
        
        std::vector<std::string> aStarExclusion(std::string srcAiport, std::string destAirport,
                                        int highLim);
        
        std::vector<std::string> djikstra(std::string srcAiport, std::string destAirport);
        
        const std::vector<std::pair<airportNode, double>> getEdges(std::string airportName);
        int nodeCount();
        std::map<std::string, airportNode> getnodeDict()
        {
            return nodeDict;
        }

        airportDict getairports()
        {
            return airports;
        }
        
    private:
        airportDict airports;
        std::map<std::string, airportNode> nodeDict;
        
        std::map<std::string, bool> routeExists;
        
        double compDist(std::string port1, std::string port2);

};