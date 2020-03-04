

#include <iostream>

#include "../../include/commands/if.h"
#include "../../include/runtime/environment.h"

If::If(std::vector<std::string> p, int lineNumber):
    Command(p, lineNumber)
{

}

void If::execute(Environment & environment, int * cmdPtr)
{
    DataPool & dataPool = environment.getDataPool();
    Resolver & resolver = environment.getResolver();
    Searcher & searcher = environment.getSearcher();
    std::string val = resolver.resolve(params[0], dataPool);
    if(val.find_first_not_of("0123456789-") != std::string::npos){
        std::string errMsg = "Cannot resolve string: ";
        errMsg += val;
        errMsg += " to boolean in if-statement.";
        throw std::runtime_error(errMsg);
    }
    int intVal = std::stoi(val);
    if(intVal < 1){
        *cmdPtr = searcher.findLabel("If", "EndIf", 1, cmdPtr);
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

