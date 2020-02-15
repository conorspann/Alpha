

#include "../../include/commands/end_custom_command.h"
#include "../../include/runtime/environment.h"

EndCustomCommand::EndCustomCommand(std::vector<std::string> params):
    Command(params)
{

}

void EndCustomCommand::execute(Environment & environment, int * cmdPtr)
{
    std::stack<int> & callStack = environment.getCallStack();
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
