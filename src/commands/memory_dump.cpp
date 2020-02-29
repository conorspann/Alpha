

#include <map>
#include <vector>
#include <string>
#include <iostream>

#include "../../include/commands/memory_dump.h"
#include "../../include/runtime/environment.h"

MemoryDump::MemoryDump(std::vector<std::string> params):
    Command(params)
{

}

void MemoryDump::execute(Environment & environment, int *)
{
    DataPool & dataPool = environment.getDataPool();
    std::vector<std::pair<std::string, int>> & globalDataPool = dataPool.getGlobalDataPool();
    std::map<std::string, std::pair<int, int>> & nameTable = dataPool.getNameTable();

    std::map<std::string, std::pair<int, int>>::iterator tableIt;
    for(tableIt = nameTable.begin(); tableIt != nameTable.end(); tableIt++){
        std::string identifier = tableIt->first;
        int varAddr = tableIt->second.first;
        int varSize = tableIt->second.second;
        std::string varValue = globalDataPool[varAddr].first;
        int varType = globalDataPool[varAddr].second;
        std::cout << "[" << std::to_string(varAddr) << "]+" << std::to_string(varSize) << " " << identifier << " " << varValue << " " << varType << std::endl;
    }
}

int MemoryDump::getNumParams()
{
    return 0;
}

std::string MemoryDump::getName()
{
    return "MemoryDump";
}
