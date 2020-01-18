
#ifndef EXTRACTED_LINE_H
#define EXTRACTED_LINE_H

#include <string>
#include <vector>

class ExtractedLine
{
public:
    ExtractedLine(std::string, std::vector<std::string>);
    std::string getCommandStr();
    std::vector<std::string> getParamList();
private:
    std::string cmdStr;
    std::vector<std::string> paramStr;
};

#endif
