
#ifndef PRE_PROCESSOR_H
#define PRE_PROCESSOR_H

#include <vector>
#include <string>

#include "../commands/custom_command.h"

class PreProcessor{
public:
    PreProcessor(std::vector<std::string>);
    std::vector<CustomCommand> getCustomCommands();
private:
    const int CMD_NAME_POS = 4;
    std::vector<CustomCommand> customCommands;
};

#endif // PRE_PROCESSOR_H
