
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
    Resolver resolver;
    Searcher searcher;
    for(int cmdPtr = 0; cmdPtr < commands.size(); cmdPtr++){
        commands[cmdPtr]->execute(resolver, searcher, &globalDataPool, commands, &cmdPtr);
    }
}
