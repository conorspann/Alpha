
#include "../../include/runtime/data_pool.h"

void DataPool::addVariable(std::string identifier, std::pair<std::string, int> variable)
{
    if(getAddress(identifier) != -1){
        throw std::runtime_error("Error: variable already exists.");
    }
    int newAddr = globalDataPool.size();
    std::pair<int, int> nameTableValues(newAddr, 1);
    nameTable.insert(std::pair<std::string, std::pair<int, int>>(identifier, nameTableValues));
    globalDataPool.push_back(variable);
}

std::pair<std::string, int> & DataPool::findVariable(std::string identifier)
{
    int varAddr = getAddress(identifier);
    if(varAddr == -1){
        throw std::runtime_error("Error: Null variable in command.");
    }

    return globalDataPool[varAddr];
}

void DataPool::editVariable(std::string identifier, std::string value)
{
    int addr = getAddress(identifier);
    if(addr == -1){
        throw std::runtime_error("Error: cannot assign new value to non-existent variable.");
    }
    globalDataPool[addr].first = value;
}

int DataPool::getAddress(std::string identifier)
{
    std::map<std::string, std::pair<int, int>>::iterator it;
    it = nameTable.find(identifier);
    if(it == nameTable.end()){
        return -1;
    }

    return it->second.first;
}

std::map<std::string, std::pair<int, int>> & DataPool::getNameTable()
{
    return nameTable;
}

std::vector<std::pair<std::string, int>> & DataPool::getGlobalDataPool()
{
    return globalDataPool;
}
