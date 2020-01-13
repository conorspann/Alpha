
#include "../../include/commands/command.h"

#include <string>
#include <vector>

Command::Command(std::vector<std::string> p):
    params(p)
{

}

bool Command::hasCorrectNumParams()
{
    return params.size() == getNumParams();
}
