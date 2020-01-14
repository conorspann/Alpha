
#ifndef ASSIGN_H
#define ASSIGN_H

#include "command.h"
#include <string>
#include <vector>
#include <memory>

//maybe make the formatter parse assign command params differently

class Assign: public Command{
public:
    Assign(std::vector<std::string>);
    void execute(Resolver &, Searcher &, std::map<std::string, std::pair<std::string, int>> * , std::vector<std::unique_ptr<Command>> &, int *);
    int getNumParams();
    std::string getName();
};

#endif // ASSIGN_H
