
#ifndef CLEAR_WINDOW_H
#define CLEAR_WINDOW_H

#include "command.h"
#include <string>
#include <vector>

class ClearWindow: public Command{
public:
    ClearWindow(std::vector<std::string>);
    void execute(Environment &, int *);
    int getNumParams();
    std::string getName();
};

#endif // CLEAR_WINDOW_H



