

#include <utility>
#include <iostream>

#include "../../include/runtime/resolver.h"
#include "../../include/commands/command.h"

/**
    Maybe could use some sort of rule table? Similar rules e.g. for strings in Formatter
    Could then pass between classes, maybe in main or smth
*/


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
    if(param[0] == '@'){
        return resolveVariable(param, dataPool);
    }

    std::pair<std::string, int> p;
    p.first = param;
    p.second = determineType(param);

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
    if(
        variableIsMinusNumber(varData)
    ){
        varData.first = varData.first.substr(1);
        addMinusSymbol(parsedParam);
    }
    parsedParam.push_back(varData);
}

bool Resolver::variableIsMinusNumber(std::pair<std::string, int> varData)
{
    return varData.second != Command::Type::STRING &&
           varData.first.length() > 1 &&
           varData.first[0] == '-';
}

void Resolver::addMinusSymbol(std::vector<std::pair<std::string, int>> & parsedParam)
{
    std::string minusSymbol = "-";
    std::pair<std::string, int> symbol(minusSymbol, Command::Type::SYMBOL);
    parsedParam.push_back(symbol);
}

void Resolver::addChar(std::string & currentParam, char paramChar)
{
    if(paramChar != '\"'){
        currentParam += paramChar;
    }
}


std::vector<std::pair<std::string, int>> Resolver::parseParam(std::string param, DataPool & dataPool)
{
    std::vector<std::pair<std::string, int>> parsedParam;
    std::string currentStrVal;
    bool insideString = false;
    int lastCharIndex = param.length() - 1;
    for(int charIndex = 0; charIndex < param.length(); charIndex++){
        char paramChar = param[charIndex];
        if(paramChar == '\"'){
            insideString = !insideString;
        }
        if(calculator.isSymbol(paramChar) && !insideString){
            addParamAndSymbol(currentStrVal, paramChar, parsedParam, dataPool);
            continue;
        }
        if(charIndex == lastCharIndex){
            addFinalParam(currentStrVal, paramChar, parsedParam, dataPool);
            break;
        }
        addChar(currentStrVal, paramChar);
    }

    return parsedParam;
}


void Resolver::addParamAndSymbol(std::string & currentStrVal, char paramChar, std::vector<std::pair<std::string, int>> & parsedParam, DataPool & dataPool)
{
    addPreviousParam(currentStrVal, parsedParam, dataPool);
    addSymbolParam(paramChar, parsedParam, dataPool);
    currentStrVal = "";
}

void Resolver::addFinalParam(std::string & currentStrVal, char paramChar, std::vector<std::pair<std::string, int>> & parsedParam, DataPool & dataPool)
{
    addChar(currentStrVal, paramChar);
    addParam(parsedParam, dataPool, currentStrVal);
}

void Resolver::addPreviousParam(std::string & currentStrVal, std::vector<std::pair<std::string, int>> & parsedParam, DataPool & dataPool)
{
    if(!currentStrVal.empty()){
        addParam(parsedParam, dataPool, currentStrVal);
    }
}

void Resolver::addSymbolParam(char paramChar, std::vector<std::pair<std::string, int>> & parsedParam, DataPool & dataPool)
{
    std::string symbolStr(std::string(1, paramChar));
    addParam(parsedParam, dataPool, symbolStr);
}

