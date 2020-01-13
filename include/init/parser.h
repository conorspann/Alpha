
#ifndef PARSER_H
#define PARSER_H

#include "../formatter/formatter.h"

#include <vector>
#include <string>
#include <map>

#include "../commands/command.h"
#include "mapper.h"

#include <memory>

class Parser{
public:
    Parser(std::vector<std::string>);
    std::vector<std::unique_ptr<Command>> parse();
private:
    std::vector<std::string> data;
    Formatter formatter;
    Mapper mapper;
    std::unique_ptr<Command> getCommand(std::string);
    std::string getWord(std::string);
    void getParameters(std::string);
};

#endif // PARSER_H
