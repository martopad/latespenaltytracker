#include <string>

class Person
{
    public:
        Person(std::string Full_Name_Abrv);
        void displayPersonName();
        void displayMyLates(int sprintnumber);
        void displayMyPaidLates(int sprintnumber);
        void displayMyUnpaidLates(int sprintnumber);
    //private:
        std::string full_Name_Abrv = std::string{};
        std::string first_Name = std::string{};
        std::string last_Name = std::string{};
        void fetchFirstLastName();
};