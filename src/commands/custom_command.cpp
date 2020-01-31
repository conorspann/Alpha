
#include "../../include/commands/custom_command.h"

CustomCommand::CustomCommand(std::vector<std::string> params):
    Command(params)
{

}

void CustomCommand::execute(Resolver &, Searcher & searcher, std::map<std::string, std::pair<std::string, int>> * , std::stack<int> &, std::vector<std::unique_ptr<Command>> & cmds, int * cmdPtr)
{
    *cmdPtr = searcher.findLabel("CustomCommand", "EndCustomCommand", 1, true, cmds, cmdPtr);
}

int CustomCommand::getNumParams()
{
    return 0;
}

std::string CustomCommand::getName()
{
    return "CustomCommand";
}
