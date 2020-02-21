
#ifndef DRAW_RECT_H
#define DRAW_RECT_H

#include "command.h"
#include <string>
#include <vector>

class DrawRect: public Command{
public:
    DrawRect(std::vector<std::string>);
    void execute(Environment &, int *);
    int getNumParams();
    std::string getName();
};

#endif // DRAW_RECT_H

