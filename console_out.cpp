
#include "console_out.h"

#include <string>
#include <vector>

#include <iostream>

ConsoleOut::ConsoleOut(std::vector<std::string> params):
    Command(params)
{

}

void ConsoleOut::execute(Resolver & resolver, std::map<std::string, std::pair<std::string, int>> * globalDataPool, std::vector<std::unique_ptr<Command>> &, int *)
{
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
