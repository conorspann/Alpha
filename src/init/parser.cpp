
#include <iostream>
#include <stdexcept>
#include <memory>
#include <utility>

#include "../../include/init/parser.h"
#include "../../include/commands/console_out.h"

Parser::Parser()
{

}

std::vector<std::unique_ptr<Command>> Parser::parse(std::vector<std::pair<int, std::vector<std::string>>> & segmentedData)
{
    CommandExtractor commandExtractor;
    std::vector<CommandData> customCommands = commandExtractor.getCustomCommands(segmentedData);
    std::vector<std::unique_ptr<Command>> commands;
    for(auto segmentedLine : segmentedData){
        std::unique_ptr<Command> cmd = std::move(getCommand(commandExtractor, segmentedLine.first, segmentedLine.second, customCommands));
        commands.push_back(std::move(cmd));
    }

    return std::move(commands);
}
//may throw exception
std::unique_ptr<Command> Parser::getCommand(CommandExtractor & commandExtractor, int lineNumber, std::vector<std::string> segmentedLine,  std::vector<CommandData> & customCommands)
{
    ExtractedLine extractedLine = commandExtractor.extract(segmentedLine);
    if(extractedLine.getCommandStr() == ""){
        throw std::runtime_error("Error: Could not extract command from line. At line number: " + std::to_string(lineNumber));
    }

    std::unique_ptr<Command> command = mapper.getNewCommand(extractedLine.getCommandStr(), extractedLine.getParamList(), customCommands, lineNumber);

    return std::move(command);
}
