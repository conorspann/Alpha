
#include <string>
#include <vector>
#include <iostream>

#include "../../include/commands/console_out.h"
#include "../../include/runtime/environment.h"

ConsoleOut::ConsoleOut(std::vector<std::string> params):
    Command(params)
{

}

void ConsoleOut::execute(Environment & environment, int *)
{
    std::map<std::string, std::pair<std::string, int>> & globalDataPool = environment.getGlobalDataPool();
    Resolver & resolver = environment.getResolver();
    std::string output = resolver.resolve(params[0], globalDataPool);
    /** remove " s ? */
    std::cout << output << std::endl; /** ????? int val? */
}

int ConsoleOut::getNumParams()
{
    return 1;
}

std::string ConsoleOut::getName()
{
    return "ConsoleOut";
}
