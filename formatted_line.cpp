

#include "formatted_line.h"

#include <string>
#include <vector>

FormattedLine::FormattedLine(std::string cstr, std::vector<std::string> pstr):
    cmdStr(cstr),
    paramStr(pstr)
{

}

std::string FormattedLine::getCommandStr()
{
    return cmdStr;
}

std::vector<std::string> FormattedLine::getParamList()
{
    return paramStr;
}
