#include <vector>
#include <string>

class File_Accessor
{
    public:
        static std::vector<std::string> getFirstLineMatched(std::string filePathRelativeToPWD, std::string tokenToMatch);
        static int countNumberOfLines(std::string filePathRelativeToPWD);
        static int countNumberOfLinesThatStartWith(std::string filePathRelativeToPWD, std::string lineStartsWith);
        static std::vector<std::string> returnAllLinesInAFile(std::string filePathRelativeToPWD);
        static void appendToAFile(std::string filePathRelativeToPWD, std::string lineToAppend);
        static std::vector<std::string> returnAllLinesThatStartWith(std::string filePathRelativeToPWD, std::string lineStartsWith);
        static bool is_empty(std::ifstream& pFile);
};