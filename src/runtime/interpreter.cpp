

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
    std::vector<std::string> labels = createLabels();
    Environment environment(labels);
    for(int cmdPtr = 0; cmdPtr < commands.size(); cmdPtr++){
        commands[cmdPtr]->execute(environment, &cmdPtr);
    }
}

std::vector<std::string> Interpreter::createLabels()
{
    std::vector<std::string> labels;
    for(int lineNumber = 0; lineNumber < commands.size(); lineNumber++){
        std::string label = commands[lineNumber]->getName();
        labels.push_back(label);
    }

    return labels;
}
