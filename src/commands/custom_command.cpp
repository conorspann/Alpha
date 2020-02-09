

#include "../../include/commands/custom_command.h"
#include "../../include/runtime/environment.h"

CustomCommand::CustomCommand(std::vector<std::string> params):
    Command(params)
{

}

void CustomCommand::execute(Environment & environment, std::vector<std::unique_ptr<Command>> & cmds, int * cmdPtr)
{
    std::stack<int> & callStack = environment.getCallStack();
    std::map<std::string, std::pair<std::string, int>> & globalDataPool = environment.getGlobalDataPool();
    Resolver & resolver = environment.getResolver();
    Searcher & searcher = environment.getSearcher();
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
