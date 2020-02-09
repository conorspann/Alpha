

#include <iostream>

#include "../../include/commands/while.h"
#include "../../include/runtime/environment.h"

While::While(std::vector<std::string> p):
    Command(p)
{

}

void While::execute(Environment & environment, std::vector<std::unique_ptr<Command>> & cmds, int * cmdPtr)
{
    std::stack<int> & callStack = environment.getCallStack();
    std::map<std::string, std::pair<std::string, int>> & globalDataPool = environment.getGlobalDataPool();
    Resolver & resolver = environment.getResolver();
    Searcher & searcher = environment.getSearcher();
    std::string val = resolver.resolve(params[0], globalDataPool);
    if(val.find_first_not_of("0123456789-") != std::string::npos){
        std::string errMsg = "Cannot resolve string: ";
        errMsg += val;
        errMsg += " to boolean in if-statement.";
        throw std::runtime_error(errMsg);
    }
    int intVal = std::stoi(val);
    if(intVal < 1){
        *cmdPtr = searcher.findLabel("While", "EndWhile", 1, false, cmds, cmdPtr);
    }
}

int While::getNumParams()
{
    return 1;
}

std::string While::getName()
{
    return "While";
}
