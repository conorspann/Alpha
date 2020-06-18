
#ifndef FILE_LOADER_H
#define FILE_LOADER_H

#include <string>
#include <vector>

class FileLoader{
public:
    std::vector<std::string> load(std::string);
private:
    std::ifstream openFile(std::string);
    std::vector<std::string> readData(std::ifstream * input);
};

#endif // LOADER_H
