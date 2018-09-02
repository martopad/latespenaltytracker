#include <ctime>
#include <chrono>
#include <vector>
#include <array>

class Date_Operations
{
    public:
        static bool compareIfTwoDatesAreOnSameWeek(std::tm date1, std::tm date2);
        static std::vector<std::tm> returnAllDatesInTheSameWeek(std::tm date);
        static int determineTotalDaysOfMonth(std::tm date);
        static std::tm Date_Operations::returnNextDay(std::tm date);
        static std::tm Date_Operations::returnPreviousDay(std::tm date);
        static bool Date_Operations::isValidDaysInMonth(std::tm date);
        static bool Date_Operations::isLeapYear(std::tm date);
        static bool Date_Operations::isValidYear(std::tm date);
    private:
        const static std::array<int,12> days_in_month = {31,28,31,30,31,30,31,31,30,31,30,31};
};