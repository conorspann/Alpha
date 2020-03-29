

#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "../commands/command.h"
#include "resolver.h"
#include "searcher.h"

#include <memory>
#include <vector>
#include <utility>
#include <map>

class Interpreter{
public:
    Interpreter(std::vector<std::unique_ptr<Command>>);
    void execute();
private:
    std::vector<std::unique_ptr<Command>> commands;
    std::vector<std::string> createLabels();
};

#endif // INTERPRETER_H
