
#include <fstream>
#include <stdexcept>

#include "../../include/init/file_loader.h"


std::vector<std::string> FileLoader::load(std::string filename)
{
    std::vector<std::string> data;
    std::ifstream input(filename, std::ios::in);
    if(!input.is_open()){
        throw std::runtime_error("Error opening file: " + filename);
    }
    std::string line;
    while(std::getline(input, line)){
        data.push_back(line);
    }
    input.close();

    return data;
}
