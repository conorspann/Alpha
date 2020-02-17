

#ifndef CREATE_WINDOW_H
#define CREATE_WINDOW_H

#include "command.h"
#include <string>
#include <vector>

class CreateWindow: public Command{
public:
    CreateWindow(std::vector<std::string>);
    void execute(Environment &, int *);
    int getNumParams();
    std::string getName();
};

#endif // CREATE_WINDOW_H
