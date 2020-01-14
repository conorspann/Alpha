
#include "../../include/commands/if.h"

#include <iostream>

If::If(std::vector<std::string> p):
    Command(p)
{

}

void If::execute(Resolver & resolver, Searcher & searcher, std::map<std::string, std::pair<std::string, int>> * globalDataPool, std::vector<std::unique_ptr<Command>> & cmds, int * cmdPtr)
{
    std::string val = resolver.resolve(params[0], globalDataPool);
    if(val.find_first_not_of("0123456789-") != std::string::npos){
        std::string errMsg = "Cannot resolve string: ";
        errMsg += val;
        errMsg += " to boolean in if-statement.";
        throw std::runtime_error(errMsg);
    }
    int intVal = std::stoi(val);
    if(intVal < 1){
        *cmdPtr = searcher.findLabel("If", "EndIf", 1, false, cmds, cmdPtr);
    }
}


int If::getNumParams()
{
    return 1;
}

std::string If::getName()
{
    return "if";
}

