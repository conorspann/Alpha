

#ifndef END_WHILE_H
#define END_WHILE_H

#include "command.h"

#include <memory>

class EndWhile: public Command{
public:
    EndWhile(std::vector<std::string> p);
    void execute(Environment &, int *);
    int getNumParams();
    std::string getName();
};

#endif // END_WHILE_H
