
#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <stack>

#include "resolver.h"
#include "searcher.h"

/**
    Maybe could make this an abstract class and have one global
    environment instance, then create local environment instances
    for functions and control blocks
*/

class Environment{
public:
    Environment();

    /** may make this as an interface for the commands to interact
        with the members
    */

    Resolver & getResolver();
    Searcher & getSearcher();
    std::stack<int> & getCallStack();
    std::map<std::string, std::pair<std::string, int>> & getGlobalDataPool();
private:
    Resolver resolver;
    Searcher searcher;
    std::stack<int> callStack;
    std::map<std::string, std::pair<std::string, int>> globalDataPool;
};

#endif // ENVIRONMENT_H
