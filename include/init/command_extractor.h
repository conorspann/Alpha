
#ifndef COMMAND_EXTRACTOR_H
#define COMMAND_EXTRACTOR_H

#include <string>
#include <vector>

#include "../init/extracted_line.h"

class CommandExtractor{
public:
    CommandExtractor();
    ExtractedLine extract(std::string);
private:
    std::string getCommandStr(std::string);
    std::vector<std::string> getParamList(std::string);
    std::vector<std::string> getDefineParamList(std::string);
    std::string findParams(std::string);
};

#endif // COMMAND_EXTRACTOR_H

