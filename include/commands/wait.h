

#ifndef WAIT_H
#define WAIT_H

#include "command.h"
#include <string>
#include <vector>

class Wait: public Command{
public:
    Wait(std::vector<std::string>);
    void execute(Environment &, int *);
    int getNumParams();
    std::string getName();
};

#endif // WAIT_H

