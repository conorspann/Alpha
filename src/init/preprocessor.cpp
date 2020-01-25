
#include "../../include/init/preprocessor.h"
#include "../../include/formatter/formatter.h"

#include <stdexcept>

PreProcessor::PreProcessor()
{

}

std::vector<CommandData> PreProcessor::getCustomCommands(std::vector<std::vector<std::string>> & formattedLines)
{
    std::vector<CommandData> customCommands;
    for(int lineNumber = 0; lineNumber < formattedLines.size(); lineNumber++){
        std::vector<std::string> line = formattedLines[lineNumber];
        if(line.size() < MIN_CMD_SEGMENTS){
            continue;
        }
        std::string segment = line[CMD_SEG_POS];
        if(segment != "Cmd"){
            continue;
        }
        std::string cmdName = line[NAME_SEG_POS];
        if(Formatter::isSymbol(cmdName[0])){
            throw std::runtime_error("Error: Custom command name is not valid.");
        }
        segment = line[BRACKET_SEG_POS];
        if(segment != "(" || line[line.size() - 1] != ")"){
            throw std::runtime_error("Error: Custom command missing bracket.");
        }
        // loop through params if they exist
        std::string param;
        std::vector<std::string> params;
        for(int segNumber = BRACKET_SEG_POS + 1; segNumber < line.size(); segNumber++){
            std::string segment = line[segNumber];
            if(segment == ")"){
                break;
            }
            if(segment == ","){
                params.push_back(param);
                param = "";
                continue;
            }
            param += segment;
            if(segNumber == line.size() - 2){
                params.push_back(param);
                param = "";
            }
        }
        CommandData customCommand(lineNumber, cmdName, params);
        customCommands.push_back(customCommand);
    }

    return customCommands;
}
