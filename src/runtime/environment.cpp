
#include "../../include/runtime/environment.h"
#include "../../include/runtime/searcher.h"
#include "../../include/runtime/resolver.h"

Environment::Environment(std::vector<std::string> labels):
    searcher(labels)
{

}

std::string Environment::getNewWindowHandle()
{
    return std::to_string(windows.size());
}

std::vector<Window> & Environment::getWindows()
{
    return windows;
}

Resolver & Environment::getResolver()
{
    return resolver;
}

Searcher & Environment::getSearcher()
{
    return searcher;
}

std::stack<int> & Environment::getCallStack()
{
    return callStack;
}

std::map<std::string, std::pair<std::string, int>> & Environment::getGlobalDataPool()
{
    return globalDataPool;
}

