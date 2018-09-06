#include <string>
#include <regex>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <map>
#include <filesystem>
#include <boost/date_time.hpp>
#include "Person.hpp"
#include <vector>
#include "Sprint.hpp"
//#include <boost/filesystem.hpp>
#include <ctime>
#include "Utilities/Date_Operations.hpp"
#include "Tests.hpp"


std::string return_current_time_and_date()
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    //ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    ss << std::put_time(std::localtime(&in_time_t), "%Y,%m,%d,%u");

    return ss.str();
}

std::string returnFirstMatch(std::string strToSearch, std::regex pattern)
{
    auto words_begin = std::sregex_iterator(strToSearch.begin(), strToSearch.end(), pattern);
    auto words_end = std::sregex_iterator();
    std::cout << "Found "
              << std::distance(words_begin, words_end)
              << " words\n";
    std::smatch match = *words_begin;
    std::string match_str = match.str();
    return match_str;
}

std::vector<std::string> split(const std::string& s, char delimiter)
{
  std::vector<std::string> tokens;
  std::string token;
  std::istringstream tokenStream(s);
  while (std::getline(tokenStream, token, delimiter))
  {
    tokens.push_back(token);
  }
  return tokens;
}

enum class Months
{
    Jan = 1,
    Feb = 2,
    Mar = 3,
    Apr = 4,
    May = 5,
    Jun = 6,
    Jul = 7,
    Aug = 8,
    Sep = 9,
    Oct = 10,
    Nov = 11,
    Dec = 12
};

int convertMonthsToInt(Months month)
{
    switch(month)
    {
        case Months::Jan :
        {
            return 1;
        }
        case Months::Feb :
        {
            return 2;
        }
        case Months::Mar :
        {
            return 3;
        }
        case Months::Apr :
        {
            return 4;
        }
        case Months::May :
        {
            return 5;
        }
        case Months::Jun :
        {
            return 6;
        }
        case Months::Jul :
        {
            return 7;
        }
        case Months::Aug :
        {
            return 8;
        }
        case Months::Sep :
        {
            return 9;
        }
        case Months::Oct :
        {
            return 10;
        }
        case Months::Nov :
        {
            return 11;
        }
        case Months::Dec :
        {
            return 12;
        }
    }

    return 0;
}

std::tm makeDate(int year, Months month, int mday)
{

    std::tm date
            {
                0, 0, 0,
                mday,
                convertMonthsToInt(month),
                year,
                0, 0, -1, 0, ""
            };
    return date;
}

void Tests::CompareIfTwoDatesAreOnSameWeek()
{
    std::tm first_date
                {
                    0, 0, 0,
                    5,
                    9,
                    2018,
                    0, 0, -1, 0, ""
                };

    std::tm second_date
                {
                    0, 0, 0,
                    6,
                    9,
                    2018,
                    0, 0, -1, 0, ""
                };

    std::cout << "Testing CompareIfTwoDatesAreOnSameWeek: ";
    if(Date_Operations::compareIfTwoDatesAreOnSameWeek(first_date, second_date))
    {
        std::cout << "Test Passed" << std::endl;
    }
    else
    {
        std::cout << "Test Failed" << std::endl;
    }

    return;
}

void Tests::CompareIfTwoDatesOnDifferentMonthsAreOnSameWeek()
{
    std::tm first_date
                {
                    0, 0, 0,
                    1,
                    9,
                    2018,
                    0, 0, -1, 0, ""
                };

    std::tm second_date
                {
                    0, 0, 0,
                    31,
                    8,
                    2018,
                    0, 0, -1, 0, ""
                };

    std::cout << "Testing CompareIfTwoDatesOnDifferentMonthsAreOnSameWeek: ";
    if(Date_Operations::compareIfTwoDatesAreOnSameWeek(first_date, second_date))
    {
        std::cout << "Test Passed" << std::endl;
    }
    else
    {
        std::cout << "Test Failed" << std::endl;
    }

    return;
}

