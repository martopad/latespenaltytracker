#include <string>

class Sprint
{
    public:
        std::string start_date = {};
        std::string end_date = {};
        std::string sprint_number = {};
        Sprint(int sprintnumber);
        Sprint(std::string date_in_sprint);
};