
#ifndef CUSTOM_COMMAND_H
#define CUSTOM_COMMAND_H

#include <string>
#include <vector>

#include "command.h"

class CustomCommand: public Command{
public:
    CustomCommand(std::vector<std::string>, int);
    void execute(Environment &, int *);
    int getNumParams();
    std::string getName();
};

#endif // CUSTOM_COMMAND_H