void Tests::CompareIfTwoDatesOnDifferentMonthsLeapYearAreOnSameWeek()
{
    std::tm first_date
                {
                    0, 0, 0,
                    29,
                    2,
                    2020,
                    0, 0, -1, 0, ""
                };

    std::tm second_date
                {
                    0, 0, 0,
                    1,
                    3,
                    2020,
                    0, 0, -1, 0, ""
                };

    std::cout << "Testing CompareIfTwoDatesOnDifferentMonthsLeapYearAreOnSameWeek: ";
    if(Date_Operations::compareIfTwoDatesAreOnSameWeek(first_date, second_date))
    {
        std::cout << "Test Passed" << std::endl;
    }
    else
    {
        std::cout << "Test Failed" << std::endl;
    }

    return;
}

void Tests::CompareIfTwoDatesOnDifferentYearsAreOnSameWeek()
{
    std::tm first_date
                {
                    0, 0, 0,
                    31,
                    12,
                    2018,
                    0, 0, -1, 0, ""
                };

    std::tm second_date
                {
                    0, 0, 0,
                    1,
                    1,
                    2019,
                    0, 0, -1, 0, ""
                };

    std::cout << "Testing CompareIfTwoDatesOnDifferentYearsAreOnSameWeek: ";
    if(Date_Operations::compareIfTwoDatesAreOnSameWeek(first_date, second_date))
    {
        std::cout << "Test Passed" << std::endl;
    }
    else
    {
        std::cout << "Test Failed" << std::endl;
    }

    return;
}

void Tests::CompareIfTwoDatesAreNotOnTheSameWeek()
{
    std::tm first_date
                {
                    0, 0, 0,
                    2,
                    9,
                    2018,
                    0, 0, -1, 0, ""
                };

    std::tm second_date
                {
                    0, 0, 0,
                    3,
                    9,
                    2018,
                    0, 0, -1, 0, ""
                };

    std::cout << "Testing CompareIfTwoDatesAreNotOnTheSameWeek: ";
    if(!Date_Operations::compareIfTwoDatesAreOnSameWeek(first_date, second_date))
    {
        std::cout << "Test Passed" << std::endl;
    }
    else
    {
        std::cout << "Test Failed" << std::endl;
    }

    return;
}


void Tests::ReturnNextAndPreviousDay()
{
    std::tm date = makeDate(2018,Months::Sep,3);
    std::tm expected_next_day = makeDate(2018,Months::Sep,4);
    std::tm expected_previous_day = makeDate(2018,Months::Sep,2);

    std::cout << "Testing CompareIfTwoDatesAreNotOnTheSameWeek: ";
    if(expected_next_day.tm_mday == Date_Operations::returnNextDay(date).tm_mday && expected_previous_day.tm_mday == Date_Operations::returnPreviousDay(date).tm_mday)
    {
        std::cout << "Test Passed" << std::endl;
    }
    else
    {
        std::cout << "Test Failed" << std::endl;
    }

}

void Tests::ReturnNextDayLeapDay()
{
    std::tm date_leap_day
            {
                0, 0, 0,
                28,
                1,
                2020,
                0, 0, -1, 0, ""
            };
    std::tm expected_next_day
            {
                0, 0, 0,
                29,
                1,
                2020,
                0, 0, -1, 0, ""
            };
    std::tm expected_next_next_day
            {
                0, 0, 0,
                1,
                2,
                2018,
                0, 0, -1, 0, ""
            };

    // std::tm date_leap_day{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ""};
    // date_leap_day.tm_year = 2020;
    // date_leap_day.tm_mon = 1;
    // date_leap_day.tm_mday = 28;
    // date_leap_day.tm_isdst = -1;
    std::cout << "date_leap_day "<< date_leap_day.tm_year << " " << date_leap_day.tm_mon << " " << date_leap_day.tm_mday << std::endl;
    std::tm next_day_in_leap_year = Date_Operations::returnNextDay(date_leap_day);
    std::cout << "next_day_in_leap_year "<< next_day_in_leap_year.tm_year << " " << next_day_in_leap_year.tm_mon << " " << next_day_in_leap_year.tm_mday << std::endl;
    std::tm next_next_day_in_leap_year = Date_Operations::returnNextDay(next_day_in_leap_year);
    std::cout << "next_next_day_in_leap_year "<< next_next_day_in_leap_year.tm_year << " " << next_next_day_in_leap_year.tm_mon << " " << next_next_day_in_leap_year.tm_mday << std::endl;
}

