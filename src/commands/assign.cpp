

#include <iostream>

#include "../../include/commands/assign.h"
#include "../../include/runtime/environment.h"

Assign::Assign(std::vector<std::string> params):
    Command(params)
{

}

void Assign::execute(Environment & environment, std::vector<std::unique_ptr<Command>> &, int *)
{
    std::stack<int> & callStack = environment.getCallStack();
    std::map<std::string, std::pair<std::string, int>> & globalDataPool = environment.getGlobalDataPool();
    Resolver & resolver = environment.getResolver();
    Searcher & searcher = environment.getSearcher();
    std::string identifier = params[0];
    std::string value = resolver.resolve(params[1], globalDataPool);
    std::map<std::string, std::pair<std::string, int>>::iterator it;
    it = globalDataPool.find(identifier);
    if(it == globalDataPool.end()){
        //TODO WILL NEED TO CHECK FOR PARAM CORRECTNESS HERE IN THE FUTURE
        // for now just insert
        /** will have to update to add support for floats/decimals
         */
        int type = Type::INT;
        if(value.find_first_not_of("0123456789") != std::string::npos){
            //string ?
            type = Type::STRING;
        }
        std::pair<std::string, int> val(value, type);
        globalDataPool.insert(std::pair<std::string, std::pair<std::string, int>>(identifier, val));
    }else{
        it->second.first = value;
    }
}

//param 1 = variable identifier
//param 2 = value
int Assign::getNumParams()
{
    return 2;
}

std::string Assign::getName()
{
    return "@";
}
