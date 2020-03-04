
#include "../../include/commands/wait.h"

#include <vector>
#include <string>

Wait::Wait(std::vector<std::string> params, int lineNumber):
    Command(params, lineNumber)
{

}

void Wait::execute(Environment & environment, int * cmdPtr)
{
    DataPool & dataPool = environment.getDataPool();
    Resolver & resolver = environment.getResolver();
    std::string timeStr = resolver.resolve(params[0], dataPool);
    if(resolver.determineType(timeStr) != Command::Type::INT){
        throw std::runtime_error("Error: Wait time must be a whole integer (milliseconds).");
    }
    int timeMilliSeconds = std::stoi(timeStr);
    SDL_Delay(timeMilliSeconds);
}

int Wait::getNumParams()
{
    return 1;
}

std::string Wait::getName()
{
    return "Wait";
}

