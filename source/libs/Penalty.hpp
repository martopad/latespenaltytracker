#include "Person.hpp"
#include "Sprint.hpp"
#include <string>
#include <vector>
#include <array>
#include <ctime>

class Penalty
{
    public:
        static void giveLatePenalty(Person late_Person, Sprint sprint, std::string date);
        //static int returnLatePenalty(std::vector<std::string> lates_list, std::array<std::tm,5> weekdays_on_the_same_week);
        static int countAllPenaltyOnSprint(Person late_Person, Sprint sprint);
        static int countPaidPenaltyOnSprint(Person late_Person, Sprint sprint);
        static int countUnpaidPenaltyOnSprint(Person late_Person, Sprint sprint);

};