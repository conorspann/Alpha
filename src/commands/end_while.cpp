
#include "../../include/commands/end_while.h"


#include <iostream>

EndWhile::EndWhile(std::vector<std::string> p):
    Command(p)
{

}

void EndWhile::execute(Resolver & resolver, Searcher & searcher, std::map<std::string, std::pair<std::string, int>> * globalDataPool, std::vector<std::unique_ptr<Command>> & cmds, int * cmdPtr)
{
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
