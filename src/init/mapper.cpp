
#include <stdexcept>
#include <iostream>
#include <string>
#include <memory>

#include "../../include/init/mapper.h"
#include "../../include/exception/syntax_error.h"
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
#include "../../include/commands/render_window.h"
#include "../../include/commands/clear_window.h"
#include "../../include/commands/draw_rect.h"


Mapper::Mapper()
{
    commandMap.insert(std::pair<std::string, commandGenerator>("@", genAssign));
    commandMap.insert(std::pair<std::string, commandGenerator>("ConsoleOut", genConsoleOut));
    commandMap.insert(std::pair<std::string, commandGenerator>("ConsoleOutLn", genConsoleOutLn));
    commandMap.insert(std::pair<std::string, commandGenerator>("ConsoleIn", genConsoleIn));
    commandMap.insert(std::pair<std::string, commandGenerator>("MemoryDump", genMemoryDump));
    commandMap.insert(std::pair<std::string, commandGenerator>("If", genIf));
    commandMap.insert(std::pair<std::string, commandGenerator>("EndIf", genEndIf));
    commandMap.insert(std::pair<std::string, commandGenerator>("While", genWhile));
    commandMap.insert(std::pair<std::string, commandGenerator>("EndWhile", genEndWhile));
    commandMap.insert(std::pair<std::string, commandGenerator>("Cmd", genCmd));
    commandMap.insert(std::pair<std::string, commandGenerator>("EndCmd", genEndCmd));
    commandMap.insert(std::pair<std::string, commandGenerator>("Wait", genWait));
    commandMap.insert(std::pair<std::string, commandGenerator>("CreateWindow", genCreateWindow));
    commandMap.insert(std::pair<std::string, commandGenerator>("ShowWindow", genShowWindow));
    commandMap.insert(std::pair<std::string, commandGenerator>("HideWindow", genHideWindow));
    commandMap.insert(std::pair<std::string, commandGenerator>("ClearWindow", genClearWindow));
    commandMap.insert(std::pair<std::string, commandGenerator>("RenderWindow", genRenderWindow));
    commandMap.insert(std::pair<std::string, commandGenerator>("DrawRect", genDrawRect));
}


std::unique_ptr<Command> Mapper::getNewCommand(std::string commandName, std::vector<std::string> params, std::vector<CommandData> & customCommands, int lineNumber)
{
    std::unique_ptr<Command> c;

    std::map<std::string, commandGenerator>::const_iterator it;
    it = commandMap.find(commandName);

    if(it == commandMap.end()){
        return std::move(getCustomCommandCall(commandName, customCommands, params, lineNumber));
    }

    commandGenerator generator = it->second;
    c = (this->*generator)(params, lineNumber);

    if(c->getNumParams() > 0 && !c->hasCorrectNumParams()){
        throw std::runtime_error("Command: " + c->getName() + " requires " + std::to_string(c->getNumParams()) + " params. At line number: " + std::to_string(lineNumber));
    }

    return std::move(c);
}

std::unique_ptr<Command> Mapper::getCustomCommandCall(std::string commandName, std::vector<CommandData> & customCommands, std::vector<std::string> params, int lineNumber)
{
    for(auto customCommand: customCommands){
        if(customCommand.getName() == commandName){
            std::vector<std::string> paramCallAddr = {std::to_string(customCommand.getLineNumber())};
            return std::move( std::make_unique<CallCommand>(paramCallAddr, lineNumber) );
        }
    }
    throw SyntaxError("Command: " + commandName + " does not exist", lineNumber);
}


std::unique_ptr<Command> Mapper::genAssign(std::vector<std::string> params, int lineNumber)
{
    return std::move(std::make_unique<Assign>(params, lineNumber));
}
std::unique_ptr<Command> Mapper::genConsoleOut(std::vector<std::string> params, int lineNumber)
{
    return std::move(std::make_unique<ConsoleOut>(params, lineNumber));
}
std::unique_ptr<Command> Mapper::genConsoleOutLn(std::vector<std::string> params, int lineNumber)
{
    return std::move(std::make_unique<ConsoleOutLn>(params, lineNumber));
}
std::unique_ptr<Command> Mapper::genConsoleIn(std::vector<std::string> params, int lineNumber)
{
    return std::move(std::make_unique<ConsoleIn>(params, lineNumber));
}
std::unique_ptr<Command> Mapper::genMemoryDump(std::vector<std::string> params, int lineNumber)
{
    return std::move(std::make_unique<MemoryDump>(params, lineNumber));
}
std::unique_ptr<Command> Mapper::genIf(std::vector<std::string> params, int lineNumber)
{
    return std::move(std::make_unique<If>(params, lineNumber));
}
std::unique_ptr<Command> Mapper::genEndIf(std::vector<std::string> params, int lineNumber)
{
    return std::move(std::make_unique<EndIf>(params, lineNumber));
}
std::unique_ptr<Command> Mapper::genWhile(std::vector<std::string> params, int lineNumber)
{
    return std::move(std::make_unique<While>(params, lineNumber));
}
std::unique_ptr<Command> Mapper::genEndWhile(std::vector<std::string> params, int lineNumber)
{
    return std::move(std::make_unique<EndWhile>(params, lineNumber));
}
std::unique_ptr<Command> Mapper::genCmd(std::vector<std::string> params, int lineNumber)
{
    return std::move(std::make_unique<CustomCommand>(params, lineNumber));
}
std::unique_ptr<Command> Mapper::genEndCmd(std::vector<std::string> params, int lineNumber)
{
    return std::move(std::make_unique<EndCustomCommand>(params, lineNumber));
}
std::unique_ptr<Command> Mapper::genWait(std::vector<std::string> params, int lineNumber)
{
    return std::move(std::make_unique<Wait>(params, lineNumber));
}
std::unique_ptr<Command> Mapper::genCreateWindow(std::vector<std::string> params, int lineNumber)
{
    return std::move(std::make_unique<CreateWindow>(params, lineNumber));
}
std::unique_ptr<Command> Mapper::genShowWindow(std::vector<std::string> params, int lineNumber)
{
    return std::move(std::make_unique<ShowWindow>(params, lineNumber));
}
std::unique_ptr<Command> Mapper::genHideWindow(std::vector<std::string> params, int lineNumber)
{
    return std::move(std::make_unique<HideWindow>(params, lineNumber));
}
std::unique_ptr<Command> Mapper::genClearWindow(std::vector<std::string> params, int lineNumber)
{
    return std::move(std::make_unique<ClearWindow>(params, lineNumber));
}
std::unique_ptr<Command> Mapper::genRenderWindow(std::vector<std::string> params, int lineNumber)
{
    return std::move(std::make_unique<RenderWindow>(params, lineNumber));
}
std::unique_ptr<Command> Mapper::genDrawRect(std::vector<std::string> params, int lineNumber)
{
    return std::move(std::make_unique<DrawRect>(params, lineNumber));
}
