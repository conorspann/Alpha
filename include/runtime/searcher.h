
#ifndef SEARCHER_H
#define SEARCHER_H


class Searcher;
#include "../commands/command.h"

class Searcher{
public:
    Searcher();
    int findLabel(std::string startLabel, std::string endLabel, int, bool,std::vector<std::unique_ptr<Command>> &, int * cmdPtr);
private:
    std::vector<std::unique_ptr<Command>> * cmds;
};

#endif // SEARCHER_H
