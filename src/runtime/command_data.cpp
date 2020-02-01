

#include <string>
#include <vector>

#include "../../include/runtime/command_data.h"


CommandData::CommandData(int lineNumber, std::string name, std::vector<std::string> params):
    lineNumber(lineNumber),
    name(name),
    params(params)
{

}

int CommandData::getLineNumber()
{
    return lineNumber;
}

std::string CommandData::getName()
{
    return name;
}

std::vector<std::string> CommandData::getParams()
{
    return params;
}
