

#include "../../include/commands/end_custom_command.h"


EndCustomCommand::EndCustomCommand(std::vector<std::string> params):
    Command(params)
{

}

void EndCustomCommand::execute(Resolver &, Searcher & searcher, std::map<std::string, std::pair<std::string, int>> * , std::stack<int> & callStack, std::vector<std::unique_ptr<Command>> &, int * cmdPtr)
{
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
