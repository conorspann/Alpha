
#include "../../include/runtime/resolver.h"

#include <utility>
#include <iostream>


/** Maybe could use some sort of rule table? Similar rules e.g. for strings in Formatter
    Could then pass between classes, maybe in main or smth
  */

Resolver::Resolver()
{

}

 /** Update, refactor etc */
int Resolver::determineType(std::string param)
{
    if(param.find_first_not_of("0123456789") != std::string::npos){
        return Command::Type::STRING;
    }

    return Command::Type::INT;
}

std::pair<std::string, int> Resolver::resolveParam(std::string param, const std::map<std::string, std::pair<std::string, int>> * globalDataPool)
{
    std::string identifier = param.substr(1, std::string::npos);
    std::map<std::string, std::pair<std::string, int>>::const_iterator it;
    it = globalDataPool->find(identifier);
    std::pair<std::string, int> data("Null", Command::Type::UNKNOWN);
    if(it != globalDataPool->end()){
        data.first = it->second.first; //value
        data.second = it->second.second; //type
    }
    return data;
}

std::pair<std::string, int> Resolver::getData(std::string param, const std::map<std::string, std::pair<std::string, int>> * globalDataPool)
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

std::string Resolver::resolve(std::string paramStr,  const std::map<std::string, std::pair<std::string, int>> * globalDataPool)
{
    return calculator.calculate(parseParam(paramStr, globalDataPool));
}

void Resolver::setData(std::vector<std::pair<std::string, int>> & parsedParam, const std::map<std::string, std::pair<std::string, int>> * globalDataPool, std::string strVal)
{
    std::pair<std::string, int> varData;
    varData = getData(strVal, globalDataPool);
    if(varData.first == "Null" || varData.second == Command::Type::UNKNOWN){
        throw std::runtime_error("Error: Null variable in command.");
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
std::vector<std::pair<std::string, int>> Resolver::parseParam(std::string param, const std::map<std::string, std::pair<std::string, int>> * globalDataPool)
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
            setData(parsedParam, globalDataPool, currentStrVal);
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


/** Maybe put this in it's own Searcher class
    could put the find resolve/search variable bit in that class too
*/
int Resolver::findLabel(std::string startLabel, std::string endLabel, int direction, bool jumpPast, std::vector<std::unique_ptr<Command>> & cmds, int * cmdPtr)
{
    int nestedLevel = 0;
    // implement way to force direction to either be -1 or 1
    if(direction > 0 ){
        direction = 1;
    }else{
        direction = -1;
    }
    for(int i = (*cmdPtr) + direction; i < cmds.size(); i += direction){
        if(cmds[i]->getName() == startLabel){
            nestedLevel++;
        }
        if(cmds[i]->getName() == endLabel){
            if(nestedLevel == 0){
                if(direction == -1){
                    return i - 1;
                }
                return i;
            }
            nestedLevel--;
        }
    }
    std::string errMsg = "Error: ";
    errMsg += startLabel;
    errMsg += " statement has no ";
    errMsg += endLabel;
    throw std::runtime_error(errMsg);
}

