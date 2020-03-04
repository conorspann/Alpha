

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
