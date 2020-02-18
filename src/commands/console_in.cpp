

#include <string>
#include <iostream>

#include "../../include/commands/console_in.h"
#include "../../include/runtime/environment.h"

ConsoleIn::ConsoleIn(std::vector<std::string> p):
    Command(p)
{

}


void ConsoleIn::execute(Environment & environment, int *)
{
    std::map<std::string, std::pair<std::string, int>> & globalDataPool = environment.getGlobalDataPool();
    Resolver & resolver = environment.getResolver();
    std::string varName = params[0];
    std::pair<std::string, int> & variable = resolver.resolveVariable(varName, globalDataPool);
    std::string userInput;
    std::getline(std::cin, userInput);
    variable.first = userInput;
    /** check type?  set variable.second ?? */
}

int ConsoleIn::getNumParams()
{
    return 1;
}

std::string ConsoleIn::getName()
{
    return "ConsoleIn";
}

