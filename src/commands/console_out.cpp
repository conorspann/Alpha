
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
    DataPool & dataPool = environment.getDataPool();
    Resolver & resolver = environment.getResolver();
    std::string output = resolver.resolve(params[0], dataPool);
    std::cout << output;
}

int ConsoleOut::getNumParams()
{
    return 1;
}

std::string ConsoleOut::getName()
{
    return "ConsoleOut";
}
