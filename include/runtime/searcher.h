
#ifndef SEARCHER_H
#define SEARCHER_H

#include <string>
#include <vector>

class Searcher{
public:
    Searcher(std::vector<std::string>);
    int findLabel(std::string startLabel, std::string endLabel, int, int *);
private:
    std::vector<std::string> labels;
};

#endif // SEARCHER_H
