// g++-8 -std=c++17 -isystem ../BOOSTEXPERIMENTS/boost_1_67_0/ *.cpp Utilities/*.cpp -pthread -lboost_unit_test_framework -o a.out -lboost_thread -lpthread -lboost_chrono -lboost_system -lboost_date_time -lstdc++fs -L ../BOOSTEXPERIMENTS/boost_1_67_0/stage/lib/#include <iostream>
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
#include "Utilities/File_Accessor.hpp"


int main ()
{
  Person latePerson("MY");
  latePerson.displayPersonName();
  std::string date = "2018";
  //1808,2018,07,18,2018,07,18


  latePerson.displayMyLates(1808);
  latePerson.displayMyPaidLates(1808);
  latePerson.displayMyUnpaidLates(1808);
  Sprint sprint("2018,05,17");
  std::cout << "Sprint Number: "<< sprint.sprint_number << std::endl;
  std::cout << "Sprint Start Date: "<< sprint.start_date << std::endl;
  std::cout << "Sprint End Date: "<< sprint.end_date << std::endl << std::endl;


  //Tests tester;
  //tester.CompareIfTwoDatesAreOnSameWeek();
  //tester.ReturnNextAndPreviousDay();
  //tester.ReturnNextDayLeapDay();
  //tester.ReturnPreviousDayAfterLeapDay();
  //tester.ReturnPreviousDayNonLeapDay();
  //tester.ReturnAllWeekdaysInTheSameWeek();


  return 0;
}