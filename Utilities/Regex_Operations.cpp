#include <sstream>

#include "Regex_Operations.hpp"

std::vector<std::string> Regex_Operations::splitGivenString(const std::string& s, char delimiter)
{
  std::vector<std::string> tokens;
  std::string token;
  std::istringstream tokenStream(s);
  while (std::getline(tokenStream, token, delimiter))
  {
    tokens.push_back(token);
  }
  return tokens;
}