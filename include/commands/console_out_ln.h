
#ifndef CONSOLE_OUT_LN_H
#define CONSOLE_OUT_LN_H

#include "console_out.h"

#include <string>
#include <memory>

class ConsoleOutLn: public ConsoleOut{
public:
    ConsoleOutLn(std::vector<std::string>, int);
    void execute(Environment &, int *);
    std::string getName();
};

#endif // CONSOLE_OUT__LN_H

