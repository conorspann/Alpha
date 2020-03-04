
#include "../../include/commands/console_out_ln.h"

#include <iostream>

ConsoleOutLn::ConsoleOutLn(std::vector<std::string> params, int lineNumber):
    ConsoleOut(params, lineNumber)
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
