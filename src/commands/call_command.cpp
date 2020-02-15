

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

