
#ifndef RESOLVER_H
#define RESOLVER_H

#include <string>
#include <map>
#include <vector>

#include "calculator.h"

class Resolver{
public:
    Resolver();
    std::string resolve(std::string, const std::map<std::string, std::pair<std::string, int>> &);
private:
    Calculator calculator;
    void addChar(std::string & currentParam, char paramChar);
    std::pair<std::string, int> getData(std::string, const std::map<std::string, std::pair<std::string, int>> &);
    std::pair<std::string, int> resolveParam(std::string, const std::map<std::string, std::pair<std::string, int>> &);
    void setData(std::vector<std::pair<std::string, int>> & parsedParam, const std::map<std::string, std::pair<std::string, int>> & globalDataPool, std::string strVal);
    void setSymbol(std::vector<std::pair<std::string, int>> & parsedParam, const std::map<std::string, std::pair<std::string, int>> & globalDataPool, char symbolChar);
    int determineType(std::string param);
    std::vector<std::pair<std::string, int>> parseParam(std::string, const std::map<std::string, std::pair<std::string, int>> &);
};

#endif // RESOLVER_H
