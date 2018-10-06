#include "Penalty.hpp"
#include "utilities/File_Accessor.hpp"
#include "utilities/Date_Operations.hpp"
#include "utilities/Regex_Operations.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

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
    // std::cout << "converted_given_date: "<< converted_given_date.tm_year  << " " << converted_given_date.tm_mon << " " << converted_given_date.tm_mday << std::endl;
    // // std::cout << "Start_Date: "<< start_sprint_date.tm_year << " " << start_sprint_date.tm_mon << " " <<  start_sprint_date.tm_mday << std::endl;
    // // std::cout << "End_Date: "<< end_sprint_date.tm_year << " " << end_sprint_date.tm_mon << " " << end_sprint_date.tm_mday << std::endl;


    std::array<std::tm,5> weekdays_on_the_same_week = Date_Operations::returnAllWeekdaysDatesInTheSameWeek(converted_given_date);
    // for(auto element: weekdays_on_the_same_week)
    // {
    //     std::cout << std::setfill('0');
    //     std::cout << "Check_Date: "<< element.tm_year  << " " << std::setw(2) << element.tm_mon << " " << std::setw(2) << element.tm_mday << std::endl;
    // }
    // //File_Accessor::appendToAFile("Sprints/"+sprint.sprint_number+"/"+late_Person.first_Name+"-"+ late_Person.last_Name+".txt", "UNPAID," + date);
    int lates_on_the_same_week_counter = 0;
    int penalty = 0;
    std::vector<std::string> all_my_lates = File_Accessor::returnAllLinesInAFile("Sprints/"+sprint.sprint_number+"/"+late_Person.first_Name+"-"+ late_Person.last_Name+".txt");
    if(all_my_lates.empty())
    {
        std::cout << "NO LATES" << std::endl;
    }
    else
    {
        for(auto element: all_my_lates)
        {
            std::vector<std::string> late = Regex_Operations::splitGivenString(element, ',');
            std::string date_to_be_compared = std::to_string(std::stoi(late.at(1)))+','+std::to_string(std::stoi(late.at(2)))+','+std::to_string(std::stoi(late.at(3)));
            for(auto weekday: weekdays_on_the_same_week)
            {
                //std::to_string(weekday.tm_year) weekday.tm_mon weekday.tm_mday
                //std::cout << "Date to be compared " << date_to_be_compared << std::endl;
                //std::cout << "Date: " << std::to_string(weekday.tm_year) << "," << std::to_string(weekday.tm_mon) <<"," << std::to_string(weekday.tm_mday)<< std::endl;
                if (date_to_be_compared == std::to_string(weekday.tm_year) +","+ std::to_string(weekday.tm_mon) +","+ std::to_string(weekday.tm_mday))
                {
                    //std::cout << "Late Found!" << std::endl;
                    ++lates_on_the_same_week_counter;
                }
            }
        }
        std::cout <<"lates_on_the_same_week_counter: " << lates_on_the_same_week_counter << std::endl;
    }

    switch (lates_on_the_same_week_counter)
    {
        case 0 :
        {
            penalty = 20;
            break;
        }
        case 1 :
        {
            penalty = 30;
            break;
        }
        case 2 :
        {
            penalty = 40;
            break;
        }
        case 3 :
        {
            penalty = 50;
            break;
        }
        case 4 :
        {
            penalty = 60;
            break;
        }
    }
    std::cout << "penalty: " << penalty << std::endl;
    std::string line_to_insert = std::string("UNPAID")+','+date+','+std::to_string(penalty);
    std::cout << "line_to_insert: " << line_to_insert << std::endl;

    File_Accessor::appendToAFile("Sprints/"+sprint.sprint_number+"/"+late_Person.first_Name+"-"+ late_Person.last_Name+".txt",line_to_insert);
    return;
}

int Penalty::countAllPenaltyOnSprint(Person late_Person, Sprint sprint)
{
    int all_penalties_in_sprint = Penalty::countPaidPenaltyOnSprint(late_Person, sprint) + Penalty::countUnpaidPenaltyOnSprint(late_Person, sprint);

    return all_penalties_in_sprint;
}

int Penalty::countPaidPenaltyOnSprint(Person late_Person, Sprint sprint)
{
    int total_Paid_Lates = 0;
    std::vector<std::string> all_Paid_Lates = File_Accessor::returnAllLinesThatStartWith("Sprints/"+sprint.sprint_number+"/"+late_Person.first_Name+"-"+ late_Person.last_Name+".txt", "PAID");

    for(auto paid_late: all_Paid_Lates)
    {
        total_Paid_Lates += std::stoi(Regex_Operations::splitGivenString(paid_late,',').at(4));
    }

    return total_Paid_Lates;

}

int Penalty::countUnpaidPenaltyOnSprint(Person late_Person, Sprint sprint)
{
    int total_Unpaid_Lates = 0;
    std::vector<std::string> all_Unpaid_Lates = File_Accessor::returnAllLinesThatStartWith("Sprints/"+sprint.sprint_number+"/"+late_Person.first_Name+"-"+ late_Person.last_Name+".txt", "UNPAID");

    for(auto unpaid_late: all_Unpaid_Lates)
    {
        total_Unpaid_Lates += std::stoi(Regex_Operations::splitGivenString(unpaid_late,',').at(4));
    }

    return total_Unpaid_Lates;

}
