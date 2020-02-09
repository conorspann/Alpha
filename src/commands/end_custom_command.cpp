

#include "../../include/commands/end_custom_command.h"
#include "../../include/runtime/environment.h"

EndCustomCommand::EndCustomCommand(std::vector<std::string> params):
    Command(params)
{

}

void EndCustomCommand::execute(Environment & environment, std::vector<std::unique_ptr<Command>> &, int * cmdPtr)
{
    std::stack<int> & callStack = environment.getCallStack();
    std::map<std::string, std::pair<std::string, int>> & globalDataPool = environment.getGlobalDataPool();
    Resolver & resolver = environment.getResolver();
    Searcher & searcher = environment.getSearcher();
    *cmdPtr = callStack.top();
    callStack.pop();
}

int EndCustomCommand::getNumParams()
{
    return 0;
}

std::string EndCustomCommand::getName()
{
    return "EndCustomCommand";
}
