
#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <stack>

#include "../gui/window.h"
#include "resolver.h"
#include "searcher.h"
#include "data_pool.h"

/**
    Maybe could make this an abstract class and have one global
    environment instance, then create local environment instances
    for functions and control blocks
*/

class Environment{
public:
    Environment(std::vector<std::string> labels);

    /**
        may make this as an interface for the commands to interact
        with the members
    */

    std::string getNewWindowHandle();
    std::vector<Window> & getWindows();
    Resolver & getResolver();
    Searcher & getSearcher();
    DataPool & getDataPool();
    std::stack<int> & getCallStack();
private:
    std::vector<Window> windows;
    Resolver resolver;
    Searcher searcher;
    DataPool dataPool;
    std::stack<int> callStack;
};

#endif // ENVIRONMENT_H
