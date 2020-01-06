
#include "formatter.h"
#include "formatted_line.h"

#include <iostream>
#include <vector>
#include <string>

Formatter::Formatter()
{

}

// Maybe split this class into other classes

FormattedLine Formatter::format(std::string line)
{
    std::string modLine = removeWhiteSpace(line);
    std::string cmdStr;
    std::vector<std::string> paramList;
    if(modLine[0] == '@'){
        cmdStr = "@";
        paramList = getDefineParamList(modLine);
    }else{
        cmdStr = getCommandStr(modLine);
        paramList = getParamList(modLine);
    }
    FormattedLine formattedLine(cmdStr, paramList);

    return formattedLine;
}

std::string Formatter::removeWhiteSpace(std::string line)
{
    std::string newLine;
    bool noRemove = false;
    for(int i = 0; i < line.length(); i++){
        char c = line[i];
        if(c == '\"'){
            noRemove = !noRemove;
        }
        if(!isWhiteSpace(c) || noRemove){
            newLine += c;
        }
    }

    return newLine;
}

bool Formatter::isWhiteSpace(char c)
{
    if(c == ' ' || c == '\t'){
        return true;
    }

    return false;
}

// Refactor
std::string Formatter::getCommandStr(std::string line)
{
    std::string cmd;
    for(int i = 0; i < line.length(); i++){
        char c = line[i];
        if(isWhiteSpace(c) || c == '('){
            break;
        }
        cmd += c;
    }
    return cmd;
}


std::vector<std::string> Formatter::getParamList(std::string line)
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

std::string Formatter::findParams(std::string line)
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

std::vector<std::string> Formatter::getDefineParamList(std::string line)
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
