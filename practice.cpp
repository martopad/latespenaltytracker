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


int main ()
{
  Person latePerson("MY");
  latePerson.displayPersonName();
  latePerson.displayMyLates(1808);
  latePerson.displayMyPaidLates(1808);
  latePerson.displayMyUnpaidLates(1808);
  Sprint sprint(1808);
  std::cout << sprint.start_date << std::endl;
  std::cout << sprint.end_date << std::endl << std::endl;

  //Tests tester;
  //tester.CompareIfTwoDatesAreOnSameWeek();
  //tester.ReturnNextAndPreviousDay();
  //tester.ReturnNextDayLeapDay();
  //tester.ReturnPreviousDayAfterLeapDay();
  //tester.ReturnPreviousDayNonLeapDay();
  //tester.ReturnAllWeekdaysInTheSameWeek();


  return 0;
}