

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

void MemoryDump::execute(Environment & environment, std::vector<std::unique_ptr<Command>> &, int *)
{
    std::map<std::string, std::pair<std::string, int>> & globalDataPool = environment.getGlobalDataPool();
    std::map<std::string, std::pair<std::string, int>>::iterator it;
    //std::map<std::string, std::string> vars = & globalDataPool;
    for(it = globalDataPool.begin(); it != globalDataPool.end(); it++){
        std::cout << it->first << " : " << it->second.first;
        switch(it->second.second){
        case Type::STRING:
            std::cout << " : string" << std::endl;
            break;
        case Type::INT:
            std::cout << " : int" << std::endl;
            break;
        default:
            std::cout << " (unknown)" << std::endl;
        }
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
