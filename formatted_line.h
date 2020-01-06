
#ifndef FORMATTED_LINE_H
#define FORMATTED_LINE_H

#include <string>
#include <vector>

class FormattedLine
{
public:
    FormattedLine(std::string, std::vector<std::string>);
    std::string getCommandStr();
    std::vector<std::string> getParamList();
private:
    std::string cmdStr;
    std::vector<std::string> paramStr;
};

#endif
