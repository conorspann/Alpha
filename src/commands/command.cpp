

#include <string>
#include <vector>

#include "../../include/commands/command.h"

Command::Command(std::vector<std::string> p, int lineNumber):
    params(p),
    preservedLineNumber(lineNumber)
{

}

bool Command::hasCorrectNumParams()
{
    return params.size() == getNumParams();
}

int Command::getPreservedLineNumber()
{
    return preservedLineNumber;
}

std::string Command::toString()
{
    std::string result;
    result += "[";
    result += std::to_string(preservedLineNumber);
    result += "][";
    result += getName();
    result += "][";
    for (int paramNumber = 0; paramNumber < getNumParams(); paramNumber++) {
        result += "[";
        result += params[paramNumber];
        result += "]";
    }
    result += "]";

    return result;
}
