
#include <iostream>
#include <stdexcept>
#include <memory>
#include <utility>

#include "../../include/init/parser.h"
#include "../../include/commands/console_out.h"

Parser::Parser()
{

}

std::vector<std::unique_ptr<Command>> Parser::parse(std::vector<std::vector<std::string>> & segmentedData)
{
    std::vector<std::unique_ptr<Command>> commands;
    for(auto segmentedLine : segmentedData){
        std::unique_ptr<Command> cmd = std::move(getCommand(segmentedLine));
        commands.push_back(std::move(cmd));
    }

    return std::move(commands);
}
//may throw exception
std::unique_ptr<Command> Parser::getCommand(std::vector<std::string> segmentedLine)
{
    ExtractedLine extractedLine = commandExtractor.extract(segmentedLine);
    if(extractedLine.getCommandStr() == ""){
        throw std::runtime_error("Error: Could not extract command from line.");
    }

    std::unique_ptr<Command> command = mapper.getNewCommand(extractedLine.getCommandStr(), extractedLine.getParamList());

    return std::move(command);
}
