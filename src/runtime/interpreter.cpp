

#include <vector>
#include <memory>
#include <utility>
#include <iostream>
#include <map>

#include "../../include/runtime/interpreter.h"
#include "../../include/runtime/environment.h"

Interpreter::Interpreter(std::vector<std::unique_ptr<Command>> cmds):
    commands(std::move(cmds))
{

}

void Interpreter::execute()
{
    Environment environment;
    for(int cmdPtr = 0; cmdPtr < commands.size(); cmdPtr++){
        commands[cmdPtr]->execute(environment, commands, &cmdPtr);
    }
}
