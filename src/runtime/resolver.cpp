

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

std::pair<std::string, int> Resolver::resolveParam(std::string param, const std::map<std::string, std::pair<std::string, int>> & globalDataPool)
{
    std::string identifier = param.substr(1, std::string::npos);
    std::map<std::string, std::pair<std::string, int>>::const_iterator it;
    it = globalDataPool.find(identifier);
    std::pair<std::string, int> data("Null", Command::Type::UNKNOWN);
    if(it != globalDataPool.end()){
        data.first = it->second.first; //value
        data.second = it->second.second; //type
    }
    return data;
}

std::pair<std::string, int> Resolver::getData(std::string param, const std::map<std::string, std::pair<std::string, int>> & globalDataPool)
{
    std::pair<std::string, int> p;
    if(param[0] == '@'){
        p = resolveParam(param, globalDataPool);
    }else{
        p.first = param;
        p.second = determineType(param);
    }

    return p;
}

std::string Resolver::resolve(std::string paramStr,  const std::map<std::string, std::pair<std::string, int>> & globalDataPool)
{
    return calculator.calculate(parseParam(paramStr, globalDataPool));
}

void Resolver::setData(std::vector<std::pair<std::string, int>> & parsedParam, const std::map<std::string, std::pair<std::string, int>> & globalDataPool, std::string strVal)
{
    std::pair<std::string, int> varData;
    varData = getData(strVal, globalDataPool);
    if(varData.first == "Null" || varData.second == Command::Type::UNKNOWN){
        throw std::runtime_error("Error: Null variable in command.");
    }
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
std::vector<std::pair<std::string, int>> Resolver::parseParam(std::string param, const std::map<std::string, std::pair<std::string, int>> & globalDataPool)
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
                setData(parsedParam, globalDataPool, currentStrVal);
            }
            std::string symbolStr(std::string(1, paramChar));
            setData(parsedParam, globalDataPool, symbolStr);
            currentStrVal = "";
            continue;
        }else if(charIndex == lastCharIndex){
            addChar(currentStrVal, paramChar);
            setData(parsedParam, globalDataPool, currentStrVal);
            break;
        }
        addChar(currentStrVal, paramChar);
    }

    return parsedParam;
}

