
#ifndef CONSOLE_IN_H
#define CONSOLE_IN_H

#include "command.h"

class ConsoleIn: public Command{
public:
    ConsoleIn(std::vector<std::string> p);
    void execute(Environment &, int *);
    int getNumParams();
    std::string getName();
};

#endif // CONSOLE_IN_H
