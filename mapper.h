
#ifndef MAPPER_H
#define MAPPER_H

#include "command.h"
#include <map>
#include <string>
#include <memory>

class Mapper{
public:
    std::unique_ptr<Command> getNewCommand(std::string, std::vector<std::string>);
};

#endif // MAPPER_H
