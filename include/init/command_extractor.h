
#ifndef COMMAND_EXTRACTOR_H
#define COMMAND_EXTRACTOR_H

#include <string>
#include <vector>

#include "../init/extracted_line.h"
#include "../runtime/command_data.h"

class CommandExtractor{
public:
    CommandExtractor();
    ExtractedLine extract(std::vector<std::string>);
    std::vector<CommandData> getCustomCommands(std::vector<std::vector<std::string>> & formattedLines);
private:
    const int MIN_CMD_SEGMENTS = 4;
    const int CMD_SEG_POS = 0;
    const int NAME_SEG_POS = 1;
    const int BRACKET_SEG_POS = 2;
    std::vector<std::string> getParamList(std::vector<std::string>);
    std::vector<std::string> getDefineParamList(std::vector<std::string>);
};

#endif // COMMAND_EXTRACTOR_H

