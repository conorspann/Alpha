
#include <fstream>
#include <stdexcept>

#include "../../include/init/file_loader.h"


std::vector<std::string> FileLoader::load(std::string filename)
{
    std::ifstream input = openFile(filename);

    std::vector<std::string> data = readData(&input);

    input.close();

    return data;
}

std::ifstream FileLoader::openFile(std::string filename)
{
    std::ifstream input(filename, std::ios::in);
    if(!input.is_open()){
        throw std::runtime_error("Error opening file: " + filename);
    }

    return input;
}

std::vector<std::string> FileLoader::readData(std::ifstream * input)
{
    std::vector<std::string> data;
    std::string line;
    while(std::getline(*input, line)){
        data.push_back(line);
    }

    return data;
}
