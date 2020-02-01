

#include <vector>
#include <memory>
#include <utility>
#include <iostream>
#include <map>

#include "../../include/runtime/interpreter.h"


Interpreter::Interpreter(std::vector<std::unique_ptr<Command>> cmds):
    commands(std::move(cmds))
{

}

void Interpreter::execute()
{
    /** Could group these objects together in an Environment class, as well as the global data pool*/
    std::stack<int> callStack;
    Resolver resolver;
    Searcher searcher;

    for(int cmdPtr = 0; cmdPtr < commands.size(); cmdPtr++){
        commands[cmdPtr]->execute(resolver, searcher, &globalDataPool, callStack, commands, &cmdPtr);
    }
}
