
#ifndef PRE_PROCESSOR_H
#define PRE_PROCESSOR_H

#include <vector>
#include <string>

#include "../runtime/command_data.h"

class PreProcessor{
public:
    PreProcessor();
    std::vector<std::string> includeFiles(std::vector<std::string>);
    std::vector<CommandData> getCustomCommands(std::vector<std::vector<std::string>> &);
private:
    const int MIN_CMD_SEGMENTS = 4;
    const int CMD_SEG_POS = 0;
    const int NAME_SEG_POS = 1;
    const int BRACKET_SEG_POS = 2;
    std::vector<CommandData> customCommands;
};

#endif // PRE_PROCESSOR_H
