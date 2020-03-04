
#ifndef FILE_LOADER_H
#define FILE_LOADER_H

#include <string>
#include <vector>

class FileLoader{
public:
    std::vector<std::pair<int, std::string>> load(std::string);
};

#endif // LOADER_H
