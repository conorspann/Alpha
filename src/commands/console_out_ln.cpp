
#include "../../include/commands/console_out_ln.h"

#include <iostream>

ConsoleOutLn::ConsoleOutLn(std::vector<std::string> params):
    ConsoleOut(params)
{

}

void ConsoleOutLn::execute(Environment & environment, int * cmdPtr)
{
    ConsoleOut::execute(environment, cmdPtr);
    std::cout << std::endl;
}

std::string ConsoleOutLn::getName()
{
    return "ConsoleOutLn";
}
