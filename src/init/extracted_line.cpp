

#include "../../include/init/extracted_line.h"

#include <string>
#include <vector>

ExtractedLine::ExtractedLine(std::string cstr, std::vector<std::string> pstr):
    cmdStr(cstr),
    paramStr(pstr)
{

}

std::string ExtractedLine::getCommandStr()
{
    return cmdStr;
}

std::vector<std::string> ExtractedLine::getParamList()
{
    return paramStr;
}
