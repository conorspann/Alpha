

#include <iostream>

#include "../../include/commands/call_command.h"


CallCommand::CallCommand(std::vector<std::string> params):
    Command(params)
{

}

void CallCommand::execute(Resolver &, Searcher &, std::map<std::string, std::pair<std::string, int>> * , std::stack<int> & callStack, std::vector<std::unique_ptr<Command>> &, int * cmdPtr)
{
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

