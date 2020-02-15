

#include "../../include/commands/custom_command.h"
#include "../../include/runtime/environment.h"

CustomCommand::CustomCommand(std::vector<std::string> params):
    Command(params)
{

}

void CustomCommand::execute(Environment & environment, int * cmdPtr)
{
    Searcher & searcher = environment.getSearcher();
    *cmdPtr = searcher.findLabel("CustomCommand", "EndCustomCommand", 1, cmdPtr);
}

int CustomCommand::getNumParams()
{
    return 0;
}

std::string CustomCommand::getName()
{
    return "CustomCommand";
}
