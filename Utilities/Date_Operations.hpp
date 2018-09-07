#include <ctime>
#include <chrono>
#include <vector>
#include <array>

class Date_Operations
{
    public:
        static std::tm formatDate(std::tm date);
        static std::tm revertFormatDate(std::tm date);
        static bool compareIfTwoDatesAreOnSameWeek(std::tm date1, std::tm date2);
        static std::array<std::tm, 5> returnAllWeekdaysDatesInTheSameWeek(std::tm date);
        static int determineTotalDaysOfMonth(std::tm date);
        static std::tm returnNextDay(std::tm date);
        static std::tm returnPreviousDay(std::tm date);
        static bool isValidDaysInMonth(std::tm date);
        static bool isLeapYear(std::tm date);
        static bool isValidYear(std::tm date);
        static int returnPositionInWeek(std::tm date);
        static bool isDateInRange(std::tm check_date, std::tm start_date, std::tm end_date);

    private:

};