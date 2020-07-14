
#ifndef PARSER_H
#define PARSER_H

#include "command_extractor.h"

#include <vector>
#include <string>
#include <map>
#include <memory>

class Parser{
public:
    std::string parse(std::vector<std::pair<int, std::vector<std::string>>> &);
private:
    std::string parseCustomCommands(std::vector<std::pair<int, std::vector<std::string>>> & segmentedData);
    std::string parseCommands(std::vector<std::pair<int, std::vector<std::string>>> & segmentedData);
    std::string getCommandString(int lineNumber, std::string commandName, std::vector<std::string> params);
    void checkCommandIsExtracted(ExtractedLine extractedLine, int lineNumber);
};

#endif // PARSER_H
