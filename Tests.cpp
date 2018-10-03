#include <iostream>
#include <string>
#include <regex>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <map>
//#include <filesystem>
//#include <boost/date_time.hpp>
#include "Person.hpp"
#include <vector>
#include "Sprint.hpp"
//#include <boost/filesystem.hpp>
#include <ctime>
#include "Utilities/Date_Operations.hpp"
#include "Tests.hpp"


// std::string return_current_time_and_date()
// {
//     auto now = std::chrono::system_clock::now();
//     auto in_time_t = std::chrono::system_clock::to_time_t(now);
//     std::stringstream ss;
//     //ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
//     ss << std::put_time(std::localtime(&in_time_t), "%Y,%m,%d,%u");

//     return ss.str();
// }

// std::string returnFirstMatch(std::string strToSearch, std::regex pattern)
// {
//     auto words_begin = std::sregex_iterator(strToSearch.begin(), strToSearch.end(), pattern);
//     auto words_end = std::sregex_iterator();
//     std::cout << "Found "
//               << std::distance(words_begin, words_end)
//               << " words\n";
//     std::smatch match = *words_begin;
//     std::string match_str = match.str();
//     return match_str;
// }

// std::vector<std::string> split(const std::string& s, char delimiter)
// {
//   std::vector<std::string> tokens;
//   std::string token;
//   std::istringstream tokenStream(s);
//   while (std::getline(tokenStream, token, delimiter))
//   {
//     tokens.push_back(token);
//   }
//   return tokens;
// }

// enum class Months
// {
//     Jan = 1,
//     Feb = 2,
//     Mar = 3,
//     Apr = 4,
//     May = 5,
//     Jun = 6,
//     Jul = 7,
//     Aug = 8,
//     Sep = 9,
//     Oct = 10,
//     Nov = 11,
//     Dec = 12
// };

// int convertMonthsToInt(Months month)
// {
//     switch(month)
//     {
//         case Months::Jan :
//         {
//             return 1;
//         }
//         case Months::Feb :
//         {
//             return 2;
//         }
//         case Months::Mar :
//         {
//             return 3;
//         }
//         case Months::Apr :
//         {
//             return 4;
//         }
//         case Months::May :
//         {
//             return 5;
//         }
//         case Months::Jun :
//         {
//             return 6;
//         }
//         case Months::Jul :
//         {
//             return 7;
//         }
//         case Months::Aug :
//         {
//             return 8;
//         }
//         case Months::Sep :
//         {
//             return 9;
//         }
//         case Months::Oct :
//         {
//             return 10;
//         }
//         case Months::Nov :
//         {
//             return 11;
//         }
//         case Months::Dec :
//         {
//             return 12;
//         }
//     }

//     return 0;
// }

// std::tm makeDate(int year, Months month, int mday)
// {

//     std::tm date
//             {
//                 0, 0, 0,
//                 mday,
//                 convertMonthsToInt(month),
//                 year,
//                 0, 0, -1, 0, ""
//             };
//     return date;
// }

// bool operator==(const std::tm& lhs, const std::tm& rhs)
// {
//     return (lhs.tm_mday == rhs.tm_mday && lhs.tm_mon == rhs.tm_mon && lhs.tm_year == rhs.tm_year);
// }

// void Tests::CompareIfTwoDatesAreOnSameWeek()
// {
//     std::tm first_date = makeDate(2018, Months::Sep, 5);
//     std::tm second_date =  makeDate(2018, Months::Sep, 6);

//     std::cout << "Testing CompareIfTwoDatesAreOnSameWeek: ";
//     if(Date_Operations::compareIfTwoDatesAreOnSameWeek(first_date, second_date))
//     {
//         std::cout << "Test Passed" << std::endl;
//     }
//     else
//     {
//         std::cout << "Test Failed" << std::endl;
//     }

//     return;
// }

// void Tests::CompareIfTwoDatesOnDifferentMonthsAreOnSameWeek()
// {
//     std::tm first_date = makeDate(2018, Months::Sep, 1);
//     std::tm second_date = makeDate(2018, Months::Aug, 31);

//     std::cout << "Testing CompareIfTwoDatesOnDifferentMonthsAreOnSameWeek: ";
//     if(Date_Operations::compareIfTwoDatesAreOnSameWeek(first_date, second_date))
//     {
//         std::cout << "Test Passed" << std::endl;
//     }
//     else
//     {
//         std::cout << "Test Failed" << std::endl;
//     }

//     return;
// }

// void Tests::CompareIfTwoDatesOnDifferentMonthsLeapYearAreOnSameWeek()
// {
//     std::tm first_date = makeDate(2020, Months::Feb, 29);
//     std::tm second_date = makeDate(2020, Months::Mar, 1);

//     std::cout << "Testing CompareIfTwoDatesOnDifferentMonthsLeapYearAreOnSameWeek: ";
//     if(Date_Operations::compareIfTwoDatesAreOnSameWeek(first_date, second_date))
//     {
//         std::cout << "Test Passed" << std::endl;
//     }
//     else
//     {
//         std::cout << "Test Failed" << std::endl;
//     }

//     return;
// }

// void Tests::CompareIfTwoDatesOnDifferentYearsAreOnSameWeek()
// {
//     std::tm first_date = makeDate(2018, Months::Dec, 31);
//     std::tm second_date = makeDate(2019, Months::Jan, 1);

