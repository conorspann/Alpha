

#ifndef SHOW_WINDOW_H
#define SHOW_WINDOW_H

#include "command.h"
#include <string>
#include <vector>

class ShowWindow: public Command{
public:
    ShowWindow(std::vector<std::string>, int);
    void execute(Environment &, int *);
    int getNumParams();
    std::string getName();
};

#endif // SHOW_WINDOW_H

