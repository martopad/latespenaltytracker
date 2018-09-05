#include "Penalty.hpp"
#include "Utilities/File_Accessor.hpp"
#include "Utilities/Date_Operations.hpp"
#include "Utilities/Regex_Operations.hpp"
#include <iostream>
#include <vector>
#include <string>
void Penalty::giveLatePenalty(Person late_Person, Sprint sprint, std::string date)
{
    //std::cout << "Sprints/"<<sprint.sprint_number<<"/"<<late_Person.first_Name<<"-"<< late_Person.last_Name<<".txt"<< std::endl;
    std::vector<std::string> spltted_date = Regex_Operations::splitGivenString(date, ',');
    std::tm converted_given_date
            {
                0, 0, 0,
                std::stoi(spltted_date.at(2)),
                std::stoi(spltted_date.at(1)),
                std::stoi(spltted_date.at(0)),
                0, 0, -1, 0, ""
            };
    // std::cout << "Check_Date: "<< date.tm_year  << " " << date.tm_mon << " " << date.tm_mday << std::endl;
    // std::cout << "Start_Date: "<< start_sprint_date.tm_year << " " << start_sprint_date.tm_mon << " " <<  start_sprint_date.tm_mday << std::endl;
    // std::cout << "End_Date: "<< end_sprint_date.tm_year << " " << end_sprint_date.tm_mon << " " << end_sprint_date.tm_mday << std::endl;


    std::array<std::tm,5> WeekdaysOnTheSameWeek = Date_Operations::returnAllWeekdaysDatesInTheSameWeek(converted_given_date);
    for(auto element: WeekdaysOnTheSameWeek)
    {
        std::cout << "Check_Date: "<< element.tm_year  << " " << element.tm_mon << " " << element.tm_mday << std::endl;
    }
    //File_Accessor::appendToAFile("Sprints/"+sprint.sprint_number+"/"+late_Person.first_Name+"-"+ late_Person.last_Name+".txt", "UNPAID," + date);
    return;
}
