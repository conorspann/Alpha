
#ifndef CONSOLE_IN_H
#define CONSOLE_IN_H

#include "command.h"

class ConsoleIn: public Command{
public:
    ConsoleIn(std::vector<std::string> p);
    void execute(Resolver &, Searcher &, std::map<std::string, std::pair<std::string, int>> * , std::stack<int> &, std::vector<std::unique_ptr<Command>> &, int *);
    int getNumParams();
    std::string getName();
};

#endif // CONSOLE_IN_H
