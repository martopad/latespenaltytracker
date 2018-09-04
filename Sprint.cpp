#include <regex>
#include <iostream>
#include <ctime>
#include <regex>
#include <time.h>

#include "Sprint.hpp"
#include "Utilities/File_Accessor.hpp"
#include "Utilities/Regex_Operations.hpp"
#include "Utilities/Date_Operations.hpp"



Sprint::Sprint(int sprintnumber)
{
    std::vector<std::string> matchingLine = File_Accessor::getFirstLineMatched("sprint_dates_map.txt", std::to_string(sprintnumber));

    if(matchingLine.front() == "FAILURE")
    {
        std::cout << "SPRINT NUMBER DOES NOT EXIST" << std::endl;
    }
    else
    {
        start_date = matchingLine.at(1) + ", " + matchingLine.at(2) + ", " + matchingLine.at(3);
        end_date = matchingLine.at(4) + ", " + matchingLine.at(5) + ", " + std::regex_replace(matchingLine.at(6), std::regex("^ +\r\n|\r|\n+"), "$1");
    }
}

Sprint::Sprint(std::string date_in_sprint)
{
    std::vector<std::string> all_sprints = File_Accessor::returnAllLinesInAFile("sprint_dates_map.txt");
    std::vector<std::string> splitted_given_date = Regex_Operations::splitGivenString(date_in_sprint,',');

    for(int x=0; x<all_sprints.size(); ++x)
    {
        std::vector<std::string> splitted_line = Regex_Operations::splitGivenString(all_sprints.at(x),',');

        std::tm date
                    {
                        0, 0, 0,
                        std::stoi(splitted_given_date.at(2)),
                        std::stoi(splitted_given_date.at(1)),
                        std::stoi(splitted_given_date.at(0)),
                        // 0/*mday*/,
                        // 0/*mon*/,
                        // 0/*year*/,
                        0, 0, -1, 0, ""
                    };

        std::tm start_sprint_date
                    {
                        0, 0, 0,
                        std::stoi(splitted_line.at(3)),
                        std::stoi(splitted_line.at(2)),
                        std::stoi(splitted_line.at(1)),
                        // 0/*mday*/,
                        // 0/*mon*/,
                        // 0/*year*/,
                        0, 0, -1, 0, ""
                    };

        std::tm end_sprint_date
                    {
                        0, 0, 0,
                        std::stoi(splitted_line.at(6)),
                        std::stoi(splitted_line.at(5)),
                        std::stoi(splitted_line.at(4)),
                        // 0/*mday*/,
                        // 0/*mon*/,
                        // 0/*year*/,
                        0, 0, -1, 0, ""
                    };
        // std::cout << "Check_Date: "<< date.tm_year  << " " << date.tm_mon << " " << date.tm_mday << std::endl;
        // std::cout << "Start_Date: "<< start_sprint_date.tm_year << " " << start_sprint_date.tm_mon << " " <<  start_sprint_date.tm_mday << std::endl;
        // std::cout << "End_Date: "<< end_sprint_date.tm_year << " " << end_sprint_date.tm_mon << " " << end_sprint_date.tm_mday << std::endl;


        if(Date_Operations::isDateInRange(date, start_sprint_date, end_sprint_date))
        {
            // std::cout << "Date Found!" << std::endl;
            sprint_number = splitted_line.at(0);
            start_date = splitted_line.at(1) + "," + splitted_line.at(2) + "," + splitted_line.at(3);
            end_date = splitted_line.at(4) + "," + splitted_line.at(5) + "," + std::regex_replace(splitted_line.at(6), std::regex("^ +\r\n|\r|\n+"), "$1");
        }
    }

    if(sprint_number.empty() || start_date.empty() || end_date.empty())
    {
        std::cout << "Date does not exist in sprint list" << std::endl;
    }
}

