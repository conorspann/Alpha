
#include <iostream>
#include <stdexcept>
#include <memory>
#include <utility>

#include "../../include/init/parser.h"
#include "../../include/commands/console_out.h"

Parser::Parser(std::vector<std::string> fileData):
    data(fileData)
{

}

std::vector<std::unique_ptr<Command>> Parser::parse()
{
    std::vector<std::unique_ptr<Command>> commands;
    for(auto &i : data){
        std::unique_ptr<Command> cmd = std::move(getCommand(i));
        commands.push_back(std::move(cmd));
    }

    return std::move(commands);
}
//may throw exception
std::unique_ptr<Command> Parser::getCommand(std::string fileLine)
{
    // put formatter as a step before parser and preprocessor but after loader
    ExtractedLine extractedLine = commandExtractor.extract(fileLine);
    if(extractedLine.getCommandStr() == ""){
        throw std::runtime_error("Error: Could not extract command from line: " + fileLine);
    }

    std::unique_ptr<Command> command = mapper.getNewCommand(extractedLine.getCommandStr(), extractedLine.getParamList());
    //maybe add another mapper function to map params?
    //maybe create new class DataType and check for type

    return std::move(command);
}
