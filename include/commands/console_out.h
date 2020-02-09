
#ifndef CONSOLE_OUT_H
#define CONSOLE_OUT_H

#include "command.h"

#include <string>
#include <memory>

class ConsoleOut: public Command{
public:
    ConsoleOut(std::vector<std::string>);
    void execute(Environment &, std::vector<std::unique_ptr<Command>> &, int *);
    int getNumParams();
    std::string getName();
};

#endif // CONSOLE_OUT_H
