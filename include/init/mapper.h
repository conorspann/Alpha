
#ifndef MAPPER_H
#define MAPPER_H

#include "../commands/command.h"
#include "../runtime/command_data.h"

#include <map>
#include <string>
#include <memory>

class Mapper{
public:
    std::unique_ptr<Command> getNewCommand(std::string, std::vector<std::string>, std::vector<CommandData> &);
};

#endif // MAPPER_H
