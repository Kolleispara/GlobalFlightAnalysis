#include <iostream>
#include <ctime>
#include "csvfile.h"
#include "bfs.h"
#include "testData.h"

int main(){

    struct testDataInput testData[] = {
        { "ORD", "Chicago O'Hare International Airport","United States", "DEN", "Denver International Airport","United States" },
        { "ORD", "Chicago O'Hare International Airport","United States", "SAF", "Santa Fe Municipal Airport","United States" },
        { "ORD", "Chicago O'Hare International Airport","United States", "BUR", "Bob Hope Airport","United States" },
        { "ORD", "Chicago O'Hare International Airport","United States", "BOB", "Bora Bora Airport","French Polynesia" },
        { "ORD", "Chicago O'Hare International Airport","United States", "HRI", "Mattala Rajapaksa International Airport","Sri Lanka" },
        { "ORD", "Chicago O'Hare International Airport","United States", "PBH", "Paro Airport","Bhutan" },
    };

    csvfile csv("MyTable.csv");
    csv << "Algorithm" << "From airport" << "IATA" << "To airport" << "IATA" << "Connecting Flights" << "Distance" << "Time" << endrow;
    BFS BFSRoutes("data/airports.csv", "data/routes.csv");
    //BFSRoutes.getDests("YTZ");
    std::clock_t    start;
    for (auto it: testData) {
        start = std::clock();
        std::cout << "Connect flight from " << it.fromIATA << " : " << it.fromAirportName << " in " << it.fromCountry << std::endl;
        std::cout << "\tto " << it.toIATA << " : " << it.toAirportName << " in " << it.toCountry << std::endl;
        std::vector<BFS::connAirport> shortestPath = BFSRoutes.findPath(it.fromIATA, it.toIATA);
        std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;

        BFSRoutes.printBFSPath(shortestPath);
        std::cout << "-------------------------------------------------\n\n";
    }
    return 0;
}
