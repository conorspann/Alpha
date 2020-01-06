
#include "memory_dump.h"

#include <map>
#include <vector>
#include <string>
#include <iostream>

MemoryDump::MemoryDump(std::vector<std::string> params):
    Command(params)
{

}

void MemoryDump::execute(Resolver & resolver, std::map<std::string, std::pair<std::string, int>> * globalDataPool, std::vector<std::unique_ptr<Command>> &, int *)
{
    std::map<std::string, std::pair<std::string, int>>::iterator it;
    //std::map<std::string, std::string> vars = & globalDataPool;
    for(it = globalDataPool->begin(); it != globalDataPool->end(); it++){
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
