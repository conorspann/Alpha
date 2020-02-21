
#ifndef RENDER_WINDOW_H
#define RENDER_WINDOW_H

#include "command.h"
#include <string>
#include <vector>

class RenderWindow: public Command{
public:
    RenderWindow(std::vector<std::string>);
    void execute(Environment &, int *);
    int getNumParams();
    std::string getName();
};

#endif // RENDER_WINDOW_H


