

#include "../../include/commands/endif.h"
#include "../../include/runtime/environment.h"

EndIf::EndIf(std::vector<std::string> p):
    Command(p)
{

}

void EndIf::execute(Environment & environment, std::vector<std::unique_ptr<Command>> &, int *)
{
    std::stack<int> & callStack = environment.getCallStack();
    std::map<std::string, std::pair<std::string, int>> & globalDataPool = environment.getGlobalDataPool();
    Resolver & resolver = environment.getResolver();
    Searcher & searcher = environment.getSearcher();
    // do nothing ??
}

int EndIf::getNumParams()
{
    return 0;
}

std::string EndIf::getName()
{
    return "EndIf";
}
