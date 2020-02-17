

#ifndef HIDE_WINDOW_H
#define HIDE_WINDOW_H

#include "command.h"
#include <string>
#include <vector>

class HideWindow: public Command{
public:
    HideWindow(std::vector<std::string>);
    void execute(Environment &, int *);
    int getNumParams();
    std::string getName();
};

#endif // HIDE_WINDOW_H


