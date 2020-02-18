

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
    std::map<std::string, std::pair<std::string, int>>::iterator it;
    std::string varName = params[0];
    if(varName.length() < 2 || varName[0] != '@'){
        throw std::runtime_error("Error: parameter must be a variable.");
    }
    varName = varName.substr(1);
    it = globalDataPool.find(varName);
    if(it == globalDataPool.end()){
        std::string errMsg = "Error: parameter variable: ";
        errMsg += varName;
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

