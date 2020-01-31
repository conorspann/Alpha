
#include "../../include/commands/endif.h"

EndIf::EndIf(std::vector<std::string> p):
    Command(p)
{

}

void EndIf::execute(Resolver & resolver, Searcher & searcher, std::map<std::string, std::pair<std::string, int>> *, std::stack<int> &, std::vector<std::unique_ptr<Command>> &, int *)
{
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
