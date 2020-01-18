
#include "../../include/init/command_extractor.h"
#include "../../include/init/extracted_line.h"

#include <iostream>
#include <vector>
#include <string>

CommandExtractor::CommandExtractor()
{

}

// Maybe split this class into other classes


ExtractedLine CommandExtractor::extract(std::string modLine)
{
    std::string cmdStr;
    std::vector<std::string> paramList;
    if(modLine[0] == '@'){
        cmdStr = "@";
        paramList = getDefineParamList(modLine);
    }else{
        cmdStr = getCommandStr(modLine);
        paramList = getParamList(modLine);
    }
    ExtractedLine extractedLine(cmdStr, paramList);

    return extractedLine;
}


// Refactor
std::string CommandExtractor::getCommandStr(std::string line)
{
    std::string cmd;
    for(int i = 0; i < line.length(); i++){
        char c = line[i];
        if(c == ' ' || c == '\t' || c == '('){
            break;
        }
        cmd += c;
    }
    return cmd;
}


std::vector<std::string> CommandExtractor::getParamList(std::string line)
{
    std::string paramStr = findParams(line);
    std::vector<std::string> paramList;
    std::string param;
    bool isString = false;
    for(int i = 0; i < paramStr.length(); i++){
        char c = paramStr[i];
        if(c == '\"'){
            isString = !isString;
        }
        if(c != ',' || isString){
            param += c;
        }
        if(( (c == ',' && !isString) || i == paramStr.length() - 1) && !param.empty()){
            paramList.push_back(param);
            param = "";
            continue;
        }
    }
    return paramList;
}

std::string CommandExtractor::findParams(std::string line)
{
    std::string params;
    bool startParams = false;
    for(int i = 0; i < line.length(); i++){
        char c = line[i];
        if(c == '('){
            startParams = true;
            continue;
        }else if(c == ')'){
            break;
        }
        if(startParams == true){
            params += c;
        }
    }

    return params;
}

std::vector<std::string> CommandExtractor::getDefineParamList(std::string line)
{
    std::vector<std::string> defineParamList;
    std::string paramLine = line.substr(1, std::string::npos);
    for(int i = 0; i < paramLine.length(); i++){
        if(paramLine[i] == '='){
            // maybe add another if here to checck if i+1 == =
            // for a interpreting IF statements and equivalenc
            defineParamList.push_back(paramLine.substr(0, i));
            defineParamList.push_back(paramLine.substr(i+1, std::string::npos));
            //TODO NEED TO CHECK THIS WORKS!!!!!!!!!!!!!!!!!!
            return defineParamList;
        }
    }
    defineParamList.push_back(paramLine);
    return defineParamList;
}

