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

    if (std::stoi(timebuf) == std::stoi(timebuf2))
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

std::vector<std::tm> Date_Operations::returnAllDatesInTheSameWeek(std::tm date)
{
    date.tm_year = date.tm_year-1900;
    date.tm_mon = date.tm_mon-1;
    date.tm_isdst = -1;
    std::mktime(&date);
    char timebuf[64];
    strftime(timebuf, sizeof timebuf, "%V", &date);
    int position_in_week = std::stoi(timebuf);
    int monday_in_week = position_in_week - (position_in_week-1);
    int tuesday_in_week;
    int wednesday_in_week;
    int thursday_in_week;
    int friday_in_week;

    // if(date.tm_mday == 0)
    // {

    // }
    // else if((31 == determineTotalDaysOfMonth(date)) && (31 == date.tm_mday))
    // {

    // }
    // else if((30 == determineTotalDaysOfMonth(date)) && (30 == date.tm_mday))
    // {

    // }
}

std::tm Date_Operations::returnNextDay(std::tm date)
{

}

std::tm Date_Operations::returnPreviousDay(std::tm date)
{

}

bool Date_Operations::isValidDaysInMonth(std::tm date)
{

}

bool Date_Operations::isValidYear(std::tm date)
{
    if(0 < date.tm_yday)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Date_Operations::isLeapYear(std::tm date)
{
    if ( (date.tm_year % 4)  != 0 )
    {
        return false;
    }
    else if ( (date.tm_year % 400)  != 0 )
    {
        return true;
    }
    else if ( (date.tm_year % 100)  == 0 )
    {
        return false;
    }
    else
    {
        return false;
    }
}



int Date_Operations::determineTotalDaysOfMonth(std::tm date)
{
    if(date.tm_mon == 1 || date.tm_mon == 3 || date.tm_mon == 5 || date.tm_mon == 7 || date.tm_mon == 8 ||date.tm_mon == 10 || date.tm_mon == 12)
    {
        return 31;
    }
    else if(date.tm_mon == 2 || date.tm_mon == 4 || date.tm_mon == 6 || date.tm_mon == 9 || date.tm_mon == 11)
    {
        return 30;
    }
    else
    {
        return 0;
    }
}