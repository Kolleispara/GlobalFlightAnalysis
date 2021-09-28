#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>


class airportDict
{
    public:
        
        airportDict(std::string inFile);
        airportDict();
        
        void loadAirports(std::string inFile);
        int airportCount();
        
        std::vector<double> lookup(std::string airport);
        std::vector<std::string> airportList_ID();
        std::vector<std::string> airportList_IAIA();
        
    private:

        // ([latitude(-90 ~ +90), longitude(-180 ~ +180)])
        std::map<std::string, std::vector<double>> coordMap;
        std::map<std::string, std::vector<double>> idMap;

};