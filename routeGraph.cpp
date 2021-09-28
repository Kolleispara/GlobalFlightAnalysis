#include "routeGraph.h"
#include <fstream>
#include <cmath>

/*
default constructor (mainly used by other classes)
*/
routeGraph::routeGraph()
{
    airports = airportDict();
    nodeDict = std::map<std::string, airportNode>();
    routeExists = std::map<std::string, bool>();
}

/*
Construct graph from airport file and route file
*/

routeGraph::routeGraph(std::string airFile, std::string routeFile){
    loadAirports(airFile);
    loadRoutes(routeFile);
}

void routeGraph::loadAirports(std::string airFile){
    airports.loadAirports(airFile);
}

/*
Helper function to split string on delimiter
*/

std::vector<std::string> spl(std::string longString, std::string delimiter){
      size_t last = 0;
      size_t next = 0;
      std::vector<std::string> splitString;
      //Search for delimiter..., append string from current position and found delimiter
      //to make list of string fragments, split on delimitr
      while ((next = longString.find(delimiter, last)) != std::string::npos) {
         std::string data = longString.substr(last, next-last);
         last = next + 1;
         splitString.push_back(data);
      }
      return splitString;
}

/*
Given longitude and latitude, compute the great circle distance between two pts
Input: airport names
Output: great circle distance
*/

double routeGraph::compDist(std::string port1, std::string port2){
    std::vector<double> ang1 = airports.lookup(port1);
    std::vector<double> ang2 = airports.lookup(port2);

    double pi = 3.14159265;

    double phi1 = ang1[0] * pi / 180.0;
    double phi2 = ang2[0] * pi/ 180.0;
    double dell = (ang2[1] - ang1[1]) * pi / 180.0;
    
    double num1 = cos(phi2) * sin(dell);
    num1 *= num1;
    double num2 = cos(phi1) * sin(phi2) - sin(phi1) * cos(phi2) * cos(dell);
    num2 *= num2;
    double dem = sin(phi1) * sin(phi2) + cos(phi1) * cos(phi2) * cos(dell);

    return 6371000 * fabs(atan2(sqrt(num1 + num2), dem));

}


/*
Load airport info into a map from filename specified.
*/

void routeGraph::loadRoutes(std::string inFile){
  std::string lin;
  std::ifstream myfile;
  myfile.open(inFile, std::ifstream::in);
  if (myfile.is_open())
  {
    //for each line...
    while ( getline (myfile,lin) )
    {
      //split on ','
      std::vector<std::string> hold = spl(lin, ",");


      //and add that airport to airport Coords dictionary

      std::string sourcePort = hold[2];
      std::string destPort = hold[4];

      //check if both airports exist...
      if (airports.lookup(sourcePort)[0] < -180. || airports.lookup(destPort)[0] < -180.){
          continue;
      }

      //check if we have nodes for both, if not, add them
      if (nodeDict.find(sourcePort) == nodeDict.end()){
          nodeDict[sourcePort] = airportNode(sourcePort);
      }
      if (nodeDict.find(destPort) == nodeDict.end()){
          nodeDict[destPort] = airportNode(destPort);
      }

      //add edge
      //add weight
      //only if route doesn't arleady exist! (use map to keep track!!)
      if (routeExists.find(sourcePort + destPort) == routeExists.end()){
          nodeDict[sourcePort].edges.push_back(&nodeDict[destPort]);
          nodeDict[sourcePort].weights.push_back(compDist(sourcePort, destPort));
          routeExists[sourcePort + destPort] = true;
      }

    }
    myfile.close();
  }
}


/*
Adds contents of file to airportDict
*/

void routeGraph::getDests(std::string airportName){
    if (nodeDict.find(airportName) == nodeDict.end()){
        std::cout << "Oops, no destinations found!" << std::endl;
    }
    else{
        for (unsigned i = 0; i < nodeDict[airportName].edges.size(); i++){
            std::cout << nodeDict[airportName].edges[i]->airportName << " , " ;
            std::cout << nodeDict[airportName].weights[i] << std::endl;
        }
    }
}

const std::vector<std::pair<routeGraph::airportNode, double>> routeGraph::getEdges(std::string airportName){
    std::vector<std::pair<airportNode, double>> airportList;
    if (nodeDict.find(airportName) == nodeDict.end()){
        std::cout << "Oops, no destinations found!" << std::endl;
    }
    else{
        for (unsigned i = 0; i < nodeDict[airportName].edges.size(); i++){
            airportList.push_back(std::make_pair(*nodeDict[airportName].edges[i], nodeDict[airportName].weights[i]));
        }
    }
    return airportList;
}

int routeGraph::nodeCount()
{
   return this->airports.airportCount();
}

