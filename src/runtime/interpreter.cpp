
#include "../../include/runtime/interpreter.h"

#include <vector>
#include <memory>
#include <utility>
#include <iostream>
#include <map>

Interpreter::Interpreter(std::vector<std::unique_ptr<Command>> cmds):
    commands(std::move(cmds))
{

}

void Interpreter::execute()
{
    for(int cmdPtr = 0; cmdPtr < commands.size(); cmdPtr++){
        commands[cmdPtr]->execute(resolver, &globalDataPool, commands, &cmdPtr);
    }
}
