
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
        if(i != ""){
            std::string formattedLine = formatter.removeWhiteSpace(i);
            // pre processor here?
            std::unique_ptr<Command> cmd = std::move(getCommand(formattedLine));
            if(cmd != nullptr){
                commands.push_back(std::move(cmd));
            }
        }
    }

    return std::move(commands);
}
//may throw exception
std::unique_ptr<Command> Parser::getCommand(std::string fileLine)
{
    // put formatter as a step before parser and preprocessor but after loader
    ExtractedLine extractedLine = commandExtractor.extract(fileLine);
    if(extractedLine.getCommandStr() == ""){
        return nullptr;
    }
    std::unique_ptr<Command> command = mapper.getNewCommand(extractedLine.getCommandStr(), extractedLine.getParamList());
    //maybe add another mapper function to map params?
    //maybe create new class DataType and check for type

    return std::move(command);
}
