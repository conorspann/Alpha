
#ifndef CALL_COMMAND_H
#define CALL_COMMAND_H

#include "command.h"
#include <string>
#include <vector>
#include <memory>

//maybe make the formatter parse assign command params differently

class CallCommand: public Command{
public:
    CallCommand(std::vector<std::string>);
    void execute(Resolver &, Searcher &, std::map<std::string, std::pair<std::string, int>> * , std::stack<int> &,  std::vector<std::unique_ptr<Command>> &, int *);
    int getNumParams();
    std::string getName();
};

#endif // ASSIGN_H

