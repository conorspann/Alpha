
#include "../../include/commands/wait.h"

#include <vector>
#include <string>

Wait::Wait(std::vector<std::string> params):
    Command(params)
{

}

void Wait::execute(Environment & environment, int * cmdPtr)
{
    std::map<std::string, std::pair<std::string, int>> & globalDataPool = environment.getGlobalDataPool();
    Resolver & resolver = environment.getResolver();
    std::string timeStr = resolver.resolve(params[0], globalDataPool);
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

