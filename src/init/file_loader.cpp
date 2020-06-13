
#include <fstream>
#include <stdexcept>

#include "../../include/init/file_loader.h"


std::vector<std::pair<int, std::string>> FileLoader::load(std::string filename)
{
    std::ifstream input = openFile(filename);

    std::vector<std::pair<int, std::string>> data = readData(&input);

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

std::vector<std::pair<int, std::string>> FileLoader::readData(std::ifstream * input)
{
    std::vector<std::pair<int, std::string>> data;
    std::string line;
    int lineNumber = 1;
    while(std::getline(*input, line)){
        std::pair<int, std::string> numberedLine(lineNumber, line);
        data.push_back(numberedLine);
        lineNumber++;
    }

    return data;
}
