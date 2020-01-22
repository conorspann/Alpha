
#ifndef PRE_PROCESSOR_H
#define PRE_PROCESSOR_H

#include <vector>
#include <string>

#include "../runtime/command_data.h"

class PreProcessor{
public:
    PreProcessor(std::vector<std::string>);
    std::vector<CommandData> getCustomCommands();
private:
    const int CMD_NAME_POS = 4;
    std::vector<CommandData> customCommands;
};

#endif // PRE_PROCESSOR_H
