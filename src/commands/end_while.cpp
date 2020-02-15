

#include <iostream>

#include "../../include/commands/end_while.h"
#include "../../include/runtime/environment.h"

EndWhile::EndWhile(std::vector<std::string> p):
    Command(p)
{

}

void EndWhile::execute(Environment & environment, std::vector<std::unique_ptr<Command>> & cmds, int * cmdPtr)
{
    Searcher & searcher = environment.getSearcher();
    *cmdPtr = searcher.findLabel("EndWhile", "While", -1, true, cmds, cmdPtr);
}

int EndWhile::getNumParams()
{
    return 0;
}

std::string EndWhile::getName()
{
    return "EndWhile";
}
