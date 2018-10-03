// g++-8 -std=c++17 -isystem ../BOOSTEXPERIMENTS/boost_1_67_0/ *.cpp Utilities/*.cpp -pthread -lboost_unit_test_framework -o a.out -lboost_thread -lpthread -lboost_chrono -lboost_system -lboost_date_time -lstdc++fs -L ../BOOSTEXPERIMENTS/boost_1_67_0/stage/lib/
#include <iostream>
#include <string>
#include <regex>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <map>
#include <filesystem>
//#include <boost/date_time.hpp>
//#include "Person.hpp"
#include <vector>
//#include "Sprint.hpp"
//#include <boost/filesystem.hpp>
#include <ctime>
#include "Utilities/Date_Operations.hpp"
// #include "Tests.hpp"
#include "Utilities/File_Accessor.hpp"
#include "Utilities/Regex_Operations.hpp"
#include "Penalty.hpp"


void display_all_lates_for_all_in_sprint()
{
  std::string all_people = "AC,AB,DR,DI,DP,EM,JL,JF,JT,JQ,JE,KT,MR,MY,PC,RM,RL,RT,SS";
  std::vector<std::string> all_people_splitted = Regex_Operations::splitGivenString(all_people,',');
  std::array<int, 6> all_sprints = {1804, 1805, 1806, 1807, 1808, 1809};
  int all_My_Lates = 0;
  int total = 0;
  for(auto person: all_people_splitted)
  {
    Person latePerson(person);
    std::cout << latePerson.first_Name << " " << latePerson.last_Name << " ";
    for(auto sp: all_sprints)
    {
      Sprint sprint(sp);
      all_My_Lates += Penalty::countUnpaidPenaltyOnSprint(person, sprint);
    }
    std::cout << "Total" << ": "<< all_My_Lates << "    ";
    total += all_My_Lates;
    std::cout << std::endl;
    all_My_Lates = 0;
  }
  std::cout << "TOTAL UNCOLLECTED LATES: " << total << std::endl;


}

int main()
{
  /*
  TODO:
    Log Lates
    Payments
      Iterating through sprint folders
      Logging mechanism when payments are made
      Reporting for payments
      Deduction in total collected.
    Duplicate entry detection

  */

 /*
 BUG:
    Days on the same week bug:
      UNPAID,2018,07,30,20
      UNPAID,2018,07,31,30
      (User gets late the next day):
        Expected: UNPAID,2018,08,01,40
        Actual: UNPAID,2018,08,01,30
 */
  //UNPAID,2018,08,17
  // std::string date = "";
  // std::string lates = "";


  // std::cout << "Greetings, welcome to martin's lates tracker." << std::endl;
  // std::cout << "Please enter the date that you wish to record the lates to: \"YYYY,MM,DD\"" << std::endl;
  // std::cin >> date;
  // std::cout << "Please enter the lates for this date: \"AB,CD,EF,GH\"" << std::endl;
  // std::cin >> lates;

  // std::cout << "The Inputted Date: " << date << std::endl;
  // std::cout << "Inputted Lates: " << lates << std::endl;
  // //std::filesystem::create_directories(std::filesystem::current_path().string()+"/Sprints/1809");

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
  //   int all_My_Unpaid_Lates = Penalty::countUnpaidPenaltyOnSprint(latePerson, sprint);
  //   int all_My_Paid_Lates = Penalty::countPaidPenaltyOnSprint(latePerson, sprint);
  //   //all_My_Lates += Penalty::countPaidPenaltyOnSprint(latePerson, sprint);
  //   std::cout << "Unpaid Lates: " << all_My_Unpaid_Lates << " Paid Lates: " << all_My_Paid_Lates << std::endl;
  // }
  std::cout << "Hello World" << std::endl;
  display_all_lates_for_all_in_sprint();

  // std::cout << std::endl;

  // Person latePerson("MY");
  // latePerson.displayPersonName();
  // //1808,2018,07,18,2018,07,18


  // latePerson.displayMyLates(1808);
  // latePerson.displayMyPaidLates(1808);
  // latePerson.displayMyUnpaidLates(1808);




  // Tests tester;
  // tester.CompareIfTwoDatesAreOnSameWeek();
  // tester.CompareIfTwoDatesOnDifferentMonthsAreOnSameWeek();
  // tester.CompareIfTwoDatesOnDifferentMonthsLeapYearAreOnSameWeek();
  // tester.CompareIfTwoDatesOnDifferentYearsAreOnSameWeek();
  // tester.CompareIfTwoDatesAreNotOnTheSameWeek();

  // tester.ReturnNextAndPreviousDay();
  // tester.ReturnNextDayLeapDay();
  // tester.ReturnPreviousDayAfterLeapDay();
  // tester.ReturnPreviousDayNonLeapDay();
  // tester.ReturnAllWeekdaysInTheSameWeek();
  // tester.DateGivenExistInSprintList();
  // tester.DateGivenDoestExistInSprintList();


  return 0;
}