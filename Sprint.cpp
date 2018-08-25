#include <regex>
#include <iostream>

#include "Sprint.hpp"
#include "Utilities/File_Accessor.hpp"

Sprint::Sprint(int sprintnumber)
{
    std::vector<std::string> matchingLine = File_Accessor::getFirstLineMatched("sprint_dates_map.txt", std::to_string(sprintnumber));

    if(matchingLine.front() == "FAILURE")
    {
        std::cout << "SPRINT NUMBER DOES NOT EXIST" << std::endl;
    }
    else
    {
        start_date = matchingLine.at(1) + " " + matchingLine.at(2) + ", " + matchingLine.at(3);
        end_date = matchingLine.at(4) + " " + matchingLine.at(5) + ", " + std::regex_replace(matchingLine.at(6), std::regex("^ +\r\n|\r|\n+"), "$1");
    }
}