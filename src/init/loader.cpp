
#include <fstream>
#include <stdexcept>
#include "../../include/init/loader.h"

Loader::Loader()
{

}


std::vector<std::string> Loader::load(std::string filename)
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
