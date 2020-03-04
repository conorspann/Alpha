

#include <string>
#include <iostream>

#include "../../include/commands/console_in.h"
#include "../../include/runtime/environment.h"

ConsoleIn::ConsoleIn(std::vector<std::string> p, int lineNumber):
    Command(p, lineNumber)
{

}


void ConsoleIn::execute(Environment & environment, int *)
{
    DataPool & dataPool = environment.getDataPool();
    Resolver & resolver = environment.getResolver();
    std::string varName = params[0];
    std::pair<std::string, int> & variable = resolver.resolveVariable(varName, dataPool);
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

