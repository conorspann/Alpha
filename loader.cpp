
#include <fstream>
#include <stdexcept>
#include "loader.h"

Loader::Loader(std::string filename)
{
    std::ifstream input(filename, std::ios::in);
    if(!input.is_open()){
        throw std::runtime_error("Error opening file: " + filename);
    }
    std::string line;
    while(std::getline(input, line)){
        data.push_back(line);
    }
    input.close();
}

std::vector<std::string> Loader::getData()
{
    return data;
}

std::string Loader::getLine(int lineNumber)
{
    std::string line;
    if(lineNumber >= 0 && lineNumber < data.size()){
        line = data[lineNumber];
    }
    return line;
}
