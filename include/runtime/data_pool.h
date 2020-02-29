
#ifndef DATA_POOL_H
#define DATA_POOL_H

#include <string>
#include <map>
#include <vector>

class DataPool{
public:
    void addVariable(std::string, std::pair<std::string, int>);
    std::pair<std::string, int> & findVariable(std::string);
    void editVariable(std::string identifier, std::string value);
    int getAddress(std::string identifier);
    std::map<std::string, std::pair<int, int>> & getNameTable();
    std::vector<std::pair<std::string, int>> & getGlobalDataPool();
private:
    std::map<std::string, std::pair<int, int>> nameTable; // name -> address/index + size e.g. 1 for normal, 1+ for arrays
    std::vector<std::pair<std::string, int>> globalDataPool;
    //std::map<std::string, std::pair<std::string, int>> globalDataPool; //
};

#endif // DATA_POOL_H
