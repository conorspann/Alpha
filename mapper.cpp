
#include "mapper.h"
#include "command.h"
#include "console_out.h"
#include "console_in.h"
#include "assign.h"
#include "memory_dump.h"
#include "if.h"
#include "endif.h"
#include "while.h"
#include "end_while.h"

#include <exception>
#include <stdexcept>
#include <iostream>
#include <string>

std::unique_ptr<Command> Mapper::getNewCommand(std::string line, std::vector<std::string> params)
{
    //could potentially re write using a map of string->function pointers
    //functions return type of oommand
    //std::unique_ptr<Command> (*p)(std::vector<std::string>);
    //could initialise in constructor
    //however may be more complicated than all the if's
// refactor
// maybe do upppercase and lowercase ??
    std::unique_ptr<Command> c;
    if(line == "@"){
        c = std::make_unique<Assign>(params);
    }else if(line == "ConsoleOut"){
        c = std::make_unique<ConsoleOut>(params);
    }else if(line == "ConsoleIn"){
        c = std::make_unique<ConsoleIn>(params);
    }else if(line == "MemoryDump"){
        c = std::make_unique<MemoryDump>(params);
    }else if(line == "If"){
        c = std::make_unique<If>(params);
    }else if(line == "EndIf"){
        c = std::make_unique<EndIf>(params);
    }else if(line == "While"){
        c = std::make_unique<While>(params);
    }else if(line == "EndWhile"){
        c = std::make_unique<EndWhile>(params);
    }else{
        throw std::runtime_error("Exception: Command \"" + line + "\" not valid");
    }
    if(!c->hasCorrectNumParams()){
        throw std::runtime_error("Command: " + c->getName() + " requires " + std::to_string(c->getNumParams()) + " params.");
    }
    return std::move(c);
}
