

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

std::pair<std::string, int> & Resolver::resolveVariable(std::string variableName, std::map<std::string, std::pair<std::string, int>> & globalDataPool)
{
    if(variableName.length() < 2 || variableName[0] != '@'){
        throw std::runtime_error("Error: variable name not valid");
    }
    std::string identifier = variableName.substr(1);
    std::map<std::string, std::pair<std::string, int>>::iterator it;
    it = globalDataPool.find(identifier);
    if(it == globalDataPool.end()){
        throw std::runtime_error("Error: Null variable in command.");
    }

    return it->second;
}

std::pair<std::string, int> Resolver::resolveParam(std::string param, std::map<std::string, std::pair<std::string, int>> & globalDataPool)
{
    std::pair<std::string, int> p;
    if(param[0] == '@'){
        p = resolveVariable(param, globalDataPool);
    }else{
        p.first = param;
        p.second = determineType(param);
    }

    return p;
}

std::string Resolver::resolve(std::string paramStr, std::map<std::string, std::pair<std::string, int>> & globalDataPool)
{
    return calculator.calculate(parseParam(paramStr, globalDataPool));
}

void Resolver::addParam(std::vector<std::pair<std::string, int>> & parsedParam, std::map<std::string, std::pair<std::string, int>> & globalDataPool, std::string strVal)
{
    std::pair<std::string, int> varData;
    varData = resolveParam(strVal, globalDataPool);
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
std::vector<std::pair<std::string, int>> Resolver::parseParam(std::string param, std::map<std::string, std::pair<std::string, int>> & globalDataPool)
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
                addParam(parsedParam, globalDataPool, currentStrVal);
            }
            std::string symbolStr(std::string(1, paramChar));
            addParam(parsedParam, globalDataPool, symbolStr);
            currentStrVal = "";
            continue;
        }else if(charIndex == lastCharIndex){
            addChar(currentStrVal, paramChar);
            addParam(parsedParam, globalDataPool, currentStrVal);
            break;
        }
        addChar(currentStrVal, paramChar);
    }

    return parsedParam;
}

