
#include "../../include/init/preprocessor.h"

#include <stdexcept>

PreProcessor::PreProcessor(std::vector<std::string> fileLines)
{
    for(int lineIndex = 0; lineIndex < fileLines.size(); lineIndex++){
        std::string line = fileLines[lineIndex];
        int cmdPos = line.find("Cmd ");
        if(cmdPos == std::string::npos){
            continue;
        }
        int cmdNamePos = cmdPos + CMD_NAME_POS;
        std::string cmdName;
        for(int charPos = cmdNamePos; charPos < line.length(); charPos++){
            if(line[charPos] == '('){
                break;
            }
            cmdName += line[charPos];
        }
        if(cmdName.empty()){
            throw std::runtime_error("Error: Custom command does not have a name.");
        }
        int paramPos = line.find("(");
        if(paramPos == std::string::npos){
            throw std::runtime_error("Error: Missing parentheses in custom command.");
        }
        paramPos += 1; // skip bracket
        std::vector<std::string> params;
        std::string param;
        for(int charPos = paramPos; charPos < line.length(); charPos++){
            if(line[charPos] == ')'){
                if(!param.empty()){
                    params.push_back(param);
                } // allow no params
                break;
            }
            if(line[charPos] == ','){
                if(param.empty()){
                    throw std::runtime_error("Error, unexpected comma separator in custom command.");
                }
                params.push_back(param);
                param = "";
            }
            param += line[charPos];
        }
        CommandData customCommand(lineIndex, cmdName, params);
        customCommands.push_back(customCommand);
    }
}

std::vector<CommandData> PreProcessor::getCustomCommands()
{
    return customCommands;
}
