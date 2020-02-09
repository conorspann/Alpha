
#ifndef IF_H
#define IF_H

#include "command.h"

#include <memory>

class If: public Command{
public:
    If(std::vector<std::string> p);
    void execute(Environment &, std::vector<std::unique_ptr<Command>> &, int *);
    int getNumParams();
    std::string getName();
};

#endif // IF_H
