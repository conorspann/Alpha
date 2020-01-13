
#ifndef FORMATTER_H
#define FORMATTER_H

#include <string>
#include <vector>

#include "formatted_line.h"

class Formatter{
public:
    Formatter();
    FormattedLine format(std::string);
private:
    std::string removeWhiteSpace(std::string);
    std::string getCommandStr(std::string);
    std::vector<std::string> getParamList(std::string);
    std::vector<std::string> getDefineParamList(std::string);
    std::string findParams(std::string);
    bool isWhiteSpace(char);
};

#endif // FORMATTER_H
