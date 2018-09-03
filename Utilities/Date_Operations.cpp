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

std::array<std::tm, 5> Date_Operations::returnAllWeekdaysDatesInTheSameWeek(std::tm date)
{
    std::cout << "received date: "<< date.tm_year << " " << date.tm_mon << " " << date.tm_mday << std::endl;
    std::tm base_date = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ""};
    base_date.tm_year = date.tm_year;
    base_date.tm_mon = date.tm_mon;
    base_date.tm_mday = date.tm_mday;
    std::array<std::tm, 5> weekdays = {base_date,base_date,base_date,base_date,base_date};
    std::tm yesterday_date = base_date;
    std::tm tomorrow_date = base_date;

    int position_in_week = Date_Operations::returnPositionInWeek(date);
    std::cout << "position_in_week " << position_in_week << std::endl;
    weekdays[position_in_week-1] = base_date;

    if(0 == position_in_week && 6 == position_in_week)
    {
        //no lates supposedly during saturdays, and sundays.
    }
    int days_back_to_monday = position_in_week - 1;
    std::cout << "days_back_to_monday " << days_back_to_monday << std::endl;
    for (int x = days_back_to_monday; x > 0; --x)
    {
        std::cout << "x " << x << std::endl;
        yesterday_date = Date_Operations::returnPreviousDay(yesterday_date);
        weekdays[x-1] = yesterday_date;
    }

    int days_to_friday = 5 - position_in_week;
    std::cout << "days_to_friday " << days_to_friday << std::endl;
    for (int x = position_in_week; x < 5; ++x)
    {
        std::cout << "x " << x << std::endl;
        tomorrow_date = Date_Operations::returnNextDay(tomorrow_date);
        weekdays[x] = tomorrow_date;
    }
    return weekdays;
}

int Date_Operations::returnPositionInWeek(std::tm date)
{
    // std::tm base_date = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ""};
    // base_date = date;
    // base_date.tm_year -= 1900;
    // std::cout <<"base_date " << base_date.tm_year << " " << base_date.tm_mon << " " << base_date.tm_mday << std::endl;

    // // date.tm_year = date.tm_year-1900;
    // // date.tm_mon = date.tm_mon-1;
    // // date.tm_isdst = -1;
    // // std::mktime(&date);
    // // char timebuf[64];
    // // strftime(timebuf, sizeof timebuf, "%V", &date);
    // // int position_in_week = std::stoi(timebuf);
    // // return position_in_week;

    // // date.tm_mon = (date.tm_mon + 9) % 12;
    // // date.tm_year -= date.tm_mon / 10;
    // // int pos_week = 365*date.tm_year + date.tm_year/4 - date.tm_year/100 + date.tm_year/400 + (date.tm_mon*306 + 5)/10 + (date.tm_mday - 1);


    char timebuf2[64];
    date.tm_year = date.tm_year-1900;
    date.tm_mon = date.tm_mon-1;
    //date1.tm_mday = std::stoi(std::regex_replace(tokens.at(2), std::regex("^ +\r\n|\r|\n+"), "$1"));
    date.tm_isdst = -1;
    std::cout << date.tm_year << " " << date.tm_mon << " " << date.tm_mday << std::endl;
    std::mktime(&date);
    strftime(timebuf2, sizeof timebuf2, "%u", &date);
    std::cout << "date " << date.tm_wday << std::endl;
    std::cout <<"date "<< timebuf2 << std::endl;

    return std::stoi(timebuf2);

    // // return pos_week;

    // // std::tm time_in = { 0, 0, 0, // second, minute, hour
    // //   9, 10, 2016 - 1900 }; // 1-based day, 0-based month, year since 1900

    // std::time_t time_temp = std::mktime(&base_date);

    // //Note: Return value of localtime is not threadsafe, because it might be
    // // (and will be) reused in subsequent calls to std::localtime!
    // //const std::tm * time_out = std::localtime(&time_in);
    // const std::tm time_out = *std::localtime(&time_temp);
    // //Sunday == 0, Monday == 1, and so on ...
    // std::cout << "Today is this day of the week: " << time_out.tm_wday << "\n";
    // return time_out.tm_wday;

    // constexpr int DAYS_PER_WEEK = 7 ;

    // const int wday = date.tm_wday ;
    // const int delta = wday ? wday-1 : DAYS_PER_WEEK-1 ;
    // return ( date.tm_yday + DAYS_PER_WEEK - delta ) / DAYS_PER_WEEK ;
}


std::tm Date_Operations::returnNextDay(std::tm date)
{
    std::tm next_day = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ""};
    const static std::array<int,12> days_in_month = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(1 == date.tm_mon && 28 == date.tm_mday && isLeapYear(date))
    {
        next_day.tm_year = date.tm_year;
        next_day.tm_mon = date.tm_mon;
        next_day.tm_mday = date.tm_mday + 1;
        return next_day;
    }
    else if(11 == date.tm_mon && date.tm_mday + 1 > days_in_month[date.tm_mon])
    {
        next_day.tm_year = date.tm_year + 1;
        next_day.tm_mon = 0;
        next_day.tm_mday = 1;
        return next_day;
    }
    else if(date.tm_mday + 1 > days_in_month[date.tm_mon])
    {
        next_day.tm_year = date.tm_year;
        next_day.tm_mon = date.tm_mon + 1;
        next_day.tm_mday = 1;
        return next_day;
    }
    else
    {
        next_day.tm_year = date.tm_year;
        next_day.tm_mon = date.tm_mon;
        next_day.tm_mday = date.tm_mday + 1;
        return next_day;
    }
}

std::tm Date_Operations::returnPreviousDay(std::tm date)
{
    std::tm previous_day = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ""};
    const static std::array<int,12> days_in_month = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(2 == date.tm_mon && 1 == date.tm_mday && isLeapYear(date))
    {
        previous_day.tm_year = date.tm_year;
        previous_day.tm_mon = 1;
        previous_day.tm_mday = 29;
        return previous_day;
    }
    else if(1 == date.tm_mon && 0 == date.tm_mday)
    {
        previous_day.tm_year = date.tm_year - 1;
        previous_day.tm_mon = 11;
        previous_day.tm_mday = 31;
        return previous_day;
    }
    else if(1 == date.tm_mday)
    {
        previous_day.tm_year = date.tm_year;
        previous_day.tm_mon = date.tm_mon - 1;
        previous_day.tm_mday = days_in_month[previous_day.tm_mon];
        return previous_day;
    }
    else
    {
        previous_day.tm_year = date.tm_year;
        previous_day.tm_mon = date.tm_mon;
        previous_day.tm_mday = date.tm_mday - 1;
        return previous_day;
    }

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