#include "Date_Operations.hpp"
#include <iostream>
#include <string>

bool Date_Operations::compareIfTwoDatesAreOnSameWeek(std::tm date1, std::tm date2)
{
    char timebuf[64];
    date1.tm_year = date1.tm_year-1900;
    date1.tm_mon = date1.tm_mon-1;
    //date1.tm_mday = std::stoi(std::regex_replace(tokens.at(2), std::regex("^ +\r\n|\r|\n+"), "$1"));
    date1.tm_isdst = -1;
    std::cout << date1.tm_year << " " << date1.tm_mon << " " << date1.tm_mday << std::endl;
    std::mktime(&date1);
    strftime(timebuf, sizeof timebuf, "%V", &date1);
    std::cout << "date1 " << date1.tm_wday << std::endl;
    std::cout <<"date1 "<< timebuf << std::endl;

    char timebuf2[64];
    date2.tm_year = date2.tm_year-1900;
    date2.tm_mon = date2.tm_mon-1;
    //date1.tm_mday = std::stoi(std::regex_replace(tokens.at(2), std::regex("^ +\r\n|\r|\n+"), "$1"));
    date2.tm_isdst = -1;
    std::cout << date2.tm_year << " " << date2.tm_mon << " " << date2.tm_mday << std::endl;
    std::mktime(&date2);
    strftime(timebuf2, sizeof timebuf2, "%V", &date2);
    std::cout << "date2 " << date2.tm_wday << std::endl;
    std::cout <<"date2 "<< timebuf2 << std::endl;

    if (std::string(timebuf) == std::string(timebuf2))
    {
        std::cout <<"date1 and date2 are on the same week"<< std::endl;
        return true;
    }
    else
    {
        std::cout <<"date1 and date2 are NOT on the same week"<< std::endl;
        return false;
    }
}