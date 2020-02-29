
#ifndef RESOLVER_H
#define RESOLVER_H

#include <string>
#include <map>
#include <vector>

#include "calculator.h"
#include "data_pool.h"

class Resolver{
public:
    Resolver();
    std::string resolve(std::string, DataPool &);
    std::pair<std::string, int> & resolveVariable(std::string, DataPool &);
    int determineType(std::string param);
private:
    Calculator calculator;
    void addChar(std::string & currentParam, char paramChar);
    std::pair<std::string, int> resolveParam(std::string, DataPool &);
    void addParam(std::vector<std::pair<std::string, int>> & parsedParam, DataPool &, std::string strVal);
    void setSymbol(std::vector<std::pair<std::string, int>> & parsedParam, DataPool &, char symbolChar);
    std::vector<std::pair<std::string, int>> parseParam(std::string, DataPool &);
};

#endif // RESOLVER_H
