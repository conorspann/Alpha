
#include <fstream>
#include <stdexcept>

#include "../../include/init/file_loader.h"


std::vector<std::pair<int, std::string>> FileLoader::load(std::string filename)
{
    std::vector<std::pair<int, std::string>> data;
    std::ifstream input(filename, std::ios::in);
    if(!input.is_open()){
        throw std::runtime_error("Error opening file: " + filename);
    }
    std::string line;
    int lineNumber = 1;
    while(std::getline(input, line)){
        std::pair<int, std::string> numberedLine(lineNumber, line);
        data.push_back(numberedLine);
        lineNumber++;
    }
    input.close();

    return data;
}
