// g++-8 -std=c++17 -isystem ../BOOSTEXPERIMENTS/boost_1_67_0/ *.cpp Utilities/*.cpp -pthread -lboost_unit_test_framework -o a.out -lboost_thread -lpthread -lboost_chrono -lboost_system -lboost_date_time -lstdc++fs -L ../BOOSTEXPERIMENTS/boost_1_67_0/stage/lib/#include <iostream>
#include <string>
#include <regex>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <map>
#include <filesystem>
#include <boost/date_time.hpp>
//#include "Person.hpp"
#include <vector>
//#include "Sprint.hpp"
//#include <boost/filesystem.hpp>
#include <ctime>
#include "Utilities/Date_Operations.hpp"
#include "Tests.hpp"
#include "Utilities/File_Accessor.hpp"
#include "Utilities/Regex_Operations.hpp"
#include "Penalty.hpp"


int main()
{
  //UNPAID,2018,08,17
  // std::string date = "2018,08,17";
  // std::string lates = "MY";

  // std::cout << "The Inputted Date: " << date << std::endl;
  // std::cout << "Inputted Lates: " << lates << std::endl;
  // // std::cout << "Greetings, welcome to martin's lates tracker." << std::endl;
  // // std::cout << "Please enter the date that you wish to record the lates to: \"YYYY,MM,DD\"" << std::endl;
  // // std::cin >> date;
  // // std::cout << "Please enter the lates for this date: \"AB,CD,EF,GH\"" << std::endl;
  // // std::cin >> lates;


  // Sprint sprint(date);
  // if(!sprint.sprint_number.empty())
  // {
  //   std::cout <<"Sprint detected, sprint number: "<< sprint.sprint_number << std::endl;
  // }
  // std::vector<std::string> lates_splitted = Regex_Operations::splitGivenString(lates,',');
  // std::cout << "The lates are: " << std::endl;
  // for(auto element: lates_splitted)
  // {
  //   Person latePerson(element);
  //   std::cout << latePerson.full_Name_Abrv << "-" << latePerson.last_Name << "," << latePerson.first_Name << std::endl;
  //   Penalty::giveLatePenalty(latePerson, sprint, date);
  // }

  //std::cout << std::endl;

  // Person latePerson("MY");
  // latePerson.displayPersonName();
  // //1808,2018,07,18,2018,07,18


  // latePerson.displayMyLates(1808);
  // latePerson.displayMyPaidLates(1808);
  // latePerson.displayMyUnpaidLates(1808);




  Tests tester;
  tester.CompareIfTwoDatesAreOnSameWeek();
  tester.CompareIfTwoDatesOnDifferentMonthsAreOnSameWeek();
  tester.CompareIfTwoDatesOnDifferentMonthsLeapYearAreOnSameWeek();
  tester.CompareIfTwoDatesOnDifferentYearsAreOnSameWeek();
  tester.CompareIfTwoDatesAreNotOnTheSameWeek();

  tester.ReturnNextAndPreviousDay();
  tester.ReturnNextDayLeapDay();
  tester.ReturnPreviousDayAfterLeapDay();
  tester.ReturnPreviousDayNonLeapDay();
  tester.ReturnAllWeekdaysInTheSameWeek();
  tester.DateGivenExistInSprintList();
  tester.DateGivenDoestExistInSprintList();


  return 0;
}