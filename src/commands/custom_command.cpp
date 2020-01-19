
#include "../../include/commands/custom_command.h"

#include <string>
#include <vector>

CustomCommand::CustomCommand(std::string name, std::vector<std::string> params):
    lineNumber(0),
    name(name),
    params(params)
{

}

void CustomCommand::jumpToCommand()
{

}

void CustomCommand::setLineNumber(int lineNumber)
{
    this->lineNumber = lineNumber;
}

int CustomCommand::getLineNumber()
{
    return lineNumber;
}

std::string CustomCommand::getName()
{
    return name;
}

std::vector<std::string> CustomCommand::getParams()
{
    return params;
}
