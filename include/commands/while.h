
#ifndef WHILE_H
#define WHILE_H

#include "command.h"

#include <memory>

class While: public Command{
public:
    While(std::vector<std::string> p);
    void execute(Environment &, int *);
    int getNumParams();
    std::string getName();
};

#endif // WHILE_H
