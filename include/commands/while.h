
#ifndef WHILE_H
#define WHILE_H

#include "command.h"

#include <memory>

class While: public Command{
public:
    While(std::vector<std::string> p);
    void execute(Environment &, std::vector<std::unique_ptr<Command>> &, int *);
    int getNumParams();
    std::string getName();
};

#endif // WHILE_H
