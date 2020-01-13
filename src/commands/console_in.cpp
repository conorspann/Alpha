
#include "../../include/commands/console_in.h"

#include <string>
#include <iostream>

ConsoleIn::ConsoleIn(std::vector<std::string> p):
    Command(p)
{

}


void ConsoleIn::execute(Resolver & resolver, std::map<std::string, std::pair<std::string, int>> * globalDataPool, std::vector<std::unique_ptr<Command>> &, int *)
{
    std::map<std::string, std::pair<std::string, int>>::iterator it;
    it = globalDataPool->find(params[0]);
    if(it == globalDataPool->end()){
        std::string errMsg = "Error: parameter variable: ";
        errMsg += params[0];
        errMsg += " does not exist";
        throw std::runtime_error(errMsg);
    }
    std::string userInput;
    std::getline(std::cin, userInput);
    it->second.first = userInput;

    /** check type?  set second.second ?? */
}

int ConsoleIn::getNumParams()
{
    return 1;
}

std::string ConsoleIn::getName()
{
    return "ConsoleIn";
}

