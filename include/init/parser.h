
#ifndef PARSER_H
#define PARSER_H

#include "command_extractor.h"
#include "../commands/command.h"
#include "mapper.h"

#include <vector>
#include <string>
#include <map>
#include <memory>

class Parser{
public:
    std::vector<std::unique_ptr<Command>> parse(std::vector<std::pair<int, std::vector<std::string>>> &);
private:
    Mapper mapper;
    std::unique_ptr<Command> getCommand(CommandExtractor &, int, std::vector<std::string>, std::vector<CommandData> &);
    void checkCommandIsExtracted(ExtractedLine extractedLine, int lineNumber);
};

#endif // PARSER_H
