
#ifndef PARSER_H
#define PARSER_H

#include "extracted_line.h"
#include "command_extractor.h"
#include "../commands/command.h"

#include <vector>
#include <string>
#include <map>

#include "mapper.h"

#include <memory>

class Parser{
public:
    Parser();
    std::vector<std::unique_ptr<Command>> parse(std::vector<std::vector<std::string>> &);
private:
    CommandExtractor commandExtractor;
    Mapper mapper;
    std::unique_ptr<Command> getCommand(std::vector<std::string>);
};

#endif // PARSER_H