//     std::cout << "Testing CompareIfTwoDatesOnDifferentYearsAreOnSameWeek: ";
//     if(Date_Operations::compareIfTwoDatesAreOnSameWeek(first_date, second_date))
//     {
//         std::cout << "Test Passed" << std::endl;
//     }
//     else
//     {
//         std::cout << "Test Failed" << std::endl;
//     }

//     return;
// }

// void Tests::CompareIfTwoDatesAreNotOnTheSameWeek()
// {
//     std::tm first_date = makeDate(2018, Months::Sep, 2);
//     std::tm second_date = makeDate(2018, Months::Sep, 3);

//     std::cout << "Testing CompareIfTwoDatesAreNotOnTheSameWeek: ";
//     if(!Date_Operations::compareIfTwoDatesAreOnSameWeek(first_date, second_date))
//     {
//         std::cout << "Test Passed" << std::endl;
//     }
//     else
//     {
//         std::cout << "Test Failed" << std::endl;
//     }

//     return;
// }


// void Tests::ReturnNextAndPreviousDay()
// {
//     std::tm date = makeDate(2018,Months::Sep,3);
//     std::tm expected_next_day = makeDate(2018,Months::Sep,4);
//     std::tm expected_previous_day = makeDate(2018,Months::Sep,2);

//     std::cout << "Testing CompareIfTwoDatesAreNotOnTheSameWeek: ";
//     if(expected_next_day.tm_mday == Date_Operations::returnNextDay(date).tm_mday && expected_previous_day.tm_mday == Date_Operations::returnPreviousDay(date).tm_mday)
//     {
//         std::cout << "Test Passed" << std::endl;
//     }
//     else
//     {
//         std::cout << "Test Failed" << std::endl;
//     }

// }

// void Tests::ReturnNextDayLeapDay()
// {
//     std::tm date_leap_day = makeDate(2020,Months::Feb,28);
//     std::tm expected_next_day = makeDate(2020,Months::Feb,29);
//     std::tm expected_next_next_day = makeDate(2020,Months::Mar,1);

//     std::cout << "Testing ReturnNextDayLeapDay: ";
//     if(expected_next_day == Date_Operations::returnNextDay(date_leap_day) && expected_next_next_day == Date_Operations::returnNextDay(Date_Operations::returnNextDay(date_leap_day)))
//     {
//         std::cout << "Test Passed" << std::endl;
//     }
//     else
//     {
//         std::cout << "Test Failed" << std::endl;
//     }
// }

// void Tests::ReturnPreviousDayAfterLeapDay()
// {
//     std::tm day_after_leap_day = makeDate(2020,Months::Mar,1);
//     std::tm expected_previous_day = makeDate(2020,Months::Feb,29);

//     std::cout << "Testing ReturnPreviousDayAfterLeapDay: ";
//     if(expected_previous_day == Date_Operations::returnPreviousDay(day_after_leap_day))
//     {
//         std::cout << "Test Passed" << std::endl;
//     }
//     else
//     {
//         std::cout << "Test Failed" << std::endl;
//     }
// }

// void Tests::ReturnPreviousDayNonLeapDay()
// {
//     std::tm day_after_non_leap_day = makeDate(2019,Months::Mar,1);
//     std::tm expected_previous_day = makeDate(2019,Months::Feb,28);

//     std::cout << "Testing ReturnPreviousDayNonLeapDay: ";
//     if(expected_previous_day == Date_Operations::returnPreviousDay(day_after_non_leap_day))
//     {
//         std::cout << "Test Passed" << std::endl;
//     }
//     else
//     {
//         std::cout << "Test Failed" << std::endl;
//     }
// }

// void Tests::ReturnAllWeekdaysInTheSameWeek()
// {
//     std::tm date = makeDate(2018,Months::Sep,5);
//     std::tm expected_monday = makeDate(2018,Months::Sep,3);
//     std::tm expected_tuesday = makeDate(2018,Months::Sep,4);
//     std::tm expected_wednesday = makeDate(2018,Months::Sep,5);
//     std::tm expected_thursday = makeDate(2018,Months::Sep,6);
//     std::tm expected_friday = makeDate(2018,Months::Sep,7);

//     std::cout << "Testing ReturnAllWeekdaysInTheSameWeek: ";
//     std::array<std::tm,5> actual_weekdays = Date_Operations::returnAllWeekdaysDatesInTheSameWeek(date);
//     if(       expected_monday == actual_weekdays[0] && expected_tuesday == actual_weekdays[1]
//         && expected_wednesday == actual_weekdays[2] && expected_thursday == actual_weekdays[3]
//         && expected_friday == actual_weekdays[4] )
//     {
//         std::cout << "Test Passed" << std::endl;
//     }
//     else
//     {
//         std::cout << "Test Failed" << std::endl;
//     }
// }

// void Tests::DateGivenExistInSprintList()
// {
//     std::cout << "Testing DateGivenExistInSprintList: ";
//     Sprint sprint("2018,05,17");

//     if("1806" == sprint.sprint_number && "2018,05,16" == sprint.start_date && "2018,06,12" == sprint.end_date)
//     {
//         std::cout << "Test Passed" << std::endl;
//     }
//     else
//     {
//         std::cout << "Test Failed" << std::endl;
//     }
// }

// void Tests::DateGivenDoestExistInSprintList()
// {
//     std::cout << "Testing DateGivenDoestExistInSprintList: ";
//     Sprint sprint("2018,05,15");

//     if(sprint.sprint_number.empty() && sprint.start_date.empty() && sprint.end_date.empty())
//     {
//         std::cout << "Test Passed" << std::endl;
//     }
//     else
//     {
//         std::cout << "Test Failed" << std::endl;
//     }
// }
