#include "routeGraph.h"
#include <iostream>

int main(){

    //Tests for airport list. Will show longitude and latitude of an airport
    std::cout << "Airport Longitude and Latitute" << std::endl<< std::endl;
    
    airportDict fullList("data/airports.csv");
    std::cout << "Trudeau Airport: " << fullList.lookup("YUL")[0] << ", "
    << fullList.lookup("YUL")[1] << std::endl;
    std::cout << "YYZ: " << fullList.lookup("YYZ")[0] << ", "
    << fullList.lookup("YYZ")[1] << std::endl;
    std::cout << "YTZ: " << fullList.lookup("YTZ")[0] << ", "
    << fullList.lookup("YTZ")[1] << std::endl;
    std::cout << "JFK: " << fullList.lookup("JFK")[0] << ", "
    << fullList.lookup("JFK")[1] << std::endl;
    std::cout << "PEK: " << fullList.lookup("PEK")[0] << ", "
    << fullList.lookup("PEK")[1] << std::endl;
    std::cout << "ID 1: " << fullList.lookup("1")[0] << ", "
    << fullList.lookup("1")[1] << std::endl;
    
    
    std::cout << "-------------------------------------------------" << std::endl << std::endl;
    
    
    
    routeGraph fullGraph("data/airports.csv", "data/routes.csv");
    std::cout << "Airport Edges Test" << std::endl<< std::endl;
    //Tests for airport nodes. Will show edges (flights) from airport
    //along with distances. These can be checked
    std::cout << std::endl;
    std::cout << "Distances for flights from YTZ" << std::endl;
    std::cout << std::endl;
    fullGraph.getDests("YTZ");
    
    std::cout << std::endl;
    std::cout << "Distances for flights from YYZ" << std::endl;
    std::cout << std::endl;
    fullGraph.getDests("YYZ");
    
    std::cout << std::endl;
    std::cout << "Distances for flights from JFK" << std::endl;
    std::cout << std::endl;
    fullGraph.getDests("JFK");
    
    std::cout << "-------------------------------------------------" << std::endl << std::endl;
    
    //Below, we look at A*
    
    //fullGraph.allRoutes(50, "allRoutes.txt");
    //fullGraph.allRoutes(-1, "allRoutes.txt");
    
    //Below, we can see tests for aStar and Djikstra
    //Confirm that aStar searches fewer nodes
    //Confirm that flight paths exist
    
    //Below, we look at A*
    
    std::cout << "A-Star Path Tests" << std::endl;
    
    std::cout << "Best Path from YUL to CMI" << std::endl<< std::endl;
    std::vector<std::string>  path = fullGraph.aStar("YUL", "CMI");
    for (int i = 0; i < path.size(); i++){
        if (i == path.size() - 1){
            std::cout << path[i] << std::endl;
            continue;
        }
        std::cout << path[i] << " -> ";
    }
    
    std::cout << "Best Path from YUL to PEK" << std::endl;
    path = fullGraph.aStar("YUL", "PEK");
    for (int i = 0; i < path.size(); i++){
        if (i == path.size() - 1){
            std::cout << path[i] << std::endl;
            continue;
        }
        std::cout << path[i] << " -> ";
    }
    
    std::cout << "Best Path from PEK to VDM" << std::endl;
    path = fullGraph.aStar("PEK", "VDM");
    for (int i = 0; i < path.size(); i++){
        if (i == path.size() - 1){
            std::cout << path[i] << std::endl;
            continue;
        }
        std::cout << path[i] << " -> ";
    }
    
    std::cout << "Best Path from AXT to VDM" << std::endl;
    path = fullGraph.aStar("AXT", "VDM");
    for (int i = 0; i < path.size(); i++){
        if (i == path.size() - 1){
            std::cout << path[i] << std::endl;
            continue;
        }
        std::cout << path[i] << " -> ";
    }
    
    std::cout << "Best Path from MMY to AGT" << std::endl;
    path = fullGraph.aStar("MMY", "AGT");
    for (int i = 0; i < path.size(); i++){
        if (i == path.size() - 1){
            std::cout << path[i] << std::endl;
            continue;
        }
        std::cout << path[i] << " -> ";
    }
    
    std::cout << "Best Path from OLP to AGT" << std::endl;
    path = fullGraph.aStar("OLP", "AGT");
    for (int i = 0; i < path.size(); i++){
        if (i == path.size() - 1){
            std::cout << path[i] << std::endl;
            continue;
        }
        std::cout << path[i] << " -> ";
    }
    
    std::cout << "-------------------------------------------------" << std::endl << std::endl;
    
    
    //Below, we look at Djikstra's algorithm
    
    std::cout << "Djikstra's Algorithm Test" << std::endl<< std::endl;
    
    path = fullGraph.djikstra("YUL", "CMI");
    for (int i = 0; i < path.size(); i++){
        if (i == path.size() - 1){
            std::cout << path[i] << std::endl;
            continue;
        }
        std::cout << path[i] << " -> ";
    }
    
    std::cout << "Best Path from YUL to PEK" << std::endl;
    path = fullGraph.djikstra("YUL", "PEK");
    for (int i = 0; i < path.size(); i++){
        if (i == path.size() - 1){
            std::cout << path[i] << std::endl;
            continue;
        }
        std::cout << path[i] << " -> ";
    }
    
    std::cout << "Best Path from PEK to VDM" << std::endl;
    path = fullGraph.djikstra("PEK", "VDM");
    for (int i = 0; i < path.size(); i++){
        if (i == path.size() - 1){
            std::cout << path[i] << std::endl;
            continue;
        }
        std::cout << path[i] << " -> ";
    }
    
    std::cout << "Best Path from AXT to VDM" << std::endl;
    path = fullGraph.djikstra("AXT", "VDM");
    for (int i = 0; i < path.size(); i++){
        if (i == path.size() - 1){
            std::cout << path[i] << std::endl;
            continue;
        }
        std::cout << path[i] << " -> ";
    }
    
    std::cout << "Best Path from MMY to AGT" << std::endl;
    path = fullGraph.djikstra("MMY", "AGT");
    for (int i = 0; i < path.size(); i++){
        if (i == path.size() - 1){
            std::cout << path[i] << std::endl;
            continue;
        }
        std::cout << path[i] << " -> ";
    }
    
    std::cout << "Best Path from OLP to AGT" << std::endl;
    path = fullGraph.djikstra("OLP", "AGT");
    for (int i = 0; i < path.size(); i++){
        if (i == path.size() - 1){
            std::cout << path[i] << std::endl;
            continue;
        }
        std::cout << path[i] << " -> ";
    }
    
    std::cout << "-------------------------------------------------" << std::endl << std::endl;
    
    std::cout << "A* With Edges Removed Test" << std::endl<< std::endl;
    
    std::cout << "Best Path from YUL to CMI" << std::endl;
    path = fullGraph.aStarExclusion("YUL", "CMI", -1);
    for (int i = 0; i < path.size(); i++){
        if (i == path.size() - 1){
            std::cout << path[i] << std::endl;
            continue;
        }
        std::cout << path[i] << " -> ";
    }
    
    std::cout << "Best Path from YUL to PEK" << std::endl;
    path = fullGraph.aStarExclusion("YUL", "PEK", 50);
    for (int i = 0; i < path.size(); i++){
        if (i == path.size() - 1){
            std::cout << path[i] << std::endl;
            continue;
        }
        std::cout << path[i] << " -> ";
    }
    
    std::cout << "Best Path from PEK to VDM" << std::endl;
    path = fullGraph.aStarExclusion("PEK", "VDM", 50);
    for (int i = 0; i < path.size(); i++){
        if (i == path.size() - 1){
            std::cout << path[i] << std::endl;
            continue;
        }
        std::cout << path[i] << " -> ";
    }
    
    std::cout << "Best Path from AXT to VDM" << std::endl;
    path = fullGraph.aStarExclusion("AXT", "VDM", 50);
    for (int i = 0; i < path.size(); i++){
        if (i == path.size() - 1){
            std::cout << path[i] << std::endl;
            continue;
        }
        std::cout << path[i] << " -> ";
    }
    
    std::cout << "Best Path from MMY to AGT" << std::endl;
    path = fullGraph.aStarExclusion("MMY", "AGT", 50);
    for (int i = 0; i < path.size(); i++){
        if (i == path.size() - 1){
            std::cout << path[i] << std::endl;
            continue;
        }
        std::cout << path[i] << " -> ";
    }
    
    std::cout << "Best Path from OLP to AGT" << std::endl;
    path = fullGraph.aStarExclusion("OLP", "AGT", 50);
    for (int i = 0; i < path.size(); i++){
        if (i == path.size() - 1){
            std::cout << path[i] << std::endl;
            continue;
        }
        std::cout << path[i] << " -> ";
    }
    
    std::cout << "-------------------------------------------------" << std::endl << std::endl;
}
