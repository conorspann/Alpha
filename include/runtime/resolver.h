
#ifndef RESOLVER_H
#define RESOLVER_H

#include <string>
#include <map>
#include <vector>

#include "calculator.h"

class Resolver{
public:
    Resolver();
    std::string resolve(std::string, std::map<std::string, std::pair<std::string, int>> &);
    std::pair<std::string, int> & resolveVariable(std::string, std::map<std::string, std::pair<std::string, int>> &);
    int determineType(std::string param);
private:
    Calculator calculator;
    void addChar(std::string & currentParam, char paramChar);
    std::pair<std::string, int> resolveParam(std::string, std::map<std::string, std::pair<std::string, int>> &);
    void addParam(std::vector<std::pair<std::string, int>> & parsedParam, std::map<std::string, std::pair<std::string, int>> & globalDataPool, std::string strVal);
    void setSymbol(std::vector<std::pair<std::string, int>> & parsedParam, std::map<std::string, std::pair<std::string, int>> & globalDataPool, char symbolChar);
    std::vector<std::pair<std::string, int>> parseParam(std::string, std::map<std::string, std::pair<std::string, int>> &);
};

#endif // RESOLVER_H
