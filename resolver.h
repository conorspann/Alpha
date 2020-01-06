
#ifndef RESOLVER_H
#define RESOLVER_H

#include <string>
#include <map>
#include <vector>

class Resolver;
class Command;

#include "command.h"
#include "calculator.h"

class Resolver{
public:
    Resolver();
    std::string resolve(std::string, const std::map<std::string, std::pair<std::string, int>> *);
    std::pair<std::string, int> isVariable(std::string, const std::map<std::string, std::pair<std::string, int>> *);
    int findLabel(std::string startLabel, std::string endLabel, int, bool, std::vector<std::unique_ptr<Command>> & cmds, int * cmdPtr);
private:
    Calculator calculator;
    int determineType(std::string param);
    std::vector<std::pair<std::string, int>> parseParam(std::string, const std::map<std::string, std::pair<std::string, int>> *);
};

#endif // RESOLVER_H
