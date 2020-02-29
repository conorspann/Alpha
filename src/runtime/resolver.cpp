

#include <utility>
#include <iostream>

#include "../../include/runtime/resolver.h"
#include "../../include/commands/command.h"

/** Maybe could use some sort of rule table? Similar rules e.g. for strings in Formatter
    Could then pass between classes, maybe in main or smth
  */

Resolver::Resolver()
{

}

/** TODO: Add more types + refactor */
int Resolver::determineType(std::string param)
{
    if(param.length() == 1 && calculator.isSymbol(param[0])){
        return Command::Type::SYMBOL;
    }
    if(param.find_first_not_of("0123456789-") != std::string::npos){
        return Command::Type::STRING;
    }

    return Command::Type::INT;
}

std::pair<std::string, int> & Resolver::resolveVariable(std::string variableName, DataPool & dataPool)
{
    if(variableName.length() < 2 || variableName[0] != '@'){
        throw std::runtime_error("Error: variable name not valid");
    }
    std::string identifier = variableName.substr(1);

    return dataPool.findVariable(identifier);
}

std::pair<std::string, int> Resolver::resolveParam(std::string param, DataPool & dataPool)
{
    std::pair<std::string, int> p;
    if(param[0] == '@'){
        p = resolveVariable(param, dataPool);
    }else{
        p.first = param;
        p.second = determineType(param);
    }

    return p;
}

std::string Resolver::resolve(std::string paramStr, DataPool & dataPool)
{
    return calculator.calculate(parseParam(paramStr, dataPool));
}

void Resolver::addParam(std::vector<std::pair<std::string, int>> & parsedParam, DataPool & dataPool, std::string strVal)
{
    std::pair<std::string, int> varData;
    varData = resolveParam(strVal, dataPool);
    if(varData.second != Command::Type::STRING && varData.first.length() > 1){
        if(varData.first[0] == '-'){
            varData.first = varData.first.substr(1);
            std::string minusSymbol = "-";
            std::pair<std::string, int> symbol(minusSymbol, Command::Type::SYMBOL);
            parsedParam.push_back(symbol);
        }
    }
    parsedParam.push_back(varData);
}

void Resolver::addChar(std::string & currentParam, char paramChar)
{
    if(paramChar != '\"'){
        currentParam += paramChar;
    }
}

/**
    REFACTOR !!
*/
std::vector<std::pair<std::string, int>> Resolver::parseParam(std::string param, DataPool & dataPool)
{
    std::vector<std::pair<std::string, int>> parsedParam;
    std::string currentStrVal;
    bool isString = false;
    int lastCharIndex = param.length() - 1;
    for(int charIndex = 0; charIndex < param.length(); charIndex++){
        char paramChar = param[charIndex];
        if(paramChar == '\"'){
            isString = !isString;
        }
        if(calculator.isSymbol(paramChar) && !isString){
            if(!currentStrVal.empty()){
                addParam(parsedParam, dataPool, currentStrVal);
            }
            std::string symbolStr(std::string(1, paramChar));
            addParam(parsedParam, dataPool, symbolStr);
            currentStrVal = "";
            continue;
        }else if(charIndex == lastCharIndex){
            addChar(currentStrVal, paramChar);
            addParam(parsedParam, dataPool, currentStrVal);
            break;
        }
        addChar(currentStrVal, paramChar);
    }

    return parsedParam;
}

