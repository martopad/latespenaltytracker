#include <vector>
#include <string>

class File_Accessor
{
    public:
        static std::vector<std::string> getFirstLineMatched(std::string filePathRelativeToPWD, std::string tokenToMatch);
        static int countNumberOfLines(std::string filePathRelativeToPWD);
        static int countNumberOfLinesThatStartWith(std::string filePathRelativeToPWD, std::string lineStartsWith);
        static std::vector<std::string> returnAllLinesInAFile(std::string filePathRelativeToPWD);
};