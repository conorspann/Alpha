
#include "../../include/runtime/resolver.h"

#include <utility>


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

std::pair<std::string, int> Resolver::isVariable(std::string param, const std::map<std::string, std::pair<std::string, int>> * globalDataPool)
{
    std::pair<std::string, int> p;
    if(param[0] == '@'){
        std::string identifier = param.substr(1, std::string::npos);
        std::map<std::string, std::pair<std::string, int>>::const_iterator it;
        it = globalDataPool->find(identifier);
        if(it != globalDataPool->end()){
            p.first = it->second.first; //value
            p.second = it->second.second; //type
        }else{
            p.first = "Null";
            p.second = Command::Type::UNKNOWN;
        }
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

/**
    REFACTOR !!
*/
std::vector<std::pair<std::string, int>> Resolver::parseParam(std::string param, const std::map<std::string, std::pair<std::string, int>> * globalDataPool)
{
    std::vector<std::pair<std::string, int>> parsedParam;
    std::string val;
    std::pair<std::string, int> var;
    bool isString = false;
    for(int i = 0; i < param.length(); i++){
        char c = param[i];
        // need to check if params are valid numbers variables or symbols otherwise throw error
        if(c == '\"'){
            isString = !isString;
        }
        if(calculator.isSymbol(c) && !isString){
            var = isVariable(val, globalDataPool);
            if(var.first == "Null" || var.second == Command::Type::UNKNOWN){
                throw std::runtime_error("Error: Null variable in command.");
            }
            parsedParam.push_back(var);
            std::string symbol(std::string(1, c));
            std::pair<std::string, int> symbolPair;
            symbolPair.first = symbol;
            symbolPair.second = Command::Type::SYMBOL;
            parsedParam.push_back(symbolPair);
            val = "";
            continue;
        }else if(i == param.length() - 1){
            if(c != '\"'){
                val += c;
            }
            var = isVariable(val, globalDataPool);
            if(var.first == "Null" || var.second == Command::Type::UNKNOWN){
                throw std::runtime_error("Error: Null variable in command.");
            }
            parsedParam.push_back(var);
            break;
        }
        if(c != '\"'){
            val += c;
        }
    }

    return parsedParam;
}


/** Maybe put this in it's own Searcher class */
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

