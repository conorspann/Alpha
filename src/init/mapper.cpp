
#include <stdexcept>
#include <iostream>
#include <string>
#include <memory>

#include "../../include/init/mapper.h"
#include "../../include/commands/command.h"
#include "../../include/commands/console_out.h"
#include "../../include/commands/console_out_ln.h"
#include "../../include/commands/console_in.h"
#include "../../include/commands/assign.h"
#include "../../include/commands/memory_dump.h"
#include "../../include/commands/if.h"
#include "../../include/commands/endif.h"
#include "../../include/commands/while.h"
#include "../../include/commands/end_while.h"
#include "../../include/commands/call_command.h"
#include "../../include/commands/custom_command.h"
#include "../../include/commands/end_custom_command.h"
#include "../../include/runtime/command_data.h"
#include "../../include/commands/wait.h"
#include "../../include/commands/create_window.h"
#include "../../include/commands/show_window.h"
#include "../../include/commands/hide_window.h"


std::unique_ptr<Command> Mapper::getNewCommand(std::string line, std::vector<std::string> params, std::vector<CommandData> & customCommands)
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
    }else if(line == "ConsoleOutLn"){
        c = std::make_unique<ConsoleOutLn>(params);
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
    }else if(line == "Cmd"){
        c = std::make_unique<CustomCommand>(params);
    }else if(line == "EndCmd"){
        c = std::make_unique<EndCustomCommand>(params);
    }else if(line == "Wait"){
        c = std::make_unique<Wait>(params);
    }else if(line == "CreateWindow"){
        c = std::make_unique<CreateWindow>(params);
    }else if(line == "ShowWindow"){
        c = std::make_unique<ShowWindow>(params);
    }else if(line == "HideWindow"){
        c = std::make_unique<HideWindow>(params);
    }else{
        for(auto customCommand: customCommands){
            if(customCommand.getName() == line){
                std::vector<std::string> paramLineNumber = {std::to_string(customCommand.getLineNumber())};
                c = std::make_unique<CallCommand>(paramLineNumber);
                return std::move(c);
            }
        }
        throw std::runtime_error("Exception: Command \"" + line + "\" not valid");
    }
    if(c->getNumParams() > 0 && !c->hasCorrectNumParams()){
        throw std::runtime_error("Command: " + c->getName() + " requires " + std::to_string(c->getNumParams()) + " params.");
    }
    return std::move(c);
}
