
#ifndef COMMAND_EXTRACTOR_H
#define COMMAND_EXTRACTOR_H

#include <string>
#include <vector>

#include "../init/extracted_line.h"

class CommandExtractor{
public:
    CommandExtractor();
    ExtractedLine extract(std::vector<std::string>);
private:
    std::vector<std::string> getParamList(std::vector<std::string>);
    std::vector<std::string> getDefineParamList(std::vector<std::string>);
};

#endif // COMMAND_EXTRACTOR_H

