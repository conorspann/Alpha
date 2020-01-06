

#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "command.h"
#include "poly_var.h"
#include "resolver.h"

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
    Resolver resolver;
};

#endif // INTERPRETER_H
