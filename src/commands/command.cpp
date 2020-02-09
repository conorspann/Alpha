

#include <string>
#include <vector>

#include "../../include/commands/command.h"

Command::Command(std::vector<std::string> p):
    params(p)
{

}

bool Command::hasCorrectNumParams()
{
    return params.size() == getNumParams();
}
