
#ifndef END_CUSTOM_COMMAND_H
#define END_CUSTOM_COMMAND_H

#include <string>
#include <vector>

#include "command.h"

class EndCustomCommand: public Command{
public:
    EndCustomCommand(std::vector<std::string>, int);
    void execute(Environment &, int *);
    int getNumParams();
    std::string getName();
};

#endif // END_CUSTOM_COMMAND_H
