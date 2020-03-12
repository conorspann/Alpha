
#include <iostream>
#include <vector>
#include <string>

#include "../../include/init/command_extractor.h"
#include "../../include/init/extracted_line.h"
#include "../../include/formatter/formatter.h"
#include "../../include/exception/syntax_error.h"


CommandExtractor::CommandExtractor()
{

}


ExtractedLine CommandExtractor::extract(std::vector<std::string> segmentedLine)
{
    if(segmentedLine.size() < 1){
        throw std::runtime_error("Error: Blank statement");
    }
    std::string cmdStr;
    std::vector<std::string> paramList;
    std::string firstSeg = segmentedLine[0];
    if(Formatter::isSymbol(firstSeg[0])){
        if(firstSeg != "@"){
            throw std::runtime_error("Error: Erroneous symbol in command.");
        }
        cmdStr = firstSeg;
        paramList = getDefineParamList(segmentedLine);
    }else{
        cmdStr = segmentedLine[0];
        paramList = getParamList(segmentedLine);
    }
    ExtractedLine extractedLine(cmdStr, paramList);

    return extractedLine;
}


std::vector<std::string> CommandExtractor::getParamList(std::vector<std::string> segmentedLine)
{
    std::vector<std::string> paramList;

    if(segmentedLine.size() < 2 || segmentedLine[0] == "Cmd"){
        return paramList;
    }
    std::string param;
    for(int segmentNumber = 2; segmentNumber < segmentedLine.size() - 1; segmentNumber++){
        std::string segment = segmentedLine[segmentNumber];
        if(segment == ","){
            paramList.push_back(param);
            param = "";
            continue;
        }
        param += segment;
        if(segmentNumber == segmentedLine.size() - 2){
            paramList.push_back(param);
            param = "";
        }
    }

    return paramList;
}


std::vector<std::string> CommandExtractor::getDefineParamList(std::vector<std::string> segmentedLine)
{
    std::vector<std::string> defineParamList;
    if(segmentedLine.size() < 4 || segmentedLine[2] != "="){
        throw std::runtime_error("Error: Malformed assignment.");
    }
    defineParamList.push_back(segmentedLine[1]);
    std::string params;
    for(int segmentNumber = 3; segmentNumber < segmentedLine.size(); segmentNumber++){
        params += segmentedLine[segmentNumber];
    }
    defineParamList.push_back(params);

    return defineParamList;
}

std::vector<CommandData> CommandExtractor::getCustomCommands(std::vector<std::pair<int, std::vector<std::string>>> & formattedLines)
{
    std::vector<CommandData> customCommands;
    for(int lineNumber = 0; lineNumber < formattedLines.size(); lineNumber++){
        std::vector<std::string> tokenLine = formattedLines[lineNumber].second;
        if(!tokensAreValid(tokenLine, formattedLines[lineNumber].first)){
            continue;
        }
        std::vector<std::string> params = extractParams(tokenLine);
        std::string cmdName = tokenLine[NAME_SEG_POS];
        CommandData customCommand(lineNumber, cmdName, params);
        customCommands.push_back(customCommand);
    }

    return customCommands;
}


bool CommandExtractor::tokensAreValid(std::vector<std::string> tokenLine, int preservedLineNumber)
{
    if(tokenLine.size() < MIN_CMD_SEGMENTS || tokenLine[CMD_SEG_POS] != "Cmd"){
        return false;
    }
    std::string cmdName = tokenLine[NAME_SEG_POS];
    if(cmdName.empty()){
        throw SyntaxError("Error: Custom command name cannot be blank.", preservedLineNumber);
    }
    if(Formatter::isSymbol(cmdName[0])){
        throw SyntaxError("Error: Custom command name cannot start with a symbol.", preservedLineNumber);
    }
    std::string bracketToken = tokenLine[BRACKET_SEG_POS];
    if(bracketToken != "("){
        throw SyntaxError("Error: Custom command missing start parameter bracket.", preservedLineNumber);
    }
    if(tokenLine[tokenLine.size() - 1] != ")"){
        throw SyntaxError("Error: Custom command missing end parameter bracket.", preservedLineNumber);
    }

    return true;
}

std::vector<std::string> CommandExtractor::extractParams(std::vector<std::string> tokenLine)
{
    std::string param;
    std::vector<std::string> params;
    for(int tokenNumber = BRACKET_SEG_POS + 1; tokenNumber < tokenLine.size(); tokenNumber++){
        std::string token = tokenLine[tokenNumber];
        if(token == ")"){
            break;
        }
        if(token == ","){
            params.push_back(param);
            param = "";
            continue;
        }
        param += token;
        if(tokenNumber == tokenLine.size() - 2){
            params.push_back(param);
            param = "";
        }
    }

    return params;
}
