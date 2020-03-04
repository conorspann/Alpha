

#include <iostream>

#include "../../include/commands/assign.h"
#include "../../include/runtime/environment.h"

Assign::Assign(std::vector<std::string> params, int lineNumber):
    Command(params, lineNumber)
{

}

void Assign::execute(Environment & environment, int *)
{
    Resolver & resolver = environment.getResolver();
    DataPool & dataPool = environment.getDataPool();
    std::string identifier = params[0];
    std::string value = resolver.resolve(params[1], dataPool);
    if(dataPool.getAddress(identifier) == -1){
        int type = resolver.determineType(value);
        std::pair<std::string, int> valPair(value, type);
        dataPool.addVariable(identifier, valPair);
    }else{
        dataPool.editVariable(identifier, value);
    }
}

int Assign::getNumParams()
{
    return 2;
}

std::string Assign::getName()
{
    return "@";
}
