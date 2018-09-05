#include "Person.hpp"
#include "Sprint.hpp"
#include <string>

class Penalty
{
    public:
        static void giveLatePenalty(Person late_Person, Sprint sprint, std::string date);

};