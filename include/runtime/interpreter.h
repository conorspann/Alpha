

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
    std::map<std::string, std::pair<std::string, int>> globalDataPool;
};

#endif // INTERPRETER_H