void Tests::ReturnPreviousDayAfterLeapDay()
{
    std::tm day_after_leap_day{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ""};

    day_after_leap_day.tm_year = 2020;
    day_after_leap_day.tm_mon = 2;
    day_after_leap_day.tm_mday = 1;
    day_after_leap_day.tm_isdst = -1;
    std::cout << "day_after_leap_day "<< day_after_leap_day.tm_year << " " << day_after_leap_day.tm_mon << " " << day_after_leap_day.tm_mday << std::endl;
    std::tm previous_day_after_leap_day = Date_Operations::returnPreviousDay(day_after_leap_day);
    std::cout << "previous_day_after_leap_day "<< previous_day_after_leap_day.tm_year << " " << previous_day_after_leap_day.tm_mon << " " << previous_day_after_leap_day.tm_mday << std::endl;
}

void Tests::ReturnPreviousDayNonLeapDay()
{
    std::tm day_after_non_leap_day{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ""};

    day_after_non_leap_day.tm_year = 2019;
    day_after_non_leap_day.tm_mon = 2;
    day_after_non_leap_day.tm_mday = 1;
    day_after_non_leap_day.tm_isdst = -1;
    std::cout << "day_after_non_leap_day "<< day_after_non_leap_day.tm_year << " " << day_after_non_leap_day.tm_mon << " " << day_after_non_leap_day.tm_mday << std::endl;
    std::tm previous_day_after_non_leap_day = Date_Operations::returnPreviousDay(day_after_non_leap_day);
    std::cout << "previous_day_after_non_leap_day "<< previous_day_after_non_leap_day.tm_year << " " << previous_day_after_non_leap_day.tm_mon << " " << previous_day_after_non_leap_day.tm_mday << std::endl;
}

void Tests::ReturnAllWeekdaysInTheSameWeek()
{
    std::cout <<"The Date today is(std):" << return_current_time_and_date() << std::endl;
    std::string date = return_current_time_and_date();
    std::vector<std::string> tokens = split(date, ',');

    std::tm first_date{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ""};
    first_date.tm_year = std::stoi(tokens.at(0));
    first_date.tm_mon = std::stoi(tokens.at(1));
    first_date.tm_mday = std::stoi(tokens.at(2));
    first_date.tm_isdst = -1;
    first_date.tm_wday = std::stoi(std::regex_replace(tokens.at(3), std::regex("^ +\r\n|\r|\n+"), "$1"));
    std::cout << "first_date "<< first_date.tm_year << " " << first_date.tm_mon << " " << first_date.tm_mday << " " << first_date.tm_wday << std::endl;

    std::array<std::tm,5> weekdays = Date_Operations::returnAllWeekdaysDatesInTheSameWeek(first_date);
    for (int x = 0; x<5; ++x)
    {
        std::cout << "Element " << x << " " << weekdays[x].tm_year << " " <<  weekdays[x].tm_mon << " " <<  weekdays[x].tm_mday << std::endl;
    }
}

void Tests::DateGivenExistInSprintList()
{
    std::cout << "Testing DateGivenExistInSprintList: ";
    Sprint sprint("2018,05,17");

    if("1806" == sprint.sprint_number && "2018,05,16" == sprint.start_date && "2018,06,12" == sprint.end_date)
    {
        std::cout << "Test Passed" << std::endl;
    }
    else
    {
        std::cout << "Test Failed" << std::endl;
    }
}

void Tests::DateGivenDoestExistInSprintList()
{
    std::cout << "Testing DateGivenDoestExistInSprintList: ";
    Sprint sprint("2018,05,15");

    if(sprint.sprint_number.empty() && sprint.start_date.empty() && sprint.end_date.empty())
    {
        std::cout << "Test Passed" << std::endl;
    }
    else
    {
        std::cout << "Test Failed" << std::endl;
    }
}
