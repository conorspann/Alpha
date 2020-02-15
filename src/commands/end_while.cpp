

#include "../../include/commands/end_while.h"
#include "../../include/runtime/environment.h"

EndWhile::EndWhile(std::vector<std::string> p):
    Command(p)
{

}

void EndWhile::execute(Environment & environment, int * cmdPtr)
{
    Searcher & searcher = environment.getSearcher();
    *cmdPtr = searcher.findLabel("EndWhile", "While", -1, cmdPtr);
}

int EndWhile::getNumParams()
{
    return 0;
}

std::string EndWhile::getName()
{
    return "EndWhile";
}
