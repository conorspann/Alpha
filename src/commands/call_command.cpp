

#include <iostream>

#include "../../include/commands/call_command.h"
#include "../../include/runtime/environment.h"

CallCommand::CallCommand(std::vector<std::string> params):
    Command(params)
{

}

void CallCommand::execute(Environment & environment, std::vector<std::unique_ptr<Command>> &, int * cmdPtr)
{
    std::stack<int> & callStack = environment.getCallStack();
    std::map<std::string, std::pair<std::string, int>> & globalDataPool = environment.getGlobalDataPool();
    Resolver & resolver = environment.getResolver();
    Searcher & searcher = environment.getSearcher();
    callStack.push(*cmdPtr);
    int funcAddr = std::stoi(params[0]);
    *cmdPtr = funcAddr;
}

int CallCommand::getNumParams()
{
    return 1; // maybe need some sort of variable-number of commands?
}

std::string CallCommand::getName()
{
    return "CallCommand";
}

