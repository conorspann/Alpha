
#include <iostream>
#include <stdexcept>
#include <memory>
#include <utility>

#include "../../include/init/parser.h"



std::string Parser::parse(std::vector<std::pair<int, std::vector<std::string>>> & segmentedData)
{
    std::string commandsStr = parseCustomCommands(segmentedData);
    commandsStr += parseCommands(segmentedData);

    return commandsStr;
}

std::string Parser::parseCustomCommands(std::vector<std::pair<int, std::vector<std::string>>> & segmentedData)
{
    CommandExtractor commandExtractor;
    std::vector<CommandData> customCommands = commandExtractor.getCustomCommands(segmentedData);
    std::string customCommandsStr = "{";
    for (int customCommandIndex = 0; customCommandIndex < customCommands.size(); customCommandIndex++) {
        CommandData customCommand = customCommands[customCommandIndex];
        customCommandsStr += getCommandString(
            customCommand.getLineNumber(),
            customCommand.getName(),
            customCommand.getParams()
        );
    }
    customCommandsStr += "}";

    return customCommandsStr;
}

std::string Parser::parseCommands(std::vector<std::pair<int, std::vector<std::string>>> & segmentedData)
{
    CommandExtractor commandExtractor;
    std::string commandsStr = "{";
    for(auto segmentedLine : segmentedData){
        int lineNumber = segmentedLine.first;
        ExtractedLine extractedLine = commandExtractor.extract(segmentedLine.second);
        checkCommandIsExtracted(extractedLine, lineNumber);
        commandsStr += getCommandString(
            lineNumber,
            extractedLine.getCommandStr(),
            extractedLine.getParamList()
        );
    }
    commandsStr += "}";

    return commandsStr;
}

std::string Parser::getCommandString(int lineNumber, std::string commandName, std::vector<std::string> params)
{
    std::string customCommandsStr = "[";

    customCommandsStr += std::to_string(lineNumber);
    customCommandsStr += "]";
    customCommandsStr += commandName;

    customCommandsStr += "(";
    for (int paramIndex = 0; paramIndex < params.size(); paramIndex++) {
        customCommandsStr += params[paramIndex];
        if (paramIndex < params.size() - 1) {
            customCommandsStr += ",";
        }
    }
    customCommandsStr += ")";

    customCommandsStr += ";";

    return customCommandsStr;
}

void Parser::checkCommandIsExtracted(ExtractedLine extractedLine, int lineNumber)
{
    if(extractedLine.getCommandStr() == ""){
        throw std::runtime_error(
            "Error: Could not extract command from line. At line number: " +
            std::to_string(lineNumber)
        );
    }
}
