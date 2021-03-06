#include <vector>
#include <sstream>
#include <filesystem>
#include <fstream>
#include <iostream>

#include "File_Accessor.hpp"

std::vector<std::string> File_Accessor::getFirstLineMatched(std::string filePathRelativeToPWD, std::string tokenToMatch)
{
    std::ifstream reader(std::filesystem::current_path().string() +"/"+ filePathRelativeToPWD);
    if(!reader | is_empty(reader))
    {
        //std::cout << "Unable to access: " << std::filesystem::current_path().string() << " " << filePathRelativeToPWD << std::endl ;
        return std::vector<std::string> {};
    }

    std::string line;
    std::vector<std::string> tokens;
    std::string token;

    while(getline(reader, line))
    {
        std::istringstream tokenStream(line);
        while (std::getline(tokenStream, token, ','))
        {
            tokens.push_back(token);
        }
        if(tokens.front() == tokenToMatch)
        {
            return tokens;
        }
        tokens.clear();
    }

    if(tokens.empty())
    {
        std::cout << "Your keyword: " << tokenToMatch << " does not exist in " <<  std::filesystem::current_path().string() << " " << filePathRelativeToPWD << std::endl;
    }
    reader.close();
    return std::vector<std::string> {};
}

std::vector<std::string> File_Accessor::returnAllLinesInAFile(std::string filePathRelativeToPWD)
{
    std::ifstream reader(std::filesystem::current_path().string() +"/"+ filePathRelativeToPWD);
    if(!reader | is_empty(reader))
    {
        //std::cout << "Unable to access: " << std::filesystem::current_path().string() << " " << filePathRelativeToPWD << std::endl ;
        return std::vector<std::string> {};
    }

    std::string line;
    std::vector<std::string> all_lines_in_file;
    while(getline(reader, line))
    {
        all_lines_in_file.push_back(line);
    }

    if(all_lines_in_file.empty())
    {
        reader.close();
        return std::vector<std::string> {"FAILURE"};
    }

    reader.close();
    return all_lines_in_file;
}

int File_Accessor::countNumberOfLines(std::string filePathRelativeToPWD)
{
    std::ifstream reader(std::filesystem::current_path().string() +"/"+ filePathRelativeToPWD);
    if(!reader | is_empty(reader))
    {
        //std::cout <<"Unable to access: " << std::filesystem::current_path().string() << " " << filePathRelativeToPWD << std::endl ;
        return 0;
    }

    std::string line;
    int line_count = 0;
    while(getline(reader, line))
    {
        ++line_count;
    }
    reader.close();
    return line_count;
}

int File_Accessor::countNumberOfLinesThatStartWith(std::string filePathRelativeToPWD, std::string lineStartsWith)
{
    std::ifstream reader(std::filesystem::current_path().string() +"/"+ filePathRelativeToPWD);
    if(!reader | is_empty(reader))
    {
        //std::cout <<"Unable to access: " << std::filesystem::current_path().string() << " " << filePathRelativeToPWD << std::endl ;
        return 0;
    }

    int line_count = 0;
    std::string line;
    std::vector<std::string> tokens;
    std::string token;

    while(getline(reader, line))
    {
        std::istringstream tokenStream(line);
        while (std::getline(tokenStream, token, ','))
        {
            tokens.push_back(token);
        }
        if(tokens.front() == lineStartsWith)
        {
            ++ line_count;
        }
        tokens.clear();
    }
    reader.close();
    return line_count;
}

std::vector<std::string> File_Accessor::returnAllLinesThatStartWith(std::string filePathRelativeToPWD, std::string lineStartsWith)
{
    std::ifstream reader(std::filesystem::current_path().string() +"/"+ filePathRelativeToPWD);
    if(!reader | is_empty(reader))
    {
        //std::cout <<"Unable to access: " << std::filesystem::current_path().string() << " " << filePathRelativeToPWD << std::endl ;
        return std::vector<std::string> {};
    }

    int line_count = 0;
    std::vector<std::string> linesMatched;
    std::string line;
    std::vector<std::string> tokens;
    std::string token;

    while(getline(reader, line))
    {
        std::istringstream tokenStream(line);
        while (std::getline(tokenStream, token, ','))
        {
            tokens.push_back(token);
        }
        if(tokens.front() == lineStartsWith)
        {
            linesMatched.push_back(line);
        }
        tokens.clear();
    }
    reader.close();
    return linesMatched;
}

void File_Accessor::appendToAFile(std::string filePathRelativeToPWD, std::string lineToAppend)
{
    std::ofstream writer;
    //std::ofstream writer(std::filesystem::current_path().string() +"/"+ filePathRelativeToPWD);
    std::cout << "Writing to File: " <<  std::filesystem::current_path().string() <<"/"<< filePathRelativeToPWD << std::endl;
    writer.open( std::filesystem::current_path().string() +"/"+ filePathRelativeToPWD, std::ios::out | std::ios::app );
    if(!writer)
    {
        std::cout <<"Unable to access: " << std::filesystem::current_path().string() << " " << filePathRelativeToPWD << std::endl ;
    }


    writer << lineToAppend << "\n" ;
    writer.close();
}

bool File_Accessor::is_empty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}


