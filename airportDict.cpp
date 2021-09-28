#include "airportDict.h"
#include <fstream>  

/*
Helper function to split string on delimiter
*/

std::vector<std::string> split(std::string longString, std::string delimiter){
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
Load airport info into a map from filename specified.
*/

void airportDict::loadAirports(std::string inFile){
  std::string lin;
  std::ifstream myfile;
  myfile.open(inFile, std::ifstream::in);
  if (myfile.is_open())
  {
    //for each line...
    while ( getline (myfile,lin) )
    {
      //split on ','
      std::vector<std::string> hold = split(lin, ",");
      //and add that airport to airport Coords dictionary
      try{
          if (hold[4].size() > 3)
              coordMap[hold[4].substr(1,3)] = std::vector<double>{std::stod(hold[6]), std::stod(hold[7])};
      }
      catch (...) { continue; }
      idMap[hold[0]] = std::vector<double>{std::stod(hold[6]), std::stod(hold[7])};
    }
    myfile.close();
  }
}

/*
Constructs airport Dict from file
*/

airportDict::airportDict(std::string inFile){
    loadAirports(inFile);
}

airportDict::airportDict(){
    coordMap = std::map<std::string, std::vector<double>>();
    idMap = std::map<std::string, std::vector<double>>();
}

/*
Adds contents of file to airportDict
*/

std::vector<double> airportDict::lookup(std::string lookupString){
    //if numeric string, look at openflights ID based map
    if (lookupString[0] < 'A'){
        if (idMap.find(lookupString) == coordMap.end()){
        return std::vector<double> {-191.0, -191.0};
        }
        return idMap[lookupString];
    }
    //otherwise, look at IATA id map
    if (coordMap.find(lookupString) == coordMap.end()){
        return std::vector<double> {-191.0, -191.0};
    }
    return coordMap[lookupString];
}

int airportDict::airportCount()
{
  return coordMap.size();
}

std::vector<std::string> airportDict::airportList_ID()
{
  std::vector<std::string> result;
  for (auto i = idMap.begin(); i != idMap.end(); ++i)
    result.push_back((*i).first);
  return result;
}

std::vector<std::string> airportDict::airportList_IAIA()
{
  std::vector<std::string> result;
  for (auto i = coordMap.begin(); i != coordMap.end(); ++i)
    result.push_back((*i).first);
  return result;
}