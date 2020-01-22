
#ifndef FORMATTER_H
#define FORMATTER_H

#include <string>
#include <vector>

class Formatter{
public:
    Formatter();
    std::vector<std::string> removeWhiteSpace(std::vector<std::string>);
private:
    std::string symbols = "+-*/?%@=<>,()";
    bool isWhiteSpace(char c);
    std::string removeInitialWhiteSpace(std::string line);
    std::string addSymbolWhiteSpace(std::string line);
    std::string removeDuplicateWhiteSpace(std::string line);
    bool isSymbol(char c);
};

#endif // FORMATTER_H
