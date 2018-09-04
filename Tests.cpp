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

void Tests::CompareIfTwoDatesAreOnSameWeek()
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

    std::tm second_date{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ""};
    second_date.tm_year = 2018;
    second_date.tm_mon = 9;
    second_date.tm_mday = 5;
    second_date.tm_isdst = -1;
    std::cout << "second_date "<< second_date.tm_year << " " << second_date.tm_mon << " " << second_date.tm_mday << std::endl;

    Date_Operations::compareIfTwoDatesAreOnSameWeek(first_date, second_date);
}

void Tests::ReturnNextAndPreviousDay()
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

    std::tm tomorrow = Date_Operations::returnNextDay(first_date);
    std::cout << "tomorrow "<< tomorrow.tm_year << " " << tomorrow.tm_mon << " " << tomorrow.tm_mday << std::endl;

    std::tm yesterday = Date_Operations::returnPreviousDay(first_date);
    std::cout << "yesterday "<< yesterday.tm_year << " " << yesterday.tm_mon << " " << yesterday.tm_mday << std::endl;
}

void Tests::ReturnNextDayLeapDay()
{
    std::tm date_leap_day{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ""};
    date_leap_day.tm_year = 2020;
    date_leap_day.tm_mon = 1;
    date_leap_day.tm_mday = 28;
    date_leap_day.tm_isdst = -1;
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