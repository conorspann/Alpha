
#ifndef LOADER_H
#define LOADER_H

#include <string>
#include <vector>

class Loader{
public:
    Loader(std::string);
    std::vector<std::string> getData();
    std::string getLine(int);
private:
    std::vector<std::string> data;
};

#endif // LOADER_H
