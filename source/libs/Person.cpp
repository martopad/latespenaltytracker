#include <iostream>
#include <regex>

#include "Person.hpp"
#include "utilities/File_Accessor.hpp"

Person::Person(std::string Full_Name_Abrv)
{
    full_Name_Abrv = Full_Name_Abrv;
    fetchFirstLastName();
}

void Person::displayPersonName()
{
    std::cout << "My Name is: " << full_Name_Abrv << " - " << first_Name << " - " << last_Name << std::endl;
}

void Person::fetchFirstLastName()
{
    std::vector<std::string> matchingLine = File_Accessor::getFirstLineMatched("listOfNames.txt", full_Name_Abrv);

    if("FAILURE" == matchingLine.front())
    {
        std::cout << "PERSON DOES NOT EXIST" << std::endl;
    }
    else
    {
        first_Name = matchingLine.at(1);
        last_Name = std::regex_replace(matchingLine.at(2), std::regex("^ +\r\n|\r|\n+"), "$1");
    }
}

void Person::displayMyLates(int sprintnumber)
{
    int total_Lates = File_Accessor::countNumberOfLines("Sprints/"+std::to_string(sprintnumber)+"/"+first_Name+"-"+ last_Name+".txt");
    if(0 == total_Lates)
    {
        std::cout << "FILE Doest not exist" << std::endl;
    }
    else
    {
        std::cout << "On sprint: " << sprintnumber << ", my total lates count is " << total_Lates << std::endl;
    }
}

void Person::displayMyPaidLates(int sprintnumber)
{
    int total_Paid_Lates = File_Accessor::countNumberOfLinesThatStartWith("Sprints/"+std::to_string(sprintnumber)+"/"+first_Name+"-"+ last_Name+".txt", "PAID");
    if(0 == total_Paid_Lates)
    {
        std::cout << "FILE Doest not exist" << std::endl;
    }
    else
    {
        std::cout << "On sprint: " << sprintnumber << ", my total PAID lates count is " << total_Paid_Lates << std::endl;
    }
}

void Person::displayMyUnpaidLates(int sprintnumber)
{
    int total_Unpaid_Lates = File_Accessor::countNumberOfLinesThatStartWith("Sprints/"+std::to_string(sprintnumber)+"/"+first_Name+"-"+ last_Name+".txt", "UNPAID");
    if(0 == total_Unpaid_Lates)
    {
        std::cout << "FILE Doest not exist" << std::endl;
    }
    else
    {
        std::cout << "On sprint: " << sprintnumber << ", my total UNPAID lates count is " << total_Unpaid_Lates << std::endl;
    }
}